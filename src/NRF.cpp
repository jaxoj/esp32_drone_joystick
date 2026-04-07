#include "NRF.h"

NRFTransmitter::NRFTransmitter(uint8_t cePin, uint8_t csnPin, const byte address[6])
    : radio(cePin, csnPin)
{
    memcpy(pipeAddress, address, 6);
}

void NRFTransmitter::begin()
{
    radio.begin();
    radio.openWritingPipe(pipeAddress);
    radio.setPALevel(RF24_PA_MAX);
    radio.stopListening(); // Transmitter mode
}

// Reads joystick values (0-1023) and maps them to control signals
void NRFTransmitter::readJoysticks(int pin1, int pin2, int pin3, int pin4)
{
    data.yawTarget = map(analogRead(pin1), 0, 1023, -30, 30);
    data.throttle = map(analogRead(pin2), 0, 1023, 1000, 2000);
    data.rollTarget = map(analogRead(pin3), 0, 1023, -25, 25);
    data.pitchTarget = map(analogRead(pin4), 0, 1023, -25, 25);
}

// Sends the packet
void NRFTransmitter::send()
{
    radio.write(&data, sizeof(RadioPacket));
}