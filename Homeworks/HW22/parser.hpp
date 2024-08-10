#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <utility>
#include <type_traits>
#include <stdexcept>

namespace parse
{
    namespace _AnyWrapper
    {
        enum class __BasicT
        {
            __INTEGER = 0x1,
            __FLOAT   = 0x2,
            __STRING  = 0x3,
            __NULL    = 0x0
        };

        class __any_type
        {
        private:
            __BasicT _Type;

            union __StorageT
            {
                int _i;
                float _f;
                std::string _s;

                __StorageT()
                {
                    _i = 0;
                    _f = 0;
                    _s = "";
                }

                __StorageT(__StorageT&& _other)
                {
                    _i = std::exchange(_other._i, 0);
                    _f = std::exchange(_other._f, 0);
                    _s = std::exchange(_other._s, "");
                }

                __StorageT(const __StorageT& _other)
                {
                    _i = _other._i;
                    _f = _other._f;
                    _s = _other._s;
                }

                ~__StorageT()
                {
                    _s.~basic_string();
                }
            } _Storage;
            
        public:
            __any_type();
            
            __any_type(const __any_type& _other);
            
            __any_type(__any_type&& _other);
            
            template<typename _ValueT>
            __any_type(const _ValueT& _value);
            
            ~__any_type();

            __any_type& operator=(const __any_type& _rhs);
            __any_type& operator=(__any_type&& _rhs);
            
            template<typename _ValueT>
            void set(_ValueT _value);

            template<typename _ValueT>
            _ValueT get() const;
            
            const __BasicT type() const;
        };

        __any_type::__any_type() : _Type(__BasicT::__NULL) {}
        __any_type::__any_type(const __any_type& _other) : _Type(_other._Type), _Storage(_other._Storage) {}
        __any_type::__any_type(__any_type&& _other) : _Type(std::exchange(_other._Type, __BasicT::__NULL)), _Storage(std::move(_other._Storage)) {}

        template<typename _ValueT>
        __any_type::__any_type(const _ValueT& _value)
        {
            if (std::is_same_v<_ValueT, int>)
            {
                _Type = __BasicT::__INTEGER;
                _Storage._i = _value;
            }
            else if (std::is_same_v<_ValueT, float>)
            {
                _Type = __BasicT::__FLOAT;
                _Storage._f = _value;
            }
            else if (std::is_same_v<_ValueT, std::string>)
            {
                _Type = __BasicT::__STRING;
                new(&_Storage._s) std::string(_value);
            }
            else
            {
                throw std::invalid_argument{"Error: the argument _value must be type of int, float or std::string"};
            }
        }

        __any_type::~__any_type()
        {
            if (_Type == __BasicT::__STRING)
                _Storage.~__StorageT();
            _Type = __BasicT::__NULL;
        }

        __any_type& __any_type::operator=(const __any_type& _rhs)
        {
            if (this != &_rhs)
            {
                this->~__any_type();
                _Type = _rhs._Type;

                switch (_Type)
                {
                    case __BasicT::__INTEGER:
                        _Storage._i = _rhs._Storage._i;
                        break;
                    case __BasicT::__FLOAT:
                        _Storage._f = _rhs._Storage._f;
                        break;
                    case __BasicT::__STRING:
                        new(&_Storage._s) std::string(_rhs._Storage._s);
                        break;
                    case __BasicT::__NULL:
                        break;
                }
            }
            
            return *this;
        }

        __any_type& __any_type::operator=(__any_type&& _rhs)
        {
            if (this != &_rhs)
            {
                this->~__any_type();
                _Type = _rhs._Type;

                switch (_Type)
                {
                    case __BasicT::__INTEGER:
                        _Storage._i = _rhs._Storage._i;
                        break;
                    case __BasicT::__FLOAT:
                        _Storage._f = _rhs._Storage._f;
                        break;
                    case __BasicT::__STRING:
                        new(&_Storage._s) std::string(std::move(_rhs._Storage._s)); // Placement new
                        break;
                    case __BasicT::__NULL:
                        break;
                }
                _rhs.~__any_type();
            }

            return *this;
        }

        template<typename _ValueT>
        void __any_type::set(_ValueT _value)
        {
            if constexpr (std::is_same_v<_ValueT, int>)
            {
                _Type = __BasicT::__INTEGER;
                _Storage._i = _value;
            }
            else if constexpr (std::is_same_v<_ValueT, float>)
            {
                _Type = __BasicT::__FLOAT;
                _Storage._f = _value;
            }
            else if constexpr (std::is_same_v<_ValueT, std::string>)
            {
                _Type = __BasicT::__STRING;
                _Storage._s = _value;
            }
            else
            {
                throw std::invalid_argument{"The requested type should be int, float or std::string"};
            }
        }

        template<typename _ValueT>
        _ValueT __any_type::get() const
        {
            if constexpr (std::is_same_v<_ValueT, int>)
            {
                if (_Type != __BasicT::__INTEGER)
                    throw std::bad_cast();
                return _Storage._i;
            }
            else if constexpr (std::is_same_v<_ValueT, float>)
            {
                if (_Type != __BasicT::__FLOAT)
                    throw std::bad_cast();
                return _Storage._f;
            }
            else if constexpr (std::is_same_v<_ValueT, std::string>)
            {
                if (_Type != __BasicT::__STRING)
                    throw std::bad_cast();
                return _Storage._s;
            }
            else
            {
                throw std::invalid_argument{"The requested type should be int, float or std::string"};
            }
        }

        const __BasicT __any_type::type() const
        {
            return _Type;
        }
    }
    
    using namespace _AnyWrapper;
    
    using any = __any_type;

    class parser
    {
    private:
        parser() {}
        ~parser()
        {
            instance->_Incoming.~__any_type();
        }

        static parser* instance;
        __any_type _Incoming;

    public:
        parser(const parser&) = delete;
        parser& operator=(const parser&) = delete;

        static parser& init()
        {
            if (!instance)
                instance = new parser();
            return *instance;
        }

        any render(std::string _input)
        {
            try
            {
                float fRender = std::stof(_input);
                int iRender = std::stoi(_input);

                if (fRender == iRender)
                    instance->_Incoming.set<int>(iRender);
                else
                    instance->_Incoming.set<float>(fRender);
            }
            catch(const std::invalid_argument& e)
            {
                instance->_Incoming.set<std::string>(_input);
            }
            
            return instance->_Incoming;
        }
    };

    parser* parser::instance = nullptr;
}

#endif // PARSER_HPP
