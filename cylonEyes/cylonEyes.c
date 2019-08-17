#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	uint8_t i = 0;
	int8_t increment = 1;

	DDRB = 0xFF;

	while(1) {
		PORTB = (1 << i);
		_delay_ms(50);

		i += increment;

		if (i > 6) {
			increment = -1;
		} else if (i < 1) {
			increment = 1;
		}
	}

	return 1;
}
