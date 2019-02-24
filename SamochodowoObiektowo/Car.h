#pragma once
#include "pch.h"
#include "Engine.h"
#include <iostream>
#include <string>

using namespace std;

class Car
{

#pragma region Variables

private:
	Engine cars_engine; //silnik z klasy Engine
	string mark; //marka samochodu
	string name; //nazwa samochodu
	string colour; //kolor samochodu
	unsigned int max_speed; //maksymalna predkosc
	int min_speed; //minimalna predkosc
	unsigned int acceleration; //przyspieszenie pojazdu
	unsigned int deceleration; //zwalnianie pojazdu
	int actual_speed; //aktualna predkosc samochodu
	unsigned int num_of_seats; //ilosc siedzen
	float luggage_capacity; //pojemnosc bagaznika [L]
	//numer rejestracyjny?

#pragma endregion

#pragma region Getter

public:
	Engine getCarsEngine() { return cars_engine; } //zwraca silnik
	string getMark() { return mark; } //zwraca marke
	string getName() { return name; } //zwraca nazwe pojazdu
	string getColour() { return colour; } //zwraca kolor
	unsigned int getMaxSpeed() { return max_speed; } //zwraca maksymalna predkosc
	int getMinSpeed() { return min_speed; } //zwraca minimalna predkosc
	unsigned int getAcceleration() { return acceleration; } //zwraca przyspieszenie
	unsigned int getDeceleration() { return deceleration; } //zwraca wartosc spowolnienia 
	int getActualSpeed() { return actual_speed; } //zwraca aktualna predkosc
	unsigned int getNumOfSeats() { return num_of_seats; } //zwraca ilosc siedzen
	float getLuggageCapacity() { return luggage_capacity; } //zwraca pojemnosc bagaznika

#pragma endregion

#pragma region Setter

public:
	void setCarsEngine(); //ustawia silnik (korzystajac z newEngine())
	void setMark(); //ustawia marke samochodu
	void setName(); //ustawia nazwe
	void setColour(); //ustawia kolor
	void setMaxSpeed(); //ustawia maksymalna predkosc
	void setMinSpeed(); //ustawia minimalna predkosc
	void setAcceleration(); //ustawia przyspieszenie 
	void setDeceleration(); //ustawia spowolnienie
	void setActualSpeed(int c_actual_speed) { actual_speed = c_actual_speed; } //ustawia aktualna predkosc
	void setNumOfSeats(); //ustawia ilosc siedzen
	void setLuggageCapacity(); //ustawia pojemnosc bagaznika

#pragma endregion

#pragma region Constructor and Destructor

public:
	Car(string eng_type = NULL, int eng_power = NULL, float eng_capacity = NULL, int eng_torque = NULL, bool eng_run = 0, string c_mark = NULL,
		string c_name = NULL, string c_colour = NULL, unsigned int c_max_speed = 0, int c_min_speed = 0, unsigned int c_acceleration = 0,
		unsigned int c_deceleration = 0, int c_actual_speed = 0, unsigned int c_num_of_seats = 0, float c_luggage_capacity = 0); //konstruktor nr1
	~Car(); //destruktor

#pragma endregion

#pragma region Methods

public:
	void newCar(); //tworzy nowy samochod
	void showCarInfo(); //wyswietla informacje o samochodzie
	void changeColour(); //zmienia kolor samochodu
	void accelerate(); //przyspiesza
	void decelerate(); //zwalnia
	void breakCar() { setActualSpeed(0); } //zeruje predkosc
	void turnEngineOn() { cars_engine.setRun(true); } //uruchamia silnik
	void turnEngineOff() { cars_engine.setRun(false); } //wylacza silnik

#pragma endregion

};