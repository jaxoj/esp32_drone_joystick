#ifndef NRF_H
#define NRF_H

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

struct __attribute((packed)) RadioPacket {
    int16_t throttle;
    float rollTarget;
    float pitchTarget;
    float yawTarget;
};

class NRFTransmitter {
public:
    NRFTransmitter(uint8_t cePin, uint8_t csnPin, const byte address[6]);

    void begin();
    void readJoysticks(int leftJoyY, int rightJoyX, int rightJoyY, int leftJoyX);
    void send();

    RadioPacket data;

private:
    RF24 radio;
    byte pipeAddress[6];
};

#endif