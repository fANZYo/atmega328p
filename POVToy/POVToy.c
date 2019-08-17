#include <avr/io.h>
#include <util/delay.h>

void POVDisplay(uint8_t byte) {
	PORTB = byte;
	_delay_ms(2);
}

int main(void) {
	DDRB = 0xFF;

	uint8_t invaders[] = {
		0b00001110,
		0b00011000,
		0b10111101,
		0b01110110,
		0b00111100,
		0b00111100,
		0b00111100,
		0b01110110,
		0b10111101,
		0b00011000,
		0b00001110,
	};

	uint8_t hearts[] = {
		0b01110000,
		0b11111100,
		0b00111111,
		0b11111100,
		0b01110000,
		0b00000000,
		0b01110000,
		0b11111100,
		0b00111111,
		0b11111100,
		0b01110000,
	};

	while(1) {
		for (uint8_t i = 0; i < 8; i += 1) {
			POVDisplay(hearts[i]);
		}

		PORTB = 0;
		_delay_ms(10);
	}

	return 1;
}
