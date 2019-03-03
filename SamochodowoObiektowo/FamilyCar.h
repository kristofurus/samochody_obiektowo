#pragma once
#include "Car.h"

//! \class FamilyCar
/*!
	Klasa FamilyCar przechowywujaca dane o samochodzie rodzinnym. Klasa pochodna klasy Car.
	Posiada funkcje pozwalajace na tworzenie nowego samochodu rodzinnego, pokazywania podanych parametrow,
	wyjazdu na wycieczke rodzinna, a takze moze korzystac z wszystkich funkcji klasy Car.
*/

class FamilyCar :
	public Car
{
#pragma region Variables

private:

	//!ilosc siedzien dla dzieci (moze byc od 0 do ilosci siedzen - 1)
	int num_of_baby_seats;

#pragma endregion

#pragma region Getter

public:

	//!zwraca ilosc siedzen dla dzieci
	int getNumOfBabySeats() { return num_of_baby_seats; }

#pragma endregion

#pragma region Setters

public:

	//!ustawia ilosc siedzen dla dzieci
	void setNumOfBabySeats(); 

#pragma endregion

#pragma region Constructor and Destructor

public:

	//!konstruktor wymagajacy wszystkich parametrow
	FamilyCar(string eng_type = NULL, int eng_power = NULL, float eng_capacity = NULL, int eng_torque = NULL, bool eng_run = 0,
		string mark = NULL, string name = NULL, string colour = NULL, unsigned int max_speed = 0, int min_speed = 0,
		unsigned int acceleration = 0, unsigned int deceleration = 0, int actual_speed = 0, unsigned int num_of_seats = 0,
		float luggage_capacity = 0, int num_of_baby_seats = 0); 
	//!destruktor nie robiacy nic poza usunieciem stworzonych obiektow danej klasy
	~FamilyCar();

#pragma endregion

#pragma region Methods

public:

	//!tworzy nowy samochod rodzinny
	void newFamilyCar(); 
	//!wyswietla informacje o samochodzie rodzinnym
	void showFamilyCarInfo(); 
	//!wyjazd na wycieczke rodzinna
	void familyTrip(); 

#pragma endregion

};

