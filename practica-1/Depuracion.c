// edu@uma.es - 18/02/22 (v2)

// Depuracion: Determinar los valores minimos, tanto en decimal como en
// hexadecimal, que toman las variables "val" y "reg" y el registro "P1IES" (que
// pertenece al periferico "Port 1") a lo largo del codigo, indicando las lineas
// donde alcanzan dichos valores

#include "msp430g2553.h"

unsigned char reg = 0xFF;;

void main(void) {
	volatile unsigned int val = 0xFFFF;
	int temp = 0;
	unsigned int cont;

	WDTCTL = (WDTPW|WDTHOLD);

	for (cont = 0; cont < 1000; cont++) {
		temp += 12345;
	} // for (cont = 0; cont < 1000; cont++)

	val = (temp^0x7FFF);
	reg = (unsigned char) (val^0x69);
	P1IES = (reg^0x5A);

	for (cont = 1000; cont > 0; cont--) {
		temp -= 54321;
	} // for (cont = 1000; cont > 0; cont--)

	val = (temp^0x7FFF);
	reg = (unsigned char) (val^0xE9);
	P1IES = (reg^0xDA);

	while (1);

} // void main(void)
