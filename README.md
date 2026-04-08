# ESP32 NRF24L01 Drone Transmitter 🎮

The custom radio controller unit for the ESP32 Drone project. This firmware reads analog joystick inputs, formats the data into a structured payload, and transmits it via an NRF24L01 module.

## Hardware Components
* **Microcontroller:** ESP32 (or compatible Arduino)
* **Radio:** NRF24L01 (2.4GHz Transceiver) + Adapter Board (recommended for stable 3.3V)
* **Inputs:** 2x Dual-Axis Analog Joysticks
* **Power:** 3.7V LiPo or 5V USB Power Bank

## Radio Protocol & Data Structure
The transmitter sends a fixed-size data struct at a high refresh rate. The payload structure matches the receiver on the drone:

```cpp
struct RadioData {
    int16_t throttle;    // Ranges from 1000 (Idle) to 2000 (Max)
    float rollTarget;    // Target angle (-max to +max degrees)
    float pitchTarget;   // Target angle (-max to +max degrees)
    float yawTarget;     // Target rotation rate (deg/sec)
};