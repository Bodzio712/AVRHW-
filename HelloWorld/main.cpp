#include <avr/io.h>
#include <util/delay.h>

#include "diode.h"

int main(void) {
	Diode d = Diode(Diode::B, PB0);
	while(true) {
		d.Blink();
	}
}
