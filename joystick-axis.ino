int value = 0;

void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(7, INPUT);
    Serial.begin(9600);
}

void loop() {
    int x = analogRead(0) - 511; // read X axis value [0..1023]
    Serial.print("X:");
    Serial.print(x, DEC);

    int y = analogRead(1) - 518; // read Y axis value [0..1023]
    Serial.print(" | Y:");
    Serial.print(y, DEC);

    value = digitalRead(7); // read Button state [0,1]
    Serial.print(" | Button:");
    Serial.println(value, DEC);
    if (x <= 5 && y <= -100) {
        Serial.println("down");
        digitalWrite(5, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
    } else if (x <= -100 && y <= 505) {
        Serial.println("left");
        digitalWrite(5, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if (x >= 11 && y <= 11) {
        Serial.println("right");
        digitalWrite(4, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
    } else if (x <= 512 && y >= 12) {
        Serial.println("up");
        digitalWrite(2, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
    } else {
        Serial.println("center");
        digitalWrite(5, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    delay(100);
}
