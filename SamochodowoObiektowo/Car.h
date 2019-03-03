#pragma once
#include "pch.h"
#include "Engine.h"
#include <iostream>
#include <string>

using namespace std;

//! \class Car
/*!
	Klasa Car przechowywujaca podstawowe dane o samochodzie. Jest klasa bazowa klas SportCar i FamilyCar.
	Posiada funkcje pozwalajace na tworzenie nowego samochodu, zmiany koloru, pokazywania podanych parametrow,
	zmiany stanu silnika na on lub off oraz zmianny predkosci poprzez podane acceleration, deceleration,
	lub wyzerowanie predkosci funkcja breakCar().
*/

class Car
{

#pragma region Variables

private:
	/**silnik z klasy Engine*/
	Engine cars_engine;
	/**marka samochodu*/
	string mark; 
	/**nazwa samochodu*/
	string name; 
	/**kolor samochodu*/
	string colour;
	/**maksymalna predkosc*/
	unsigned int max_speed;
	/**minimalna predkosc*/
	int min_speed;
	/**przyspieszenie pojazdu*/
	unsigned int acceleration;
	/**zwalnianie pojazdu*/
	unsigned int deceleration;
	/**aktualna predkosc samochodu*/
	int actual_speed;
	/**ilosc siedzen*/
	unsigned int num_of_seats; 
	/**pojemnosc bagaznika [L]*/
	float luggage_capacity; 
	//numer rejestracyjny?

#pragma endregion

#pragma region Getter

public:
	/** getter zwracajacy parametry silnika*/
	Engine getCarsEngine() { return cars_engine; }
	/**getter zwracajacy marke samochodu*/
	string getMark() { return mark; }
	/**getter zwracajacy nazwe pojazdu*/
	string getName() { return name; }
	/**getter zwracajacy kolor*/
	string getColour() { return colour; }
	/**zwraca maksymalna predkosc*/
	unsigned int getMaxSpeed() { return max_speed; }
	/**zwraca minimalna predkosc*/
	int getMinSpeed() { return min_speed; } 
	/**zwraca przyspieszenie*/
	unsigned int getAcceleration() { return acceleration; }
	/**zwraca wartosc spowolnienia*/
	unsigned int getDeceleration() { return deceleration; }
	/**zwraca aktualna predkosc*/
	int getActualSpeed() { return actual_speed; } 
	/**zwraca ilosc siedzen*/
	unsigned int getNumOfSeats() { return num_of_seats; }
	/**zwraca pojemnosc bagaznika*/
	float getLuggageCapacity() { return luggage_capacity; } 

#pragma endregion

#pragma region Setter

public:
	/**ustawia silnik (korzystajac z newEngine())*/
	void setCarsEngine();
	/**ustawia marke samochodu*/
	void setMark();
	/**ustawia nazwe*/
	void setName();
	/**ustawia kolor*/
	void setColour();
	/**ustawia maksymalna predkosc*/
	void setMaxSpeed();
	/**ustawia minimalna predkosc*/
	void setMinSpeed();
	/**ustawia przyspieszenie*/
	void setAcceleration();
	/**ustawia spowolnienie*/
	void setDeceleration();
	/**ustawia aktualna predkosc*/
	void setActualSpeed(int actual_speed) { this -> actual_speed = actual_speed; }
	/**ustawia ilosc siedzen*/
	void setNumOfSeats();
	/**ustawia pojemnosc bagaznika*/
	void setLuggageCapacity();

#pragma endregion

#pragma region Constructor and Destructor

public:
	//!konstruktor
	/*!
		konstruktor wymagajacy wszystkich parametrow
	*/
	Car(string eng_type = NULL, int eng_power = NULL, float eng_capacity = NULL, int eng_torque = NULL, bool eng_run = 0, string mark = NULL,
		string name = NULL, string colour = NULL, unsigned int max_speed = 0, int min_speed = 0, unsigned int acceleration = 0,
		unsigned int deceleration = 0, int actual_speed = 0, unsigned int num_of_seats = 0, float luggage_capacity = 0); 
	//!destruktor
	/*!
		destruktor nie robiacy nic poza usunieciem stworzonych obiektow danej klasy
	*/
	~Car(); 

#pragma endregion

#pragma region Methods

public:
	/**tworzy nowy samochod*/
	void newCar(); 
	/**wyswietla informacje o samochodzie*/
	void showCarInfo();
	/**zmienia kolor samochodu*/
	void changeColour();
	/**zwieksza actual_speed o wartosc accelerate o ile actual_speed + accelerate <= max_speed */
	void accelerate();
	/**zmniejsza actual_speed o wartosc decelerate o ile actual_speed - decelerate >= min_speed */
	void decelerate();
	//zeruje predkosc*/
	void breakCar() { setActualSpeed(0); }
	/**uruchamia silnik*/
	void turnEngineOn() { cars_engine.setRun(true); }
	/**wylacza silnik*/
	void turnEngineOff() { cars_engine.setRun(false); }

#pragma endregion

};