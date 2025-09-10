// Vehicle Side Code (Receiver + Motor Driver)
#include <VirtualWire.h>

const int receive_pin = 11;
const int motorPin1 = 5;
const int motorPin2 = 6;
const int enablePin = 9;

int currentSpeed = 200;  // PWM value (0–255)

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  vw_set_rx_pin(receive_pin);
  vw_setup(2000);   // Bits per second
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    int zoneLimit = atoi((char*)buf);   // Convert message to integer
    regulateSpeed(zoneLimit);
  }

  driveMotor();
}

void regulateSpeed(int limit) {
  int desiredSpeed = map(limit, 20, 60, 120, 200); // Convert km/h → PWM
  if (currentSpeed > desiredSpeed) {
    currentSpeed -= 5;   // Gradually slow down
  }
}

void driveMotor() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, currentSpeed);
}
