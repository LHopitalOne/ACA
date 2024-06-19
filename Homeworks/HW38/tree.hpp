#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <queue>
#include <vector>

template<typename _ValueT>
class bstree
{
public:
    class Node;

    constexpr bstree(_ValueT rootValue) : _root(new Node(rootValue)) {}
    bstree(const bstree&) = delete;

    inline Node* root() const
    {
        return _root;
    }

    ~bstree()
    {
        delete _root;
    }

public:
    class Node
    {
    private:
        _ValueT mValue;
        
        Node* node_left;
        Node* node_right;
    public:
        constexpr Node(_ValueT value) : mValue(value), node_left(nullptr), node_right(nullptr) {}

        void set(Node* __left, Node* __right)
        {
            node_left = __left;
            node_right = __right;
        }

        inline _ValueT value() const
        {
            return mValue;
        }

        inline Node* left()
        {
            return node_left;
        }

        inline Node* right()
        {
            return node_right;
        }

        ~Node()
        {
            delete node_left;
            delete node_right;
        }
    };
private:  
    Node* _root;
};

template<typename _ValueT>
std::vector<_ValueT> inorder(typename bstree<_ValueT>::Node* root)
{
    static std::vector<_ValueT> inorder_path;

    if (root == nullptr) return {};

    inorder<_ValueT>(root->left());
    inorder_path.push_back(root->value());
    inorder<_ValueT>(root->right());

    return inorder_path;
}

template<typename _ValueT>
std::vector<_ValueT> preorder(typename bstree<_ValueT>::Node* root)
{
    static std::vector<_ValueT> preorder_path;

    if (root == nullptr) return {};

    preorder_path.push_back(root->value());
    preorder<_ValueT>(root->left());
    preorder<_ValueT>(root->right());

    return preorder_path;
}

template<typename _ValueT>
std::vector<_ValueT> postorder(typename bstree<_ValueT>::Node* root)
{
    static std::vector<_ValueT> preorder_path;

    if (root == nullptr) return {};

    postorder<_ValueT>(root->left());
    postorder<_ValueT>(root->right());
    preorder_path.push_back(root->value());

    return preorder_path;
}

template<typename _ValueT>
std::vector<_ValueT> bfs(typename bstree<_ValueT>::Node* root)
{
    std::vector<_ValueT> bfs_path;

    std::queue<typename bstree<_ValueT>::Node*> q;
    q.push(root);

    while (!q.empty())
    {
        typename bstree<_ValueT>::Node* n = q.front();
        bfs_path.push_back(n->value());
        q.pop();

        if (n->left())
            q.push(n->left());
        if (n->right())
            q.push(n->right());
    }
    
    return bfs_path;
}

#endif // BSTREE_HPP
