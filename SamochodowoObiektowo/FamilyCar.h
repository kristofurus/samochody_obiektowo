#pragma once
#include "Car.h"

class FamilyCar :
	public Car
{
#pragma region Variables

private:
	int num_of_baby_seats;

#pragma endregion

#pragma region Getter

public:
	int getNumOfBabySeats() { return num_of_baby_seats; } //zwraca ilosc siedzen dla dzieci

#pragma endregion

#pragma region Setters

	void setNumOfBabySeats(); //ustawia ilosc siedzen dla dzieci

#pragma endregion

#pragma region Constructor and Destructor

public:
	FamilyCar(string eng_type = NULL, int eng_power = NULL, float eng_capacity = NULL, int eng_torque = NULL, bool eng_run = 0,
		string c_mark = NULL, string c_name = NULL, string c_colour = NULL, unsigned int c_max_speed = 0, int c_min_speed = 0,
		unsigned int c_acceleration = 0, unsigned int c_deceleration = 0, int c_actual_speed = 0, unsigned int c_num_of_seats = 0,
		float c_luggage_capacity = 0, int fc_num_of_baby_seats = 0); //konstruktor
	~FamilyCar(); //destruktor

#pragma endregion

#pragma region Methods

public:
	void newFamilyCar(); //tworzy nowy samochod rodzinny
	void showFamilyCarInfo(); //wyswietla informacje o samochodzie rodzinnym
	void familyTrip(); //wyjazd na wycieczke rodzinna

#pragma endregion


};

