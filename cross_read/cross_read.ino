#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "Room334"
#define WIFI_PASSWORD "334334334"

#define FIREBASE_HOST "iot-annymour.firebaseio.com"
#define FIREBASE_AUTH "dNYPqKA4fZTlAmxWBhaIdgXOQd8hkktQRO1Lo4Oq"

int steps[4] = {0, 0, 0, 0};
int sets = 0;
String real = "";

void setup()
{
	pinMode(D1, INPUT);
	pinMode(D2, INPUT);
	pinMode(D5, INPUT);
	pinMode(D6, INPUT);
	Serial.begin(115200);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
	Serial.print("Connecting");
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print(".");
		delay(500);
	}
	Serial.println();
	Serial.print("Connected: ");
	Serial.println(WiFi.localIP());
	Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

	Firebase.setString("result", "WAIT");
}

void loop()
{
	while(real.length() != 4){
		Serial.println(real);
		Serial.println(real.length());
		real = Firebase.getString("game/answer");
	}
	Serial.print("Real answer is: ");
	Serial.println(real);
	String cmd = getPushed();
	if(cmd != "0000" && cmd != "1111"){
		Serial.println("CMD GET !!");
		String before_reset = cmd;
		cmd = getPushed();
		while(!(cmd == "0000" || cmd == "1111")){
			String before_reset = cmd;
			cmd = getPushed();
		}
		Serial.println("CMD CONFIRM !!");
		steps[sets] = binaryToColor(before_reset);
		Serial.print("Now, My answer is ");		
		Serial.print(steps[0]);
		Serial.print(steps[1]);
		Serial.print(steps[2]);
		Serial.println(steps[3]);
		sets++;
	}
	if(sets == 4){
		// pushed all answer
		String myans = String(steps[0])+String(steps[1])+String(steps[2])+String(steps[3]);
		Serial.print(myans);
		Serial.print(" VS ");
		Serial.println(real);
		if(myans == real){
			Firebase.setString("result", "WIN");
		}else{
			Firebase.setString("result", "LOSE");
		}
		delay(30000);
	}
}

String getPushed() {
	// Return as binary (String)
	int num1 = digitalRead(D1);
	int num2 = digitalRead(D2);
	int num3 = digitalRead(D5);
	int num4 = digitalRead(D6);
	delay(1000);
	Serial.println(String(num1)+String(num2)+String(num3)+String(num4));
	return String(num1)+String(num2)+String(num3)+String(num4);
}

int binaryToColor(String str) {
	// Return as index of color (int)
	// blue 1000, red 0110, green 0010, yellow 0111?
	if(str == "1000"){
		return 0;
	}else if(str == "0110"){
		return 1;
	}else if(str = "0010"){
		return 2;
	}else if(str == "0111"){
		return 3;
	}
}