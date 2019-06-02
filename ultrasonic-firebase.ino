/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sensors).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    --------------------
 * | HC-SC04 | Arduino |    | 3 pins | Arduino |
 * ---------------------    --------------------
 * |   Vcc   |   5V    |    |   Vcc  |   5V    |
 * |   Trig  |   12    | OR |   SIG  |   13    |
 * |   Echo  |   13    |    |   Gnd  |   GND   |
 * |   Gnd   |   GND   |    --------------------
 * ---------------------
 * Note: You do not obligatorily need to use the pins defined above
 * 
 * By default, the distance returned by the read()
 * method is in centimeters. To get the distance in inches,
 * pass INC as a parameter.
 * Example: ultrasonic.read(INC)
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 03 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 11 Jun 2018
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 *
 * This example code is released into the MIT License.
 */

#include <Ultrasonic.h>
#include <FirebaseArduino.h> //Library สำหรับเชื่อมต่อ Firebase
#include <ESP8266WiFi.h> //Library สำหรับการใช้งาน ESP8266 กับ WiFi

#define WIFI_SSID "Room334" //SSID ของ WiFi ห้อง 334
#define WIFI_PASSWORD "334334334" //รหัสผ่าน WiFi ห้อง 334

#define FIREBASE_HOST "iot-annymour.firebaseio.com" //URL ของ Firebase จากใน Realtime Database
#define FIREBASE_AUTH "dNYPqKA4fZTlAmxWBhaIdgXOQd8hkktQRO1Lo4Oq" //Database Secret Key (หาได้จาก - เฟือง > Project Settings > Service accounts > Database Secrets)

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(D0, D1);
int distance;

void setup() {
  Serial.begin(9600);
    Serial.begin(115200); //เริ่ม Serial Monitor ที่ 115200 baud
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //เริ่มเชื่อมต่อ WiFi ด้วยค่าที่กำหนดไว้ที่บรรทัดที่ 4 และ 5
    Serial.print("Connecting"); //บอกสถานะว่ากำลังเชื่อมต่ออยู่

    while(WiFi.status() != WL_CONNECTED){ //ทำการวนรอบจนกว่า WiFi จะเชื่อมต่อได้
        Serial.print(".");
        delay(500);
    }
    //เมื่อเชื่อมต่อได้แล้วแสดงที่อยู่ IP ที่เชื่อมต่อ
    Serial.println();
    Serial.print("Connected: ");
    Serial.println(WiFi.localIP());
  pinMode(D5,OUTPUT);
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
 
    //Firebase.setInt("distance",distance);

    if(distance <= 25){
      Firebase.setBool("sit",true);
       digitalWrite(D5,HIGH);
      }else{
         Firebase.setBool("sit",false);
          digitalWrite(D5,LOW);
        }
//    boolean light = Firebase.getBool("on");
    delay (250);
 
}
