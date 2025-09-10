// RF Transmitter for Speed Control Zones
#include <VirtualWire.h>

const int transmit_pin = 12;
const int speedLimitZone = 30;  // Example: Zone A → 30 km/h

void setup() {
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);  // Bits per second
}

void loop() {
  char msg[3];
  sprintf(msg, "%d", speedLimitZone);
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
  delay(1000);
}

