#include "pch.h"
#include "Engine.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

/* TODO
1. Klasa Samochod (DONE)
2. Podklasy samochodu <- dziedziczenie
2.1. Sportowy
2.2. Rodzinny (DONE)
2.3. Rolniczy?
2.4. Specjalne <- to chyba bedzie fajne na polimorfizm (if i remember correctly)
2.4.1. Ambulans
2.4.2. Straz pozarna
2.4.3. Policja
3. Klasa silnik (DONE)
4. Klasa kierowca? (imie, nazwisko, nr tel, pesel) <- moze friend z tego sie da zrobic (przypisanie samochodu do osoby za pomoca tablicy rejestracyjnej?)
zaraz w takim razie sie z tego jeszcze baza danych zrobi normalnie XD baza silnikow do wyboru przy tworzeniu samochodow i cala baza kierowcow i samochodow
i ich laczenie (az sie zadanie na Accessa przypomina)
*/

int main()
{	
	string engType;
	Car brum("diesel", 170, 60.5, 350, false, "Porsche", "911", "red", 200, -50, 30, 25, 0, 2, 40.0);
	Car brum2("bensine", 300, 20, 700, true, "Ferrari", "112", "yellow", 500, -100, 60, 50, 0, 5, 20.0);
	Car autko("", 0, 0.0, 0, false, "", "", "", 0, 0, 0, 0, 0, 0, 0.0);
	Engine eng("bensine", 120, 124, 200, true);
	vector <Car> autka;
	autka.push_back(brum);
	autka.push_back(brum2);
	for (int i = 0; i < autka.size(); i++)
	{
		autko = autka[i];
		autko.showCarInfo();
	}
}