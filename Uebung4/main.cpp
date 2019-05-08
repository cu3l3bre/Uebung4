

//Aufgabenbeschreibung
//Übungen zu Kontrollstrukturen / Schleifen
//
//1. Geben Sie die Zahlen einmal von 1 - 100 aus, dann in umgekehrter Reihenfolge.
//2. Geben Sie die Zahlen von 1 bis zur Zahl X aus, X wird vom Benutzer eingegeben.
//b) Berechnen Sie dabei auch die Gesamtsumme aller Zahlen von 1 bis zum eingegebenen Wert.
//c) Zusätzlich soll auch gleich die Fakultät der Zahlen berechnet und ausgegeben werden.
//
//
//
//Ratespiel
//
//Finden Sie selbstständig heraus, wie in C++ eine Zufallszahl erzeugt wird.
//1. Schreiben Sie ein Programm, das beim Start eine zufällige Zahl zwischen 1 und 6 (Würfeln)erzeugt.Nun soll der Benutzer eine Zahl selbst eingeben.Vergleichen Sie die Zahl mit der Zufallszahl und geben bei Gleichheit eine Erfolgsmeldung aus, andernfalls einen Hinweis, dass die Zahl nicht richtig geraten wurde.
//2. Erweitern Sie das Ratespiel so, dass der Benutzer nun genau 3 Versuche hat, die Zahl zu raten.
//3. Jetzt soll der Benutzer so lange die Zahl erraten können, bis die Zahl übereinstimmt.Geben Sie am Ende die Anzahl der Versuche aus.
//4. Verändern Sie das Programm so, dass nun Zufallszahlen zwischen 1 und 100 möglich sind.Damit der Anwender leichter zur Lösung kommt, soll nach jedem falschen Versuch angegeben werden, ob die gesuchte Zahl kleiner oder größer als der Rateversuch ist.


//Bonusaufgaben:
//
//Zu Aufgabe 1.c) ab wann ist der Wertebereich der ganzen Zahlen bei der Fakultät überschritten ? Finden Sie eine Möglichkeit, dann die Ausgabe abzubrechen und eine entsprechende Meldung auszugeben.
//
//Schreiben Sie ein Programm, dass zu einem eingegebenen Zeichen(char) den dazugehörigen Zahlencode ausgibt(ASCII).Schreiben Sie auch eine Funktion, die alle lesbaren Zeichen der ASCII - Tabelle auf der Konsole ausgibt.
//b) Bei einem Zeichen, dass der Benutzer eingegeben hat, soll jetzt herausgefunden werden, ob es sich um einen Kleinbuchstaben(a - z), Grossbuchstaben(A - Z) oder um eine Ziffer handelt(0 - 9).




#include <iostream>
#include <time.h>


using namespace std;

// Funktion zu Bonusaufgaben
void SchreibeZeichen()
{
	for (int i = 33; i < 255; i++)
	{
		cout << "Zeichen: " << unsigned char(i) << " Nummer: " << i << endl;
	}

}

int main()
{
	
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

	int Uhrzeit = time(0);	// Akutuelle Uhrzeit als UnixTimeStamp
	
	
	// Startwert von srand wird auch als Seed bezeichnet
	// srand sollte am besten nur ein mal zu Beginn des Programms aufgerufen werden
	
	// Zufallsgenerator starten mit der aktuellen Uhrzeit als Startwert
	srand(Uhrzeit);			

	// Hinweis zu srand
	// srand(time(0))
	// *mache irgendwas mit rand*
	// srand(time(0))
	// *mache nochmal irgendwas mit rand*
	// dann würden diei zufallszahlen die durch srand ermittelt werden, die gleichen sein
	// da es in der gleichen Sekunde aufgerufen wird, also nur einmal die srand funktion benutzen


	int BenutzerNummer, ZufallsNummer, AnzahlVersuche = 0;
	bool SpielVerlasen = false;

	ZufallsNummer = (rand()%6) + 1;
	
	//int randtest = rand();
	//cout << randtest << endl;
	//cout << randtest%6 << endl;


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
	//cout << "Test Time ist: " << test << endl;

	ZufallsNummer = (rand() % 6) + 1;

	// Hinweis hierzu zur Berechnung der Zufallsnummer mit %
	// 6  / 6 = 1 Rest 0
	// 7  / 6 = 1 Rest 1
	// 8  / 6 = 1 Rest 2
	// 9  / 6 = 1 Rest 3
	// 10 / 6 = 1 Rest 4
	// 11 / 6 = 1 Rest 5
	// 12 / 6 = 2 Rest 0

	// dh mit %6 bekomme ich immer den rest von 0 bis 5, deswegen rechne ich +1 um die wuerfelzahlen zu bekommen


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

	ZufallsNummer = (rand() % 100) + 1;

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


	SchreibeZeichen();


	unsigned char EingabeZeichen;
	int EingabeWert;
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
		cout << "Weder eine Ziffer, ein kleiner Buchstabe (a-z) , noch ein grosser Buchstabe (A-Z)" << endl;
	}



	system("pause");
	return 0;
}