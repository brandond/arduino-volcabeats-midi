#include <Arduino.h>
#include <MIDI.h>
#include "notes.h"

#define MIDI_CHANNEL 5

MIDI_CREATE_DEFAULT_INSTANCE();

volatile bool ledState;

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	toggleLED();
	MIDI.begin(MIDI_CHANNEL);
	MIDI.turnThruOff();
	MIDI.setHandleNoteOn(noteOn);
	MIDI.setHandleClock(clock);
	MIDI.setHandleControlChange(controlChange);
	toggleLED();
}

void loop() {
	if (MIDI.read()) {
		toggleLED();
	}
}

void noteOn(byte channel, byte note, byte velocity) {
	if (velocity <= 64) {
		note = normal[note];
		velocity = 127;
	} else if (velocity <= 127) {
		note = accent[note];
		velocity = 127;
	} else {
		note = 0;
	}
	if (note != 0 && velocity != 0) {
		MIDI.sendNoteOn(note, velocity, channel);
	}
}

void controlChange(byte channel, byte function, byte value) {
	MIDI.sendControlChange(function, value, channel);
}

void clock() {
	MIDI.sendClock();
}

void toggleLED() {
	ledState = !ledState;
	digitalWrite(LED_BUILTIN, ledState);
}
