#include "pch.h"
#include "FamilyCar.h"
#include <conio.h>
#include <iostream>

using namespace std;

#pragma region Constructor and Destructor

FamilyCar::FamilyCar(string eng_type, int eng_power, float eng_capacity, int eng_torque, bool eng_run,
	string c_mark, string c_name, string c_colour, unsigned int c_max_speed, int c_min_speed, unsigned int c_acceleration,
	unsigned int c_deceleration, int c_actual_speed, unsigned int c_num_of_seats, float c_luggage_capacity, int fc_num_of_baby_seats)
	:Car(eng_type, eng_power, eng_capacity, eng_torque, eng_run, c_mark, c_name, c_colour, c_max_speed, c_min_speed, c_acceleration, c_deceleration,
		c_actual_speed, c_num_of_seats, c_luggage_capacity)
{
	num_of_baby_seats = fc_num_of_baby_seats;
}

FamilyCar::~FamilyCar()
{
	//destructor
}

#pragma endregion

#pragma region Setters

void FamilyCar::setNumOfBabySeats()
{
	bool correct = false;
	unsigned int car_num_of_seats = getNumOfSeats();
	system("cls");
	cout << "Enter car's number of baby seats: ";
	while (!correct || num_of_baby_seats > car_num_of_seats || num_of_baby_seats < 0)
	{
		cin >> num_of_baby_seats;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
			correct = false;
		}
		else
			correct = true;
	}
}

#pragma endregion

#pragma region Methods

void FamilyCar::newFamilyCar()
{
	newCar();
	setNumOfBabySeats();
}

void FamilyCar::familyTrip()
{
	int decision;
	system("cls");
	cout << "Where are we going?\n";
	cout << "1. Paris\n";
	cout << "2. Rome\n";
	cout << "3. Berlin\n";
	cout << "4. Warsaw\n";
	cout << "Choice: ";
	do
	{
		cin >> decision;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
	} while (decision < 1 || decision > 4 || cin.fail());
	cout << "We are going to ";
	switch (decision)
	{
	case 1:
		cout << "Paris\n";
		break;
	case 2:
		cout << "Rome\n";
		break;
	case 3:
		cout << "Berlin\n";
		break;
	case 4:
		cout << "Warsaw\n";
		break;
	default:
		cout << "Nowhere :c\n";
		break;
	}
	_getch();
}

void FamilyCar::showFamilyCarInfo()
{
	showCarInfo();
	cout << "Number of baby seats: " << num_of_baby_seats << "\n";
}

#pragma endregion