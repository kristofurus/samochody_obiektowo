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

//!odpowiada za wybranie opcji z glownego menu
int mainMenu()
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

//!odpowiada za wybranie samochodu do edycji
int editCar()
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
	//!glowne vectory do przechowywania podanych przez uzytkownika danych
	//! \param cars sport_cars family_cars
	vector <Car> cars;
	vector <SportCar> sport_cars;
	vector <FamilyCar> family_cars;
	//vectory do chwilowego przechowywania danych przy edycji elementow wewnatrz vectora glownego
	vector <Car> tmp_cars_vector;
	vector <SportCar> tmp_sport_cars_vector;
	vector <FamilyCar> tmp_family_cars_vector;

	int decision; //do wyboru w glownym menu
	int edit_option; //do wyboru typu samochodu do edycji
	int car_edit_number; //do wyboru numeru samochodu do edycji

	//chwilowe zmienne klasowe umozliwiajace tworzenie i edycje elementow znajdujacych sie w odpowiednich vecorach
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
			//tworzenie nowego samochodu
			car_tmp.newCar();
			cars.push_back(car_tmp);
			break;
		case 2:
			//tworzenie nowego samochodu sportowego
			sport_car_tmp.newSportCar();
			sport_cars.push_back(sport_car_tmp);
			break;
		case 3:
			//tworzenie nowego samochodu rodzinnego
			family_car_tmp.newFamilyCar();
			family_cars.push_back(family_car_tmp);
			break;
		case 4:
			//wyswietlanie pelnych infomacji o ostatnio stworzonym samochodzie 
			if (cars.size())
			{
				car_tmp = cars[cars.size() - 1];
				car_tmp.showCarInfo();
			}
			else
				cout << "Add some cars first!\n";
			break;
		case 5:
			//wyswietlanie pelnych infomacji o ostatnio stworzonym samochodzie sportowym
			if (sport_cars.size())
			{
				sport_car_tmp = sport_cars[sport_cars.size()-1];
				sport_car_tmp.showSportCarInfo();
			}
			else
				cout << "Add some sport cars first!\n";
			break;
		case 6:
			//wyswietlanie pelnych infomacji o ostatnio stworzonym samochodzie rodzinnym
			if (family_cars.size())
			{
				family_car_tmp = family_cars[family_cars.size() - 1];
				family_car_tmp.showFamilyCarInfo();
			}
			else
				cout << "Add some family cars first!\n";
			break;
		case 7:
			//edycja wybranego samochodu
			switch (edit_option = editCar())
			{
			case 0:
				break;
			case 1:
				//wybranie i edycja odpowiedniego elementu z vectora
				cout << "Choose car number from: 1 to  " << cars.size() << "\n";
				cout << "Choice: ";
				cin >> car_edit_number;
				car_tmp = cars[car_edit_number - 1];
				car_tmp.newCar();
				//przepisywanie elementow od pierwszego do edytowanego do chwilowego vectora
				for (int i = 0; i < car_edit_number - 1; i++)
				{
					tmp_cars_vector.push_back(cars[i]);
				}
				//przepisanie do chwilowego vectora edytowanego elementu
				tmp_cars_vector.push_back(car_tmp);
				//przepisywanie wszystkich elementow z chwilowego vectora do glownego
				for (unsigned int i = car_edit_number; i < cars.size(); i++)
				{
					tmp_cars_vector.push_back(cars[i]);
				}
				//czyszczenie glownego vectora
				cars.clear();
				//przepisywanie wszystkich elementow z chwilowego vectora do glownego
				for (unsigned int i = 0; i < tmp_cars_vector.size(); i++)
				{
					cars.push_back(tmp_cars_vector[i]);
				}
				//czyszczenie chwilowego vectora
				tmp_cars_vector.clear();
				break;
			case 2:
				//wybranie i edycja odpowiedniego elementu z vectora
				cout << "Choose sport car number from: 1 to  " << sport_cars.size() << "\n";
				cout << "Choice: ";
				cin >> car_edit_number;
				sport_car_tmp = sport_cars[car_edit_number - 1];
				sport_car_tmp.newSportCar();
				//przepisywanie elementow od pierwszego do edytowanego do chwilowego vectora
				for (int i = 0; i < car_edit_number - 1; i++)
				{
					tmp_sport_cars_vector.push_back(sport_cars[i]);
				}
				//przepisanie do chwilowego vectora edytowanego elementu
				tmp_sport_cars_vector.push_back(sport_car_tmp);
				//przepisywanie elementow od edytowanego do ostatniego z glownego vectora do chwilowego vectora
				for (unsigned int i = car_edit_number; i < sport_cars.size(); i++)
				{
					tmp_sport_cars_vector.push_back(sport_cars[i]);
				}
				//czyszczenie glownego vectora
				sport_cars.clear();
				//przepisywanie wszystkich elementow z chwilowego vectora do glownego
				for (unsigned int i = 0; i < tmp_sport_cars_vector.size(); i++)
				{
					sport_cars.push_back(tmp_sport_cars_vector[i]);
				}
				//czyszczenie chwilowego vectora
				tmp_sport_cars_vector.clear();
				break;
			case 3:
				//wybranie i edycja odpowiedniego elementu z vectora
				cout << "Choose sport car number from: 1 to  " << family_cars.size() << "\n";
				cout << "Choice: ";
				cin >> car_edit_number;
				family_car_tmp = family_cars[car_edit_number - 1];
				family_car_tmp.newFamilyCar();
				//przepisywanie elementow od pierwszego do edytowanego do chwilowego vectora
				for (int i = 0; i < car_edit_number - 1; i++)
				{
					tmp_family_cars_vector.push_back(family_cars[i]);
				}
				//przepisanie do chwilowego vectora edytowanego elementu
				tmp_family_cars_vector.push_back(family_car_tmp);
				//przepisywanie wszystkich elementow z chwilowego vectora do glownego
				for (unsigned int i = car_edit_number; i < family_cars.size(); i++)
				{
					tmp_family_cars_vector.push_back(family_cars[i]);
				}
				//czyszczenie glownego vectora
				family_cars.clear();
				//przepisywanie wszystkich elementow z chwilowego vectora do glownego
				for (unsigned int i = 0; i < tmp_family_cars_vector.size(); i++)
				{
					family_cars.push_back(tmp_family_cars_vector[i]);
				}
				//czyszczenie chwilowego vectora
				tmp_family_cars_vector.clear();
				break;
			default:
				cout << "Something went wrong!\n";
				break;
			}
			break;
		case 8:
			//wyswietlanie marki i nazwy wszystkich utworzonych samochodow
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