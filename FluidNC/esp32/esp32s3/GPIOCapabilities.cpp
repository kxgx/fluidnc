#include "Pins/GPIOPinDetail.h"

namespace Pins {
    PinCapabilities GPIOPinDetail::GetDefaultCapabilities(pinnum_t index) {
        // Modified to include GPIO33 and GPIO34 based on hardware testing
        // These pins work as outputs despite being marked as input-only in some docs
        if ((index <= 21) || (index == 33) || (index == 34) || (index >= 35 && index <= 48)) {
            return PinCapabilities::Native | PinCapabilities::Input | PinCapabilities::Output | PinCapabilities::PullUp |
                   PinCapabilities::PullDown | PinCapabilities::PWM | PinCapabilities::ISR | PinCapabilities::UART |
                   (index <= 20 ? PinCapabilities::ADC : PinCapabilities::None);
        } else {
            // Not mapped to actual GPIO pins
            return PinCapabilities::None;
        }
    }
}
