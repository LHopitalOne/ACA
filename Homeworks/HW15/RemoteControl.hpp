class RemoteControl {
public:
    virtual void togglePower() = 0;
    virtual int volume() = 0;
    virtual void nextChannel() = 0;
    virtual void previousChannel() = 0;
    virtual void setChannel(int channel) = 0;
    virtual ~RemoteControl() {}
};
