#ifndef __MATH_H__
#define __MATH_H__

/*
Defines
*/


/*
Makros
*/
#define ADDIEREN(wert1, wert2) ((wert1) + (wert2) )

/*
Funktionsprototypen
*/
int rechne(short, int, int);
int addiere(int, int);
int subtrahiere(int, int);
int multipliziere(int, int);
int dividiere(int, int);
int rechne_modulo(int, int);
int potenzieren_rekursiv(int, int);
int potenzieren_schleife(int, int);

/*
Globale Variablen
*/
enum Rechenart { addition = 1, subtraktion, multiplikation, division, modulo, potenzieren };

/*
Funktionen
*/

/*
input parameter		short rechenart
returns				none
*/
int rechne(short rechenart, int zahl1, int zahl2)
{
	int berechnetes_ergebnis = 0;

	switch (rechenart)
	{
	case addition:
		berechnetes_ergebnis = addiere(zahl1, zahl2);
		break;
	case subtraktion:
		berechnetes_ergebnis = subtrahiere(zahl1, zahl2);
		break;
	case multiplikation:
		berechnetes_ergebnis = multipliziere(zahl1, zahl2);
		break;
	case division:
		berechnetes_ergebnis = dividiere(zahl1, zahl2);
		break;
	case modulo:
		berechnetes_ergebnis = rechne_modulo(zahl1, zahl2);
		break;
	case potenzieren:
		// Variante 1
		berechnetes_ergebnis = potenzieren_rekursiv(zahl1, zahl2);
		// Variante 2
		berechnetes_ergebnis = potenzieren_schleife(zahl1, zahl2);
		break;
	//default:
		//print_error_message("Unbekannte Rechenoperation!");
	}

	return berechnetes_ergebnis;
}

/*
input parameter		int zahl1 (Summand)
					int zahl2 (Summand)
returns				ergebnis
*/
int addiere(int zahl1, int zahl2)
{
	return zahl1 + zahl2;
}

/*
input parameter		int zahl1 (Diminuend)
					int zahl2 (Subtrahend)
returns				ergebnis
*/
int subtrahiere(int zahl1, int zahl2)
{
	return zahl1 - zahl2;
}

/*
input parameter		int zahl1 (Faktor)
					int zahl2 (Faktor)
returns				ergebnis
*/
int multipliziere(int zahl1, int zahl2)
{
	return zahl1 * zahl2;
}

/*
input parameter		int zahl1 (Dividend)
					int zahl2 (Divisor)
returns				ergebnis
*/
int dividiere(int zahl1, int zahl2)
{
	return zahl1 / zahl2;
}

/*
input parameter		int zahl1 (keine Ahnung wie sich des schimpft 1)
					int zahl2 (keine Ahnung wie sich des schimpft 2)
returns				ergebnis
*/
int rechne_modulo(int zahl1, int zahl2)
{
	return zahl1 % zahl2;
}

/*
input parameter		int basis
					int exponent
returns				ergebnis
*/
int potenzieren_rekursiv(int basis, int exponent)
{
	// Abbruchbedingung
	if (exponent == 0)
	{
		return 1;
	}
	// Rekursionsvorschrift: Exponent wird pro Durchlauf um 1 reduziert
	basis *= potenzieren_rekursiv(basis, exponent - 1);

}

/*
input parameter		int basis
					int exponent
returns				ergebnis
*/
int potenzieren_schleife(int basis, int exponent)
{
	int ergebnis = 1;

	// Sonderfall
	if (exponent == 0)
	{
		return 1;
	}

	// Normaler Ablauf
	for (short i = 0; i < exponent; i++)
	{
		ergebnis *= basis;
	}

	return ergebnis;
}


#endif
