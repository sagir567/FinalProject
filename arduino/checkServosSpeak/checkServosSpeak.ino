#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create a PCA9685 object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_MIN 150  // Minimum pulse length count
#define SERVO_MAX 600  // Maximum pulse length count
#define SPEAK_SERVO_PIN 15  // PCA9685 output pin for the "speak" servo

int angle;  // Variable to store the angle

// Function to map the angle to a PCA9685 pulse length
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

void setup() {
  Serial.begin(9600);  // Start serial communication
  pwm.begin();  // Initialize the PCA9685
  pwm.setPWMFreq(50);  // Set frequency to 50 Hz (standard for servos)

  Serial.println("Enter an angle between 0 and 180 or type 'speak':");
}

// Function to move the "speak" servo
void speak(int n) {
  for (int i = 0; i < n; i++) {
    pwm.setPWM(SPEAK_SERVO_PIN, 0, angleToPulse(72));  // Move to 72 degrees
    delay(300);  // Delay for servo movement
    pwm.setPWM(SPEAK_SERVO_PIN, 0, angleToPulse(0));  // Move back to 0 degrees
    delay(300);  // Delay for servo movement
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read input from serial
    input.trim();  // Remove any whitespace or newline characters

    if (input.equalsIgnoreCase("speak")) {  // Check if the input is "speak"
      speak(5);  // Call the speak function
      Serial.println("Servo moved to 72 and back to 0.");
    } else {
      int inputAngle = input.toInt();  // Convert input to an integer
      if (inputAngle >= 0 && inputAngle <= 180) {  // Check angle validity
        angle = inputAngle;  // Set the angle
        pwm.setPWM(SPEAK_SERVO_PIN, 0, angleToPulse(angle));  // Move the servo
        Serial.print("Servo moved to angle: ");
        Serial.println(angle);
      } else {
        Serial.println("Invalid command or angle! Please enter a value between 0 and 180 or type 'speak'.");
      }
    }
  }
}
