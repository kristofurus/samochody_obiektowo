#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Engine
{

#pragma region Variables

	string type; //diesel, bensine, electrinc, hybrid
	int power; //moc w KM
	float capacity; //pojemnosc
	int torque; //moment obrotowy silnika
	bool run; // czy silnik uruchomiony

#pragma endregion

#pragma region Getters

public:
	string getType() { return type; } //zwraca wartosc typu silnika
	int getPower() { return power; } //zwraca wartosc mocy silnika
	float getCapacity() { return capacity; } //zwraca pojemnosc silnika
	int getTorque() { return torque; } //zwraca moment obrotowy
	bool getRun() { return run; } //zwraca czy uruchomiony

#pragma endregion

#pragma region Setters
public:
	void setType(); //ustawia typ silnika
	void setPower(); //ustawia moc silnika
	void setCapacity(); //ustawia pojemnosc silnika
	void setTorque(); //ustawia moment obrotowy silnika
	void setRun(bool b_run) { run = b_run; } //zmienia czy silnik uruchomiony czy nie

#pragma endregion

#pragma region Constructor and Destructor

public:
	Engine(string s_type = NULL, int i_power = NULL , float f_capacity = NULL , int i_torque = NULL, bool b_run = false); //konstruktor nr 1 (podany ze wszystkim)
	Engine(string s_type = NULL); //konstruktor nr 2 (podany tylko z typem silnika)
	Engine(); //konstruktor nr 3 (bez podanych zadnych danych)
	~Engine(); //destruktor (JEST ZAWSZE TYLKO 1)

#pragma endregion

#pragma region Functions

public:
	void turnEngineOn() { run = true; } //uruchamia silnik
	void turnEngineOff() { run = false; } //wylacza silnik
	void showEngineInfo(); //wyswietla informacje o silniku
	void newEngine(); //tworzy nowy silnik

#pragma endregion
};