#pragma once
#include "Car.h"

//! \class SportCar
/*!
	Klasa SportCar przechowywujaca dane o samochodzie sportowym. Klasa pochodna klasy Car.
	Posiada funkcje pozwalajace na tworzenie nowego samochodu sportowego, pokazywania podanych parametrow,
	wziecia udzialu w wyscigu samochodowym, a takze moze korzystac z wszystkich funkcji klasy Car.
*/

class SportCar :
	public Car
{

#pragma region Variables

private:

	//!ilosc wygranych wyscigow
	unsigned int num_of_wins;

#pragma endregion

#pragma region Constructor and Destructor

public:

	//!konstruktor wymagajacy wszystkich parametrow
	SportCar(string eng_type = NULL, int eng_power = NULL, float eng_capacity = NULL, int eng_torque = NULL, bool eng_run = 0, string mark = NULL,
		string name = NULL, string colour = NULL, unsigned int max_speed = 0, int min_speed = 0, unsigned int acceleration = 0,
		unsigned int deceleration = 0, int actual_speed = 0, unsigned int num_of_seats = 0, float luggage_capacity = 0);
	//!destruktor nie robiacy nic poza usunieciem stworzonych obiektow danej klasy
	~SportCar();

#pragma endregion

#pragma region Methods

public:

	//!tworzy nowy samochod sportowy
	void newSportCar();
	//!wyswietla informacje o samochodzie sportowym
	void showSportCarInfo(); 
	//!bierze udzial w wyscigu ulicznym (w przypadku wygranej zwiekszenie num_of_wins o 1)
	void takePartInDragRace(); 

#pragma endregion


};

