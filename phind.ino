int ledPin = D7;
int buttonPin = D0;
int power = A0;

boolean holding = false;
int buttonState;

void setup() {
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);

  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !holding)  {
    holding = true;
    digitalWrite(ledPin, HIGH);
    Serial.println("Button pressed");

  } else if (buttonState == HIGH && holding) {
    holding = false;
    digitalWrite(ledPin, LOW);

    bool success = Particle.publish("phind");
    Serial.println("Event published");

    if (success) {
      Serial.println("Rainbows");

      RGB.control(true);
      for (int i=0; i < 50; i++) {
        int randR = random(256);
        int randG = random(256);
        int randB = random(256);
        RGB.color(randR, randG, randB);
        delay(50);
      }

      delay(750);
      RGB.control(false);
    }

  }

}
