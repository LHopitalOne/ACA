#include "TVRemote.hpp"

int main()
{
    TVRemote remote;

    remote.togglePower();
    remote.nextChannel();
    remote.nextChannel();
    remote.previousChannel();
    remote.setChannel(5);

    remote.togglePower();

    std::cout << "Current channel: " << remote.getChannel() << std::endl;
    std::cout << "Current volume: " << remote.volume() << std::endl;
    remote.togglePower();

    return 0;
}
