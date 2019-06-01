#include <stdio.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  Serial.begin(115200);
}

void loop() {
  String num1 = String(digitalRead(D1));
  String num2 = String(digitalRead(D2));
  String num3 = String(digitalRead(D5));
  String num4 = String(digitalRead(D6));

  if(num1 || num2 || num3 || num4){
    Serial.println("sdsda");  
  }
  
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
