#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//! \class Engine
/*!
	Klasa Engine przechowywujaca podstawowe dane o silniku. Posiada funkcje pozwalajace na tworzenie nowego silnika,
	pokazywania podanych parametrow oraz zmiany stanu silnika na on lub off. Jest wykorzystywana w klasie Car oraz jego klasach pochodnych.
*/

class Engine
{

#pragma region Variables

	/** typ silnika mozliwe opcje to: diesel, bensine, electrinc, hybrid */
	string type;
	/** moc silnika w KM*/
	int power;
	/**pojemnosc silnika*/
	float capacity;
	//!moment obrotowy silnika
	int torque;
	//! czy silnik uruchomiony
	bool run; 

#pragma endregion

#pragma region Getters

public:

	//!zwraca wartosc typu silnika
	string getType() { return type; } 
	//!zwraca wartosc mocy silnika
	int getPower() { return power; } 
	//!zwraca pojemnosc silnika
	float getCapacity() { return capacity; }
	//!zwraca moment obrotowy silnika
	int getTorque() { return torque; } 
	//!zwraca boola sprawdzajacego czy silnik uruchomiony
	bool getRun() { return run; }

#pragma endregion

#pragma region Setters

public:

	//!ustawia typ silnika
	void setType(); 
	//!ustawia moc silnika
	void setPower();
	//!ustawia pojemnosc silnika
	void setCapacity(); 
	//!ustawia moment obrotowy silnika
	void setTorque(); 
	//!zmienia czy silnik uruchomiony czy nie
	void setRun(bool run) { this-> run = run; } 

#pragma endregion

#pragma region Constructor and Destructor

public:

	//!konstruktor nr 1 (podany ze wszystkim) wymaga podania przez uzytkownika ws
	Engine(string type = NULL, int power = NULL , float capacity = NULL , int torque = NULL, bool run = false); 
	//!konstruktor nr 2 (podany tylko z typem silnika) przypisuje podany typ silnika reszta jest wartoscia pusta
	Engine(string type = NULL); 
	//!konstruktor nr 3 (bez podanych zadnych danych) wszystkie wartosci sa puste
	Engine(); 
	//!destruktor nie robiacy nic poza usunieciem obiektu klasy silnik (JEST ZAWSZE TYLKO 1)
	~Engine(); 

#pragma endregion

#pragma region Methods

public:

	//!zmienienie wartosci parametru run na true (uruchomienie silnika)
	void turnEngineOn() { run = true; }
	//!zmienienie wartosci parametru run na false (wylaczenie silnika)
	void turnEngineOff() { run = false; }
	//!wyswietla informacje o silniku
	void showEngineInfo(); 
	//!tworzy nowy silnik
	void newEngine();

#pragma endregion
};