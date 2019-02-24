#include "pch.h"
#include "Engine.h"
#include "Car.h"
#include "SportCar.h"
#include "FamilyCar.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

/* TODO
1. Klasa Samochod (DONE)
2. Podklasy samochodu <- dziedziczenie
2.1. Sportowy (DONE)
2.2. Rodzinny (DONE)
2.3. Rolniczy?
2.4. Specjalne <- to chyba bedzie fajne na polimorfizm (if i remember correctly)
2.4.1. Ambulans
2.4.2. Straz pozarna
2.4.3. Policja
3. Klasa silnik (DONE)
4. Klasa kierowca? (imie, nazwisko, nr tel, pesel) <- moze friend z tego sie da zrobic (przypisanie samochodu do osoby za pomoca tablicy rejestracyjnej?)
zaraz w takim razie sie z tego jeszcze baza danych zrobi normalnie XD baza silnikow do wyboru przy tworzeniu samochodow i cala baza kierowcow i samochodow
i ich laczenie (az sie zadanie na Accessa przypomina)
*/

int mainMenu() //odpowiada za wybranie opcji z glownego menu
{
	int decision;
	cout << "MAIN MENU\n";
	cout << "0. Exit\n";
	cout << "1. Create new car\n";
	cout << "2. Create new sport car\n";
	cout << "3. Create new family car\n";
	cout << "4. Show last added car info\n";
	cout << "5. Show last added sport car info\n";
	cout << "6. Show last added family car info\n";
	cout << "7. Edit car\n";
	cout << "8. Show all cars\n";
	cout << "Choice: ";
	do
	{
		cin >> decision;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
	} while (cin.fail() || decision < 0 || decision > 8);
	return decision;
}

int editCar() //odpowiada za wybranie samochodu do edycji
{
	int decision;
	cout << "Choose car:\n";
	cout << "0. Return\n1. Car\n2. Sport car\n3. Family car\n";
	cout << "Choice: ";
	do
	{
		cin >> decision;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20000, '\n');
		}
	} while (cin.fail() || decision < 0 || decision > 3);
	return decision;
}

int main()
{	
	vector <Car> cars;
	vector <SportCar> sport_cars;
	vector <FamilyCar> family_cars;

	vector <Car> tmp_cars_vector;
	vector <SportCar> tmp_sport_cars_vector;
	vector <FamilyCar> tmp_family_cars_vector;

	int decision; //do wyboru w glownym menu
	int edit_option; //do wyboru typu samochodu do edycji
	int car_edit_number; //do wyboru numeru samochodu do edycji

	Car car_tmp("", 0, 0.0, 0, false, "", "", "", 0, 0, 0, 0, 0, 0, 0.0);
	SportCar sport_car_tmp("", 0, 0.0, 0, false, "", "", "", 0, 0, 0, 0, 0, 0, 0.0);
	FamilyCar family_car_tmp("", 0, 0.0, 0, false, "", "", "", 0, 0, 0, 0, 0, 0, 0.0);
	Engine engine_tmp("", 0, 0, 0, true);

	while (decision = mainMenu())
	{
		system("cls");
		switch (decision)
		{
		case 1:
			car_tmp.newCar();
			cars.push_back(car_tmp);
			break;
		case 2:
			sport_car_tmp.newSportCar();
			sport_cars.push_back(sport_car_tmp);
			break;
		case 3:
			family_car_tmp.newFamilyCar();
			family_cars.push_back(family_car_tmp);
			break;
		case 4:
			car_tmp = cars[sport_cars.size() - 1];
			car_tmp.showCarInfo();
		case 5:
			sport_car_tmp = sport_cars[sport_cars.size()-1];
			sport_car_tmp.showSportCarInfo();
			break;
		case 6:
			family_car_tmp = family_cars[family_cars.size() - 1];
			family_car_tmp.showFamilyCarInfo();
			break;
		case 7:
			switch (edit_option = editCar())
			{
			case 0:
				break;
			case 1:
				cout << "Choose car number from: 1 to  " << cars.size() << "\n";
				cout << "Choice: ";
				cin >> car_edit_number;
				car_tmp = cars[car_edit_number - 1];
				car_tmp.newCar();
				for (int i = 0; i < car_edit_number - 1; i++)
				{
					tmp_cars_vector.push_back(cars[i]);
				}
				tmp_cars_vector.push_back(car_tmp);
				for (unsigned int i = car_edit_number; i < cars.size(); i++)
				{
					tmp_cars_vector.push_back(cars[i]);
				}
				cars.clear();
				for (unsigned int i = 0; i < tmp_cars_vector.size(); i++)
				{
					cars.push_back(tmp_cars_vector[i]);
				}
				break;
			case 2:
				cout << "Choose sport car number from: 1 to  " << sport_cars.size() << "\n";
				cout << "Choice: ";
				cin >> car_edit_number;
				sport_car_tmp = sport_cars[car_edit_number - 1];
				sport_car_tmp.newSportCar();
				for (int i = 0; i < car_edit_number - 1; i++)
				{
					tmp_sport_cars_vector.push_back(sport_cars[i]);
				}
				tmp_sport_cars_vector.push_back(sport_car_tmp);
				for (unsigned int i = car_edit_number; i < sport_cars.size(); i++)
				{
					tmp_sport_cars_vector.push_back(sport_cars[i]);
				}
				sport_cars.clear();
				for (unsigned int i = 0; i < tmp_sport_cars_vector.size(); i++)
				{
					sport_cars.push_back(tmp_sport_cars_vector[i]);
				}
				break;
			case 3:
				cout << "Choose sport car number from: 1 to  " << family_cars.size() << "\n";
				cout << "Choice: ";
				cin >> car_edit_number;
				family_car_tmp = family_cars[car_edit_number - 1];
				family_car_tmp.newFamilyCar();
				for (int i = 0; i < car_edit_number - 1; i++)
				{
					tmp_family_cars_vector.push_back(family_cars[i]);
				}
				tmp_family_cars_vector.push_back(family_car_tmp);
				for (unsigned int i = car_edit_number; i < family_cars.size(); i++)
				{
					tmp_family_cars_vector.push_back(family_cars[i]);
				}
				family_cars.clear();
				for (unsigned int i = 0; i < tmp_family_cars_vector.size(); i++)
				{
					family_cars.push_back(tmp_family_cars_vector[i]);
				}
				break;
			default:
				cout << "Something went wrong!\n";
				break;
			}
			break;
		case 8:
			cout << "Cars:\n";
			for (int i = 0; i < cars.size(); i++)
			{
				car_tmp = cars[i];
				cout << "\t" << i + 1 << ". " << car_tmp.getMark() << " " << car_tmp.getName() << "\n";
			}
			cout << "Sport cars:\n";
			for (int i = 0; i < sport_cars.size(); i++)
			{
				sport_car_tmp = sport_cars[i];
				cout << "\t" << i + 1 << ". " << sport_car_tmp.getMark() << " " << sport_car_tmp.getName() << "\n";
			}
			cout << "Family cars:\n";
			for (int i = 0; i < family_cars.size(); i++)
			{
				family_car_tmp = family_cars[i];
				cout << "\t" << i + 1 << ". " << family_car_tmp.getMark() << " " << family_car_tmp.getName() << "\n";
			}
			break;
		default:
			cout << "Something went wrong!\n";
			break;
		}
	}
	cout << "Goodbye!\n";
}