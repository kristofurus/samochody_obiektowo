#include "pch.h"
#include "SportCar.h"
#include <ctime>

#pragma region Constructor and Destructor

SportCar::SportCar(string eng_type, int eng_power, float eng_capacity, int eng_torque, bool eng_run,
	string c_mark, string c_name, string c_colour, unsigned int c_max_speed, int c_min_speed, unsigned int c_acceleration,
	unsigned int c_deceleration, int c_actual_speed, unsigned int c_num_of_seats, float c_luggage_capacity)
	:Car(eng_type, eng_power, eng_capacity, eng_torque, eng_run, c_mark, c_name, c_colour, c_max_speed, c_min_speed, c_acceleration, c_deceleration,
		c_actual_speed, c_num_of_seats, c_luggage_capacity)
{
	num_of_wins = 0;
}


SportCar::~SportCar()
{
	//destructor
}

#pragma endregion

#pragma region Methods

void SportCar::newSportCar()
{
	newCar();
	num_of_wins = 0;
}

void SportCar::showSportCarInfo()
{
	showCarInfo();
	cout << "Number of won drag races: " << num_of_wins << "\n";
}

void SportCar::takePartInDragRace()
{
	srand(time(NULL));
	int lose = rand() % 6;
	cout << "You are taking part in a drag race!\n";
	Sleep(1000);
	if (lose)
	{
		if(lose = 1)
			cout << "You lost and ended on a " << lose+1 << "nd place\n";
		else if (lose = 2)
			cout << "You lost and ended on a " << lose + 1 << "rd place\n";
		else
			cout << "You lost and ended on a " << lose + 1 << "th place\n";
	}
	else
	{
		cout << "Congratulations! You have won!\n";
		num_of_wins++;
	}
}

#pragma endregion
