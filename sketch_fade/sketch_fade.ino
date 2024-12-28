int ledPin = 9;  // PWM-fähiger Pin
int minBrightness = 6;
int slowBrightness = 50;
int brightness = minBrightness;
int maxBrightness = 254;
int fadeAmount = 4;  // Änderung pro Schritt
int fadeDirection = 1;

void setup() {
  // Serial.begin(38400);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);
  // Serial.println(brightness);
  brightness += fadeAmount * fadeDirection;

  if (brightness == minBrightness || brightness == maxBrightness) {
    fadeDirection = 0 - fadeDirection;  // Richtung umkehren
  }

  if(brightness <= slowBrightness) {
    // fadeAmount = 2;
  } else {
    // fadeAmount = 4;
  }

  if (brightness == minBrightness || brightness == maxBrightness) {
    // kurze Aus-Phase
    // analogWrite(ledPin, minBrightness);
    delay(500);
  }

  delay(20);  // Geschwindigkeit der Änderung
}