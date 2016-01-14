int led = D7;

void setup() {
    pinMode(led, OUTPUT);

    bool success = Particle.publish("phind");
    if (success) {
        // ON
        digitalWrite(led, HIGH);
        RGB.control(true);
        RGB.color(255, 100, 100);

        // OFF
        delay(1000);
        digitalWrite(led, LOW);
        RGB.control(false);
    }
}

void loop() {

}
