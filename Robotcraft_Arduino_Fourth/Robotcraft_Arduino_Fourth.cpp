#include <Arduino.h>

void setup() {
Serial.begin(9600);
}

void loop() {
	if(Serial.available()<5){
		int8_t operation=Serial.read();
		int32_t first=Serial.parseInt();
		int32_t second=Serial.parseInt();
		switch (operation) {
		case 'A': Serial.println(first+second);break;
		case 'S': Serial.println(first-second);break;
		case 'M': Serial.println(first*second);break;
		case 'D': Serial.println(first/second);break;
		}
	}
}

