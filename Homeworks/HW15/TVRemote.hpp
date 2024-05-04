#include <iostream>
#include "RemoteControl.hpp"


class TVRemote : public RemoteControl {
private:
    bool isOn;
    int currentVolume;
    int currentChannel;

public:
    TVRemote() : isOn(false), currentVolume(10), currentChannel(1) {}
    
    void togglePower() override {
        isOn = !isOn;
        std::cout << (isOn ? "TV is now ON" : "TV is now OFF") << std::endl;
    }

    int volume() override {
        return currentVolume;
    }

    void nextChannel() override {
        if (isOn)
            currentChannel++;
    }

    void previousChannel() override {
        if (isOn && currentChannel > 1)
            currentChannel--;
    }

    void setChannel(int channel) override {
        if (isOn)
            currentChannel = channel;
    }

    int getChannel()
    {
        if (isOn)
            return currentChannel;
        return -1;
    }
};
