#ifndef DIODE_H_
#define DIODE_H_

#include <avr/io.h>
#include <util/delay.h>

class Diode {
public:
	enum PORT {B, C, D};
	Diode(PORT Port, int Pin);
public:
	void Blink();
	void XOR();
	void Set(bool State);
private:
	void Init();
private:
	PORT mPort;
	int mPin;
};

#endif /* DIODE_H_ */
