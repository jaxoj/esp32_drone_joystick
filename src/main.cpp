#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "NRF.h"

// NRF setup
const byte nrfAddress[6] = "DRONE";
NRFTransmitter nrf(9, 10, nrfAddress);


// Timing
unsigned long lastSendTime = 0;
const int sendInterval = 10; // 10ms → 100Hz

void setup()
{
  Serial.begin(115200);

  // Initialize NRF
  nrf.begin();

  // Optional: center values check
  Serial.println("Transmitter Ready");
}

void loop()
{
  // Run at ~100Hz
  if (millis() - lastSendTime < sendInterval)
    return;
  lastSendTime = millis();

  nrf.readJoysticks(A0, A1, A2, A3);
  nrf.send();

  // --- 5. Debug (optional) ---
  Serial.print("T:");
  Serial.print(nrf.data.throttle);
  Serial.print(" R:");
  Serial.print(nrf.data.rollTarget);
  Serial.print(" P:");
  Serial.print(nrf.data.pitchTarget);
  Serial.print(" Y:");
  Serial.println(nrf.data.yawTarget);
}