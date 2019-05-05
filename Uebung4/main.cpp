#include <iostream>
#include "time.h"


using namespace std;


void SchreibeZeichen()
{
	for (int i = 33; i < 255; i++)
	{
		cout << "Zeichen: " << char(i) << " Nummer: " << i << endl;
	}

}

int main()
{
	SchreibeZeichen();


	srand(time(0));

	// Schleifen 1)
	cout << "von 1 nach 100" << endl;
	for (int i = 1; i <= 100; i++)
	{
		cout << i << endl;
	}
	cout << endl;

	cout << "von 100 nach 1" << endl;
	for (int i = 100; i >= 1; i--)
	{
		cout << i << endl;
	}

	// Schleifen 2)
	int EingabeZahl = 0;
	int Summe = 0;
	int Fakultaet = 1;

	// Ab Fakultät von 13 Zahlenüberlauf
	cout << "Geben Sie eine Zahl > 0 und < 13 ein bis zu der gezaehlt werden soll: ";
	cin >> EingabeZahl;

	if (EingabeZahl > 0 && EingabeZahl < 13)
	{
		for (int i = 1; i <= EingabeZahl; i++)
		{
			cout << i << endl;
			Summe = Summe + i;
			Fakultaet = Fakultaet * i;
		}
		cout << "Die Summe lautet: " << Summe << endl;
		cout << "Die Fakultaet lautet: " << Fakultaet << endl;
	}
	else
	{
		cout << EingabeZahl << " entspricht nicht den Anforderungen" << endl;
	}


	// Ratespiel 1)
	int BenutzerNummer, ZufallsNummer, AnzahlVersuche = 0;
	bool SpielVerlasen = false;

	//srand(time(0)); // TODO nachgucken was das genau macht
	ZufallsNummer = (rand()%6) + 1; // TODO nachgucken was das genau macht

	cout << "Ratespiel 1 Sie haben 3 Versuche" << endl;
	cout << "Die Nummer ist: " << ZufallsNummer << endl;
	cout << "Es wurde gewuerfelt, raten Sie die Zahl (1-6): ";


	while (!SpielVerlasen)
	{
		AnzahlVersuche++;

		if (AnzahlVersuche <= 3)
		{
			cout << AnzahlVersuche << ". Versuch: ";

			cin >> BenutzerNummer;
			if ((BenutzerNummer == ZufallsNummer))
			{
				SpielVerlasen = true;
				cout << "Richtig geraten!!!" << endl;
			}
			else if ((BenutzerNummer != ZufallsNummer))
			{
				cout << "Leider falsch :( , Raten Sie nochmal: ";
			}
		}
		else
		{
			SpielVerlasen = true;
			cout << "Leider haben Sie alle 3 Versuche aufgebraucht :( :( " << endl;
		}
	}


	// Ratespiel 2)
	SpielVerlasen = false;
	AnzahlVersuche = 0;

	int test = time(0);

	//srand(time(0)); // TODO nachgucken was das genau macht
	ZufallsNummer = (rand() % 6) + 1; // TODO nachgucken was das genau macht

	cout << endl;
	cout << "Ratespiel 2 Ich zahele Ihre Versuche" << endl;
	cout << "Die Nummer ist: " << ZufallsNummer << endl;
	cout << "Es wurde gewuerfelt, raten Sie die Zahl (1-6): ";


	while (!SpielVerlasen)
	{
		AnzahlVersuche++;
		cin >> BenutzerNummer;
		if ((BenutzerNummer == ZufallsNummer))
		{
			SpielVerlasen = true;
			cout << "Richtig geraten!!!" << endl;
			cout << "Sie habe nur " << AnzahlVersuche << " Versuche gebraucht! :) Toll!!!" << endl;
		}
		else if ((BenutzerNummer != ZufallsNummer))
		{
			cout << "Leider falsch :( , Raten Sie nochmal: ";
		}
	}


	// Ratespiel 3)
	SpielVerlasen = false;
	AnzahlVersuche = 0;

	//srand(time(0)); // TODO nachgucken was das genau macht
	ZufallsNummer = (rand() % 100) + 1; // TODO nachgucken was das genau macht

	cout << endl;
	cout << "Ratespiel 3 Raten Sie die Zahl" << endl;
	cout << "Die Nummer ist: " << ZufallsNummer << endl;
	cout << "Es wurde gewuerfelt, raten Sie die Zahl (1-100): ";


	while (!SpielVerlasen)
	{
		AnzahlVersuche++;
		cin >> BenutzerNummer;

		if (BenutzerNummer < ZufallsNummer)
		{
			cout << "Die gesuchte Nummer ist groesser , Raten Sie nochmal: " ;
		}
		else if (BenutzerNummer > ZufallsNummer)
		{
			cout << "Die gesuchte Nummer ist kleiner , Raten Sie nochmal: ";
		}
		else
		{
			SpielVerlasen = true;
			cout << "Richtig geraten!!!" << endl;
			cout << "Sie habe nur " << AnzahlVersuche << " Versuche gebraucht! :) Toll!!!" << endl;
		}
	}






	// Schreiben Sie ein Programm, dass zu einem eingegebenen Zeichen (char) den dazugehörigen Zahlencode ausgibt (ASCII). Schreiben Sie auch eine Funktion, die alle lesbaren Zeichen der ASCII-Tabelle auf der Konsole ausgibt. 
	//b) Bei einem Zeichen, dass der Benutzer eingegeben hat, soll jetzt herausgefunden werden, ob es sich um einen Kleinbuchstaben(a - z), Grossbuchstaben(A - Z) oder um eine Ziffer handelt(0 - 9).

	unsigned char EingabeZeichen;
	unsigned int EingabeWert;
	cout << "Geben Sie ein Zeichen ein: ";
	cin >> EingabeZeichen;
	cout << "Sie haben eingegeben: " << EingabeZeichen << endl;
	
	EingabeWert = (int)EingabeZeichen;
	cout << "Der Zahlenwert zum Zeichen ist: " << EingabeWert << endl;

	// Zahl ist von 48 bis 57
	if (EingabeWert >= 48 && EingabeWert <= 57)
	{

		cout << "Ziffer" << endl;
	}
	// kl Buchstabe ist von 97 bis 122
	else if (EingabeWert >= 97 && EingabeWert <= 122)
	{
		cout << "Kleiner Buchstabe" << endl;
	}
	// gr Buchstabe ist von 65 bis 90
	else if (EingabeWert >= 65 && EingabeWert <= 90)
	{
		cout << "Grosser Buchstabe" << endl;
	}
	else
	{
		cout << "Weder eine Ziffer, ein kleiner Buchstabe, noch ein grosser Buchstabe" << endl;
	}



	system("pause");
	return 0;
}