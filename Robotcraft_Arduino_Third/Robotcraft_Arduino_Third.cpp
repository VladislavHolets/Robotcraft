/*
 * Implement a way to control road traffic lights
 * in a given road with Arduino. At the crossroads
 * of A and B Avenues it is intended to send
 * correct signals in order to control the traffic
 * lights and ensure safety of pedestrians.
 */
#include <Arduino.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define FIRST 0
#define SECOND 1
#define PEDESTRIAN_FIRST 2
#define PEDESTRIAN_SECOND 3

#define DAY_TIME 0
#define NIGHT_TIME 1

#define SEC 1000
#define DUTY_CYCLE 127

#define SWITCH_PIN 2

volatile uint8_t flag = DAY_TIME;
void setTime();
void traficLights();
uint8_t road[4][3] { { 3, 5, 4 }, { 8, 9, 10 }, { 6, 255, 7 }, { 11, 255, 12 } };
//value 255 are for those lights that are not existing (yellow on pedestrian cross)
void setup() {
	for (uint8_t i = 0; i < 2; ++i) {
		for (uint8_t j = 0; j < 3; ++j) {
			pinMode(road[i][j], OUTPUT);
			digitalWrite(road[i][j], LOW);
		}
	}
	Serial.begin(9600);
	delay(100);
	attachInterrupt(digitalPinToInterrupt(SWITCH_PIN), setTime, CHANGE);
}

void loop() {
	traficLights();
}
void traficLights() {
	uint32_t timeStamp[4] { 0 };
	uint32_t nightTimeStamp = millis();
	uint8_t onFlag;
	timeStamp[0] = millis();
	Serial.println("First");
	digitalWrite(road[FIRST][RED], LOW);
	digitalWrite(road[FIRST][YELLOW], LOW);
	digitalWrite(road[FIRST][GREEN], HIGH);

	digitalWrite(road[SECOND][RED], HIGH);
	digitalWrite(road[SECOND][YELLOW], LOW);
	digitalWrite(road[SECOND][GREEN], LOW);

	digitalWrite(road[PEDESTRIAN_FIRST][RED], HIGH);
	digitalWrite(road[PEDESTRIAN_FIRST][GREEN], LOW);

	digitalWrite(road[PEDESTRIAN_SECOND][RED], LOW);
	digitalWrite(road[PEDESTRIAN_SECOND][GREEN], HIGH);
	while (1) {
		if (flag == DAY_TIME && !timeStamp[3] && timeStamp[0]
				&& ((millis() - timeStamp[0]) >= (6 * SEC))) {
			timeStamp[0] = 0;
			timeStamp[1] = millis();

			Serial.println("Second");

			digitalWrite(road[FIRST][RED], LOW);
			digitalWrite(road[FIRST][YELLOW], HIGH);
			digitalWrite(road[FIRST][GREEN], LOW);

			digitalWrite(road[SECOND][RED], HIGH);
			digitalWrite(road[SECOND][YELLOW], LOW);
			digitalWrite(road[SECOND][GREEN], LOW);

			digitalWrite(road[PEDESTRIAN_FIRST][RED], HIGH);
			digitalWrite(road[PEDESTRIAN_FIRST][GREEN], LOW);

			digitalWrite(road[PEDESTRIAN_SECOND][RED], LOW);
			digitalWrite(road[PEDESTRIAN_SECOND][GREEN], HIGH);

		}
		if (flag == DAY_TIME && !timeStamp[0] && timeStamp[1]
				&& ((millis() - timeStamp[1]) >= (1 * SEC))) {
			timeStamp[1] = 0;
			timeStamp[2] = millis();

			Serial.println("Third");

			digitalWrite(road[FIRST][RED], HIGH);
			digitalWrite(road[FIRST][YELLOW], LOW);
			digitalWrite(road[FIRST][GREEN], LOW);

			digitalWrite(road[SECOND][RED], LOW);
			digitalWrite(road[SECOND][YELLOW], LOW);
			digitalWrite(road[SECOND][GREEN], HIGH);

			digitalWrite(road[PEDESTRIAN_FIRST][RED], LOW);
			digitalWrite(road[PEDESTRIAN_FIRST][GREEN], HIGH);

			digitalWrite(road[PEDESTRIAN_SECOND][RED], HIGH);
			digitalWrite(road[PEDESTRIAN_SECOND][GREEN], LOW);

		}
		if (flag == DAY_TIME && !timeStamp[1] && timeStamp[2]
				&& ((millis() - timeStamp[2]) >= (3 * SEC))) {
			timeStamp[2] = 0;
			timeStamp[3] = millis();

			Serial.println("Fourth");

			digitalWrite(road[FIRST][RED], HIGH);
			digitalWrite(road[FIRST][YELLOW], LOW);
			digitalWrite(road[FIRST][GREEN], LOW);

			digitalWrite(road[SECOND][RED], LOW);
			digitalWrite(road[SECOND][YELLOW], HIGH);
			digitalWrite(road[SECOND][GREEN], LOW);

			digitalWrite(road[PEDESTRIAN_FIRST][RED], LOW);
			digitalWrite(road[PEDESTRIAN_FIRST][GREEN], HIGH);

			digitalWrite(road[PEDESTRIAN_SECOND][RED], HIGH);
			digitalWrite(road[PEDESTRIAN_SECOND][GREEN], LOW);

		}
		if (flag == DAY_TIME && !timeStamp[2] && timeStamp[3]
				&& ((millis() - timeStamp[3]) >= 1 * SEC)) {
			timeStamp[3] = 0;
			timeStamp[0] = millis();

			Serial.println("First");

			digitalWrite(road[FIRST][RED], LOW);
			digitalWrite(road[FIRST][YELLOW], LOW);
			digitalWrite(road[FIRST][GREEN], HIGH);

			digitalWrite(road[SECOND][RED], HIGH);
			digitalWrite(road[SECOND][YELLOW], LOW);
			digitalWrite(road[SECOND][GREEN], LOW);

			digitalWrite(road[PEDESTRIAN_FIRST][RED], HIGH);
			digitalWrite(road[PEDESTRIAN_FIRST][GREEN], LOW);

			digitalWrite(road[PEDESTRIAN_SECOND][RED], LOW);
			digitalWrite(road[PEDESTRIAN_SECOND][GREEN], HIGH);

		}
		if (flag == NIGHT_TIME && millis() - nightTimeStamp > 1*SEC) {
			nightTimeStamp=millis();

            digitalWrite(road[FIRST][RED], LOW);
            digitalWrite(road[FIRST][GREEN], LOW);

            digitalWrite(road[SECOND][RED], LOW);
            digitalWrite(road[SECOND][GREEN], LOW);

            digitalWrite(road[PEDESTRIAN_FIRST][RED], LOW);
            digitalWrite(road[PEDESTRIAN_FIRST][GREEN], LOW);

            digitalWrite(road[PEDESTRIAN_SECOND][RED], LOW);
            digitalWrite(road[PEDESTRIAN_SECOND][GREEN], LOW);

         	analogWrite(road[FIRST][YELLOW], (onFlag) ? DUTY_CYCLE : 0);
            analogWrite(road[SECOND][YELLOW], (onFlag) ? DUTY_CYCLE : 0);

			onFlag = !onFlag;

		}

	}
}
void setTime() {
	flag = digitalRead(SWITCH_PIN);
}
