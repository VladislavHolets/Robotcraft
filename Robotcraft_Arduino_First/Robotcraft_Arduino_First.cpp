/*
 * The task is:
 * Pick up on the blink example…
 * 1. Change LED’s duty cycle to 75%
 * 2. Change the pin to which the LED is connected from pin 13 to pin 2 (Note that
 * both the circuit AND the program must be changed)
 * 3. Hook up 8 LEDs to pins 2 through 9 (with resistors, of course.) Modify the
 * code to turn on each one in order and then extinguish them in order
 * 4. Now that you have 8 LEDs working, make them turn on and off in a pattern
 * different from the one in exercise 3
 */
#include <Arduino.h>
//for Arduino Nano, Uno and similar
#define LED_PIN 8
#define IS_PWM_PIN(pin) pin==3 || pin==5 || pin==6 || pin==9 || pin==10 || pin==11

/*
 * You may have noticed such types as uint8_t in my code;)
 * if you ever meet it or want to use it remember :
 * u means Unsigned
 * int means INTeger as usual
 * 8(16,32,64) means the size in bits(%8 must always be 0)
 * _t is just used to recognize that this Type is not included in STD(standart library set for C / C++)
 * It is used when it is important to have very optimized code
 * where you do know how many bytes your variables need.
 * Examples uint8_t, int16_t, uint32_t and so on
 * This types are stored in a header file <stdint.h> and should be included  before usage.
 */
#include <stdint.h>

void first(const uint8_t ledPin, uint8_t dutyCycleInPercents = 75); //task #1
void second(); //task#2
void third(uint8_t leds[8]); //task#3
uint8_t leds[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
void fourth(uint8_t leds[8]);
void setup() {

}

void loop() {
//first(LED_PIN);
//second();
	third(leds);
	fourth(leds);
}
void first(const uint8_t ledPin, uint8_t dutyCycleInPercents) {

	if (IS_PWM_PIN(ledPin)) {
		uint8_t dutyCycle = ((uint16_t) (dutyCycleInPercents * 255) / 100);
		analogWrite(ledPin, dutyCycle);
		//while using analogWrite it is not obligatory to set pin to OUTPUT
		while (true) {
		}
	} else {
		pinMode(ledPin, OUTPUT);
		uint32_t timeStamp[2] { 0 };
		//unsigned long in other words;)
		timeStamp[0] = millis();
		while (1) {
			/*
			 * Next code seems complicated and slow, huh;)
			 * Lets look closer:
			 * you have seen on Monday, how millis() allows us to avoid delays,
			 * it has a twin;) micros() gives the same time but in microseconds
			 * this codes shows how to simulate Low-frequent PWM using micros()
			 * in order to not miss anything;)
			 * as a special task #1 here you can try to write pseudocode or draw a diagram
			 * of this part in order to see if you really understood why it works(self-check)
			 * (hint: while not used, one timeStamp is used as a flag)
			 */
			if (micros() - timeStamp[1] >= dutyCycleInPercents
					&& !timeStamp[0]) {
				timeStamp[0] = micros();
				timeStamp[1] = 0;
				digitalWrite(ledPin, LOW);
			}
			if (micros() - timeStamp[0] >= (100 - dutyCycleInPercents)
					&& !timeStamp[1]) {
				timeStamp[1] = micros();
				timeStamp[0] = 0;
				digitalWrite(ledPin, HIGH);

			}

			/*
			 * to be honest one slow part is present;)
			 * pay attention to the size of timeStamp[0] and [1]
			 * they are 32 bits, OMG
			 * if we were compiling for our computers that use AMD64 processors we would hardly ever noticed the difference
			 * because AMD 64 has a 64 bits bus size so that at once it can read 64 bits of data,
			 * and it does not matter to it if you use int8_t of uint64_t
			 * it always takes one "tick" to get this variable
			 * Arduino is a little smaller, it has a 8 bits bus size,which means 8 bits at once
			 * which means for every operation with timeStamp[0] or [1] we need 4 ticks
			 * on the other hand we can't use smaller variable because millis() returns uint32_t
			 */
		}
	}

}
void second() {
	first(2);
	//don't forget to change wiring;)
}
void third(uint8_t leds[8]) {
	/*
	 * Special task #2 remake this and next function to work with pointers
	 * and make it cleaner;)
	 *(hint somewhere must be something similar: const uint8_t size=8 or SIZE defined)
	 */
	for (uint8_t i = 0; i < 8; ++i) {
		pinMode(leds[i], OUTPUT);
	}
	while (1) {
		for (uint8_t i = 0; i < 8; ++i) {
			digitalWrite(leds[i], HIGH);
			delay(200);
		}
		for (int8_t i = 7; i >= 0; --i) {
			digitalWrite(leds[i], LOW);
			delay(200);
		}
	}

}
void fourth(uint8_t leds[8]) {
	for (uint8_t i = 0; i < 8; ++i) {
		pinMode(leds[i], OUTPUT);
	}
	while (1) {
		for (uint8_t i = 0; i < 8; i += 2) {
			digitalWrite(leds[i + 1], LOW);
			delay(100);
			digitalWrite(leds[i], HIGH);
			delay(100);
		}
		for (uint8_t i = 1; i < 8; i += 2) {
			digitalWrite(leds[i - 1], LOW);
			delay(100);
			digitalWrite(leds[i], HIGH);
			delay(100);
		}
	}
}
