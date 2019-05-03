#include <iostream>
#include "time.h"


using namespace std;

int main()
{

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

	system("pause");
	return 0;
}