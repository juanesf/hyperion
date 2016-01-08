
// STL includes
#include <cstring>
#include <cstdio>
#include <iostream>

// hyperion local includes
#include "LedDeviceTpm2UdpSocket.h"

LedDeviceTpm2UdpSocket::LedDeviceTpm2UdpSocket(const std::string& address) :
        UdpSocketDevice(address),
        _ledBuffer(0)
{
    // empty
}

int LedDeviceTpm2UdpSocket::write(const std::vector<ColorRgb> &ledValues)
{
    if (_ledBuffer.size() == 0)
    {
        _ledBuffer.resize(5 + 3*ledValues.size());
        _ledBuffer[0] = 0xC9; // block-start byte
        _ledBuffer[1] = 0xDA; // DATA frame
        _ledBuffer[2] = ((3 * ledValues.size()) >> 8) & 0xFF; // frame size high byte
        _ledBuffer[3] = (3 * ledValues.size()) & 0xFF; // frame size low byte
        _ledBuffer.back() = 0x36; // block-end byte
    }

    // write data
    memcpy(4 + _ledBuffer.data(), ledValues.data(), ledValues.size() * 3);
    return writeBytes(_ledBuffer.size(), _ledBuffer.data());
}

int LedDeviceTpm2UdpSocket::switchOff()
{
    memset(4 + _ledBuffer.data(), 0, _ledBuffer.size() - 5);
    return writeBytes(_ledBuffer.size(), _ledBuffer.data());
}
