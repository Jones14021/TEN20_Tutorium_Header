#ifndef __INPUT_OUTPUT_H__
#define __INPUT_OUTPUT_H__

/*
Includes
*/
#include<stdio.h>

/*
Defines
*/
#define SIZE_OUTPUT_BUFFER 20

/*
Funktionsprototypen
*/
short ergebnis_ausgeben(int, int);
int zahl_einlesen();
void print_error_message(char*);
short rechenoperation_einlesen();

/*
Globale Elemente
*/
enum Zahlensystem { hex, bin, dez, oct };
char Ziffern[] = { '0','1','2','3','4','5','6','7','8','9','A','B', 'C', 'D', 'E', 'F' };

/* 
Funktionen
*/

/*
input parameter		none
returns				die gelesene Rechenoperation (kodiert im Rechenart enum)
*/
short rechenoperation_einlesen()
{
	printf("Bitte gib die gewuenschte Rechenoperation ein:"
		"\n1\tAddition"
		"\n2\tSubtraktion"
		"\n3\tMultiplikation"
		"\n4\tDivision"
		"\n5\tModulo"
		"\n6\tPotenzieren"
		"\nRechenoperation: ");

	int operation = 0;
	scanf(" %d", &operation);

	return (short)operation;
}


/*
input parameter		int zahlensystem (spezifiziert, in welchem Zahlensystem das Ergebnis dargestellt wird)
returns				(0 = success, 1 = error)
----------------------------------------------------------------------------------------------------------------
Gibt das berechnete Ergebnis in der Konsole aus
*/
short ergebnis_ausgeben(int zahlensystem, int ergebnis)
{
	// Diese "Arbeitsvariable" wird immer weiter zerlegt.
	// Deshalb kopieren wir das Ergebnis, statt direkt globale Variable zu verwenden.
	int temp = ergebnis;

	// weitere lokale Variablen anlegen
	int rest = 1;
	int currentIndex = SIZE_OUTPUT_BUFFER - 1;
	short base = -1;
	short is_negative_number = 0;

	// Ausgabe Buffer deklarieren und alles mit Leerzeichen initialisieren
	char ausgabe_buffer[SIZE_OUTPUT_BUFFER + 1];

	for (int i = 0; i < 20; i++)
	{
		ausgabe_buffer[i] = ' ';
	}
	// letztes zeichen im C-String muss ein '\0' sein
	ausgabe_buffer[SIZE_OUTPUT_BUFFER] = '\0';

	// wenn das Ergebnis negativ ist, speichern wir das minus und rechnen mit dem Betrag weiter
	if (temp < 0)
	{
		temp *= -1;
		is_negative_number = 1;
	}

	// je nach auszugebendem Zahlensystem muss die Basis geändert werden
	switch (zahlensystem)
	{
	case hex:
		base = 16;
		break;

	case dez:
		base = 10;
		break;

	case bin:
		base = 2;
		break;

	case oct:
		base = 8;
		break;

	default:
		print_error_message("Ungueltiges Zahlensystem!");
		return 1;
	}

	// wenn etwas schiefgelaufen ist, wurde nichts in die Variable 'base' geschrieben
	// und sie hat immer noch den Wert -1
	if (base == -1)
	{
		print_error_message("Bei der Ausgabe ist etwas schief gelaufen!");
		return 1;
	}

	// Zeichenweise Umwandlung des Ergebnisses in das gewählte Zahlensystem
	if (temp == 0)
	{
		ausgabe_buffer[currentIndex] = Ziffern[0];
		currentIndex--;
	}
	else
	{
		while (temp != 0)
		{
			rest = temp % base;
			temp = temp / base;
			ausgabe_buffer[currentIndex] = Ziffern[rest];
			currentIndex--;
		}
	}

	// wenn die Zahl ursprünglich negativ war, fügen wir jetzt noch ein '-' an
	if (is_negative_number)
	{
		ausgabe_buffer[currentIndex] = '-';
		currentIndex--;
	}

	// Ausgabe des jetzt hoffentlich gefüllten buffers
	printf("Ergebnis: %s", ausgabe_buffer);

	// ein paar Leerzeilen, dass es schöner aussieht
	printf("\n\n\n\n");

	// return an die aufrufende Funktion (0 = success)
	return 0;
}

/*
input parameter		none
returns				Eine vorzeichenbehaftete, vom Nutzer eingebene Zahl
*/
int zahl_einlesen()
{
	int zahl = 0;
	printf("%s", "Bitte Zahl eingeben: ");
	scanf(" %d", &zahl);

	return zahl;
}

/*
input parameter		char* message (übergebene Fehlermeldung)
returns				none
*/
void print_error_message(char* message)
{
	printf("Fehler: %s", message);
}

#endif
