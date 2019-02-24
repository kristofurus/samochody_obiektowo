#pragma once
#include "Car.h"

class SportCar :
	public Car
{

#pragma region Variables

private:
	unsigned int num_of_wins;

#pragma endregion

#pragma region Constructor and Destructor

public:
	SportCar(string eng_type = NULL, int eng_power = NULL, float eng_capacity = NULL, int eng_torque = NULL, bool eng_run = 0, string c_mark = NULL,
		string c_name = NULL, string c_colour = NULL, unsigned int c_max_speed = 0, int c_min_speed = 0, unsigned int c_acceleration = 0,
		unsigned int c_deceleration = 0, int c_actual_speed = 0, unsigned int c_num_of_seats = 0, float c_luggage_capacity = 0); //konstruktor
	~SportCar(); //destruktor

#pragma endregion

#pragma region Methods

public:
	void newSportCar(); //tworzy nowy samochod sportowy
	void showSportCarInfo(); //wyswietla informacje o samochodzie sportowym
	void takePartInDragRace(); //bierze udzial w wyscigu ulicznym (w przypadku wygranej zwiekszenie num_of_wins o 1)

#pragma endregion


};

