const int gasSensorPin = A0; // MQ2 analog output pin
const int ledPin = D0;       // LED pin
const int buzzerPin = D2;    // Buzzer pin
const int threshold = 500;   // Gas concentration threshold

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int gasLevel = analogRead(gasSensorPin);
  Serial.println(gasLevel);

  if (gasLevel > threshold) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    digitalWrite(buzzerPin, HIGH); // Turn on Buzzer
    delay(2000); // Wait for 500 milliseconds
    digitalWrite(ledPin, LOW); // Turn off LED
    digitalWrite(buzzerPin, LOW); // Turn off Buzzer
    delay(1000); // Wait for 500 milliseconds
  } else {
    digitalWrite(ledPin, LOW); // Ensure LED is off
    digitalWrite(buzzerPin, LOW); // Ensure Buzzer is off
  }
}
