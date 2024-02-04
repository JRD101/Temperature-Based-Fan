#include <DHT.h>

// Pin configuration for DHT22 sensor
const int dhtPin = 2;

// Pin configuration for Motor 1
const int ENA = 19;
const int IN1 = 18;
const int IN2 = 5;
// temperature 
const double low = 29.0;
const double medium = 31.9;

// Pin configuration for Motor 2
const int ENB = 4;
const int IN3 = 17;
const int IN4 = 16;

// Create a DHT instance
DHT dht(dhtPin, DHT22);

// Initialize fan speed
int fanSpeed;

void setup() {
  dht.begin(); // Initialize DHT sensor

  // Start serial communication
  Serial.begin(115200);

  // Motor control pins as outputs for Motor 1
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Motor control pins as outputs for Motor 2
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Read temperature from the sensor
  float temperature = dht.readTemperature();

  // Check if the temperature reading is valid
  if (!isnan(temperature)) {
    // Display temperature on the Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Fan Speed: ");
    Serial.println(fanSpeed);

    // Adjust motor speed based on temperature
    if (temperature <= 29.0) {
      setMotorSpeed(85);  // Low speed
    } else if (temperature <= 31.9) {
      setMotorSpeed(170);  // Medium speed
    } else {
      setMotorSpeed(255);  // High speed
    }

    // Run both motors forward at the adjusted speed
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, fanSpeed);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, fanSpeed);
  } else {
    // Print an error message if the temperature reading is invalid
    Serial.println("Error reading temperature!");
     digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, fanSpeed);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, fanSpeed);
  }

  // Delay for a short interval
  delay(100);
}

// Function to set motor speed using PWM
void setMotorSpeed(int speed) {
  fanSpeed = speed;
}
