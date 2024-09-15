#include <Servo.h>

Servo myServo;  // Create a Servo object to control the servo motor
int angle;  // Variable to store the angle

void setup() {
  myServo.attach(9);  // Attach the servo to pin 9
  Serial.begin(0);  // Start serial communication at 9600 baud
  Serial.println("Enter an angle between 0 and 180 or type 'speak':");
}

void speak(int n) {
  for (int i = 0; i < n; i++) {
    myServo.write(72);  // Move the servo to 72 degrees
    delay(300);  // Short delay to allow the servo to move
    myServo.write(0);  // Move the servo back to 0 degrees
    delay(300);  // Short delay to allow the servo to move back
  }
}


void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read the input string
    input.trim();  // Remove any extra spaces or newline characters

    if (input.equalsIgnoreCase("speak")) {  // Check if the input is "speak"
      speak(5);  // Call the speak function to move the servo
      Serial.println("Servo moved to 72 and back to 0.");
    } else {
      int inputAngle = input.toInt();  // Convert the input string to an integer
      if (inputAngle >= 0 && inputAngle <= 180) {  // Check if the input is within the valid range
        angle = inputAngle;  // Set the angle
        myServo.write(angle);  // Move the servo to the specified angle
        Serial.print("Servo moved to angle: ");
        Serial.println(angle);
        delay(5);
      } else {
        Serial.println("Invalid command or angle! Please enter a value between 0 and 180 or type 'speak'.");
      }
    }
  }
}
