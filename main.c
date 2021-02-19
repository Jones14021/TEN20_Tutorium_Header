#include "main.h"
#include "math.h"
#include "input_output.h"

int main(void)
{
	int ergebnis = 0;

	do
	{
		// erste Zahl einlesen	
		printf("Was soll die erste Zahl sein? (Summand / Diminuend / Faktor/ Dividend / Basis)\n");
		int x = zahl_einlesen();

		// zweite Zahl einlesen
		printf("Was soll die zweite Zahl sein? (Summand / Subtrahend / Faktor / Divisor / Exponent)\n");
		int y = zahl_einlesen();

		// Rechenoperation abfragen
		short rechenoperation = rechenoperation_einlesen();

		// die richtige Operation auf die Zahlen anwenden
		ergebnis = rechne(rechenoperation, x, y);

		// Ergebnis ausgeben	
		ergebnis_ausgeben(dez, ergebnis);

	} while (1);

	return 0;
}