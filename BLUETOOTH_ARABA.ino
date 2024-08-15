#include <SoftwareSerial.h>

SoftwareSerial bluetooth(9, 8);  // RX, TX

const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    switch (command) {
      case 'F':  // Forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

        break;
      case 'B':  // Backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        break;
      case 'L':  // Left
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

        break;
      case 'R':  // Right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        break;
      case 'S':  // Stop
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
    }
  }
}