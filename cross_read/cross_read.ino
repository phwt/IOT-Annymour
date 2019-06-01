#include <stdio.h>
int steps = 0;
void setup() {
    // put your setup code here, to run once:
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D5, INPUT);
    pinMode(D6, INPUT);
    Serial.begin(115200);
}

void loop() {
    //   String num1 = String(digitalRead(D1));
    //   String num2 = String(digitalRead(D2));
    //   String num3 = String(digitalRead(D5));
    //   String num4 = String(digitalRead(D6));

    int num1 = digitalRead(D1);
    int num2 = digitalRead(D2);
    int num3 = digitalRead(D5);
    int num4 = digitalRead(D6);

    if (num1 || num2 || num3 || num4) {
        Serial.println(steps);
        steps++;
        while ((num1 || num2 || num3 || num4)) {
            //      Serial.println("haha");
            num1 = digitalRead(D1);
            num2 = digitalRead(D2);
            num3 = digitalRead(D5);
            num4 = digitalRead(D6);
            delay(10);
        }
    }
//    Serial.println("not");

    //  String ans = num1+num2+num3+num4;
    //  Serial.print(digitalRead(D1));
    //  Serial.print(" ");
    //  Serial.print(digitalRead(D2));
    //  Serial.print(" ");
    //  Serial.print(digitalRead(D5));
    //  Serial.print(" ");
    //  Serial.println(digitalRead(D6));
    //  Serial.println(ans);
    delay(100);
}
