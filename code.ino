
#include <Servo.h>  // Include the Servo library

// Define the pins
int rainSensorPin = 2;  // Rain sensor connected to pin 2
int servoPin = 9;       // Servo motor connected to pin 9

// Create a Servo object
Servo wiperServo;

void setup() {
  // Initialize the rain sensor pin as input
  pinMode(rainSensorPin, INPUT);
  
  // Initialize the servo
  wiperServo.attach(servoPin);
  
  // Set initial position of the wiper servo to 0 degrees
  wiperServo.write(0);

  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  int rainSensorValue = digitalRead(rainSensorPin);  // Read the value from the rain sensor

  // If rain is detected (sensor goes LOW)
  if (rainSensorValue == LOW) {
    Serial.println("Rain detected!");
    
    // Simulate the wiper motion by making the servo quickly sweep between 0 and 90 degrees
    for (int angle = 0; angle <= 90; angle++) {
      wiperServo.write(angle);
      delay(10);  // Delay for smooth movement (adjust delay for faster/slower movement)
    }
    
    for (int angle = 90; angle >= 0; angle--) {
      wiperServo.write(angle);
      delay(10);  // Delay for smooth movement (adjust delay for faster/slower movement)
    }
  } 
  else {
    Serial.println("No rain detected.");
    
    // If no rain, move the servo motor back to 0 degrees (rest position)
    wiperServo.write(0);
  }

  delay(500);  // Short delay to avoid reading too frequently
}
