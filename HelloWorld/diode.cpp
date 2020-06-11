#include <avr/io.h>
#include "diode.h"

Diode::Diode(PORT Port, int Pin) {
	mPort = Port;
	mPin = Pin;
	Init();
}

void Diode::Init() {
	switch(mPort) {
	case Diode::B:
		DDRB |= (1<<mPin);
		break;
	case Diode::C:
		DDRC |= (1<<mPin);
		break;
	case Diode::D:
		DDRD |= (1<<mPin);
		break;
	default:
		break;
	}
}

void Diode::XOR(){
	switch(mPort) {
	case Diode::B:
		PORTB ^= (1<<mPin);
		break;
	case Diode::C:
		PORTC ^= (1<<mPin);
		break;
	case Diode::D:
		PORTD ^= (1<<mPin);
		break;
	default:
		break;
	}
}

void Diode::Set(bool State) {
	if(State) {
		switch(mPort) {
		case Diode::B:
			PORTB |= (1<<mPin);
			break;
		case Diode::C:
			PORTC |= (1<<mPin);
			break;
		case Diode::D:
			PORTD |= (1<<mPin);
			break;
		default:
			break;
		}
	}
	else {
		switch(mPort) {
		case Diode::B:
			PORTB &= !(1<<mPin);
			break;
		case Diode::C:
			PORTC &= !(1<<mPin);
			break;
		case Diode::D:
			PORTD &= !(1<<mPin);
			break;
		default:
			break;
		}
	}
}

void Diode::Blink() {
	XOR();
	_delay_ms(100);
}
