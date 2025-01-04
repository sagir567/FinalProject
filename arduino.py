import serial
import time

# Configure the serial connection
arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=1)  # Adjust the port as needed
time.sleep(2)  # Wait for Arduino to initialize

def set_servo_angle(angle):
    if 0 <= angle <= 180:
        command = f"{angle}\n"  # Send angle as a string
        arduino.write(command.encode())
        print(f"Moved servo to {angle}°")
    else:
        print("Angle out of range (0-180°)")

try:
    # Example: Move servo to 90 degrees
    set_servo_angle(90)
    time.sleep(2)
    set_servo_angle(45)
    time.sleep(2)
    set_servo_angle(135)
except KeyboardInterrupt:
    print("Exiting...")
finally:
    arduino.close()
