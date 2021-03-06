#pragma once

// STL includes
#include <string>

// hyperion incluse
#include "TcpSocketDevice.h"

///
/// Implementation of the LedDevice interface for writing to tcp socket device using tpm2 protocol.
///
class LedDeviceTpm2TcpSocket : public TcpSocketDevice
{
public:
    ///
    /// Constructs the LedDevice for attached serial device using supporting tpm2 protocol
    /// All LEDs in the stripe are handled as one frame
    ///
    /// @param outputDevice The name of the output device (eg '/dev/ttyAMA0')
    /// @param baudrate The used baudrate for writing to the output device
    ///
    LedDeviceTpm2TcpSocket(const std::string& address);

    ///
    /// Writes the led color values to the led-device
    ///
    /// @param ledValues The color-value per led
    /// @return Zero on succes else negative
    ///
    virtual int write(const std::vector<ColorRgb> &ledValues);

    /// Switch the leds off
    virtual int switchOff();

private:
    /// The buffer containing the packed RGB values
    std::vector<uint8_t> _ledBuffer;
};
