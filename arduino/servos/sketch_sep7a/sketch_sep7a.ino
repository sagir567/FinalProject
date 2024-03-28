#include <Servo.h>

Servo xEyes;

int const potPin = A0;
int potVal;
int angle;
void setup() {
  xEyes.attach(9);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  xEyes.write(angle);
  delay(15);

}
