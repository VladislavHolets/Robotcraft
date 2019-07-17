/*
 * Pick up on the blink example…
 * 1. Add two push buttons as “gas” and “brake” buttons; the “gas” button should
 * speed up the blinking rate of the LED, and the “brake” button should slow it down
 * 2. Do the same, but using a potentiometer and a button - ONLY when the button is
 * pressed, the LED should blink accordingly to the value of the potentiometer (in
 * other words, you can adjust the potentiometer, but it has no effect until you
 * press the “ON” button)
 * 3. Find out how long it is between the last statement in the loop() function and the
 * first one.
 */

#include <Arduino.h>
#include <stdint.h>
#define GAS_PIN 2
#define BRAKES_PIN 3
#define SENSOR_PIN A0
#define LED_PIN 13
volatile uint32_t blinkTime = 0;
void blink(uint8_t ledPin = 13);
void brakes();
void gas();
void setTime();
void setup() {
	pinMode(LED_PIN, OUTPUT);
	Serial.begin(9600);
//for first task
	//attachInterrupt(digitalPinToInterrupt(GAS_PIN),gas,FALLING);
	//attachInterrupt(digitalPinToInterrupt(BRAKES_PIN),brakes,FALLING);
//for second task
	attachInterrupt(digitalPinToInterrupt(GAS_PIN), setTime, FALLING);
}

uint32_t timeStamp;
uint32_t blinkTimeStamp = millis();

void loop() {
	timeStamp = micros();//for the third task but in microseconds

	blink();

	Serial.println(micros() - timeStamp);//the result of a third task in microseconds
}

//ISR
void brakes() {
	blinkTime += 100;
}

void gas() {
	if (blinkTime >= 100) {
		blinkTime -= 100;
	} else {
		blinkTime = 0;
	}
}

void setTime() {
	blinkTime = analogRead(SENSOR_PIN);
	blinkTime = blinkTime * 5000 / 1023;
}
//end of ISR

void blink(uint8_t ledPin) {
	if ((millis() - blinkTimeStamp) >= blinkTime) {
		blinkTimeStamp = millis();
		digitalWrite(LED_PIN, !digitalRead(LED_PIN));
	}
}
