#include "pch.h"
#include "Engine.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

#pragma region Constructors and Destructor

Engine::Engine(string type, int power, float capacity, int torque, bool run)
{
	this-> type = type;
	this-> power = power;
	this-> capacity = capacity;
	this-> torque = torque;
	this-> run = run;
}

Engine::Engine(string type)
{
	this-> type = type;
	power = 0;
	capacity = 0.0;
	torque = 0;
	run = 0;
}

Engine::Engine()
{
	type = " ";
	power = 0;
	capacity = 0.0;
	torque = 0;
	run = 0;
}

Engine::~Engine()
{
	//destruktor
}

#pragma endregion

#pragma region Setters

void Engine::setType()
{
	int decision;
	system("cls");
	cout << "Select engine type: \n";
	cout << "1. Diesel\n";
	cout << "2. Bensine\n";
	cout << "3. Electric\n";
	cout << "4. Hybrid\n";
	do
	{
	cin >> decision;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
	} while (decision < 1 || decision > 4 || cin.fail());
	switch (decision)
	{
	case 1:
		type = "diesel";
		break;
	case 2:
		type = "bensine";
		break;
	case 3:
		type = "electric";
		break;
	case 4:
		type = "hybrid";
		break;
	default:
		cout << "Wrong option!\n";
		break;
	}
}

void Engine::setPower()
{
	bool correct = false;
	system("cls");
	cout << "Enter engine's power: ";
	while (!correct)
	{
		cin >> power;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
		else
			correct = true;
	}
}

void Engine::setCapacity()
{
	bool correct = false;
	system("cls");
	cout << "Enter engine's capacity: ";
	while (!correct)
	{
		cin >> capacity;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
		else
			correct = true;
	}
}

void Engine::setTorque()
{
	bool correct = false;
	system("cls");
	cout << "Enter engine's torque: ";
	while (!correct)
	{
		cin >> torque;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
		else
			correct = true;
	}
}

#pragma endregion

#pragma region Methods

void Engine::showEngineInfo()
{
	cout << "ENGINE INFO:\n";
	cout << "Type: " << type << "\n";
	cout << "Power: " << power << "HP\n";
	cout << "Capacity: " << capacity << "L\n";
	cout << "Torque: " << torque << "Nm\n";
	cout << "Is on: " << run << "\n";
}

void Engine::newEngine()
{
	//ustawia typ silnika
	setType();
	//ustawia moc
	setPower();
	//ustawia pojemnosc
	setCapacity();
	//ustawia moment pedu
	setTorque();
	//ustawia czy silnik uruchomiony na falsz
	setRun(0);
}

#pragma endregion