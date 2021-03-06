#include "pch.h"
#include "Car.h"
#include "Engine.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

#pragma region Constructor and Destructor

Car::Car(string eng_type, int eng_power, float eng_capacity, int eng_torque, bool eng_run, string mark, string name, string colour, unsigned int max_speed,
int min_speed, unsigned int acceleration, unsigned int deceleration, int actual_speed, unsigned int num_of_seats, float luggage_capacity)
	:cars_engine(eng_type, eng_power, eng_capacity, eng_torque, eng_run)
{
	this -> mark = mark;
	this-> name = name;
	this-> colour = colour;
	this-> max_speed = max_speed;
	this-> min_speed = min_speed;
	this-> acceleration = acceleration;
	this-> deceleration = deceleration;
	this-> actual_speed = actual_speed;
	this-> num_of_seats = num_of_seats;
	this-> luggage_capacity = luggage_capacity;
}

Car::~Car()
{
	//destructor
}

#pragma endregion

#pragma region Setters

void Car::setCarsEngine()
{
	Engine eng("", 0, 0, 0, 0);
	eng.newEngine();
	cars_engine = eng;
}

void Car::setMark()
{
	system("cls");
	cout << "Enter car's mark: ";
	cin >> mark;
}

void Car::setName()
{
	system("cls");
	cout << "Enter car's name: ";
	cin >> name;
}

void Car::setColour()
{
	system("cls");
	cout << "Enter car's colour: ";
	cin >> colour;
}

void Car::setMaxSpeed()
{
	bool correct = false;
	system("cls");
	cout << "Enter car's max speed: ";
	while (!correct || max_speed <= min_speed || max_speed <= 0)
	{
		cin >> max_speed;
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

void Car::setMinSpeed()
{
	bool correct = false;
	system("cls");
	cout << "Enter car's min speed: ";
	while (!correct || min_speed >= max_speed)
	{
		cin >> min_speed;
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

void Car::setAcceleration()
{
	bool correct = false;
	system("cls");
	cout << "Enter car's acceleration: ";
	while (!correct)
	{
		cin >> acceleration;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
		else
			correct = true;
	}
}

void Car::setDeceleration()
{
	bool correct = false;
	system("cls");
	cout << "Enter car's deceleration: ";
	while (!correct)
	{
		cin >> deceleration;
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

void Car::setNumOfSeats()
{
	bool correct = false;
	system("cls");
	cout << "Enter car's number of seats: ";
	while (!correct)
	{
		cin >> num_of_seats;
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

void Car::setLuggageCapacity()
{
	bool correct = false;
	system("cls");
	cout << "Enter car's luggage capacity: ";
	while (!correct)
	{
		cin >> luggage_capacity;
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

void Car::newCar()
{
	//tworzenie silnika
	setCarsEngine();
	//nadanie marki
	setMark();
	//podanie nazwy
	setName();
	//ustawienie koloru
	setColour();
	//ustawienie predkosci maksymalnej
	min_speed = 0;
	setMaxSpeed();
	//ustawienie predkosci minimalnej
	setMinSpeed();
	//ustawienie przyspieszenia
	setAcceleration();
	//ustawienie spowolnienia
	setDeceleration();
	//ustawienie aktualnej predkosci na 0
	setActualSpeed(0);
	//ustawienie liczby miejsc
	setNumOfSeats();
	//ustawienie pojemnosci bagaznika
	setLuggageCapacity();
}

void Car::showCarInfo()
{
	system("cls");
	cars_engine.showEngineInfo();
	cout << "CAR INFO\n";
	cout << "Mark: " << mark << "\n";
	cout << "Name: " << name << "\n";
	cout << "Colour: " << colour << "\n";
	cout << "Max speed: " << max_speed << "km/h\n";
	cout << "Min speed: " << min_speed << "km/h\n";
	cout << "Acceleration: " << acceleration << "km/h\n";
	cout << "Deceleration: " << deceleration << "km/h\n";
	cout << "Number of seats: " << num_of_seats << "\n";
	cout << "Luggage capacity: " << luggage_capacity << "L\n";
}

void Car::changeColour()
{
	string new_colour;
	system("cls");
	cout << "Enter new colour: ";
	cin >> new_colour;
	colour = new_colour;
}

void Car::accelerate()
{
	bool run = cars_engine.getRun();
	if (run)
	{
		if (actual_speed + acceleration < max_speed)
			actual_speed += acceleration;
		else
			actual_speed = max_speed;
	}
	else
	{
		system("cls");
		cout << "You must turn engine on first!\n";
	}
}

void Car::decelerate()
{
	bool run = cars_engine.getRun();
	if (run)
	{
		if (actual_speed - deceleration > min_speed)
			actual_speed -= deceleration;
		else
			actual_speed = min_speed;
	}
	else
	{
		system("cls");
		cout << "You must turn engine on first!\n";
	}
}

#pragma endregion
