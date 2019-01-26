#include "pch.h"
#include "Menu.h"
#include <ctime>
#include <iostream>
#include "AntColony.h"


using namespace std;

Menu::Menu()
{
	graph = new Graph(0);
	global = new Global();
	srand(unsigned int(time(NULL)));
}


Menu::~Menu()
{
	delete global;
	delete graph;
}





void Menu::IAmTheProgram()
{
	while (1)
	{
		MainMenu();
		char decision;
		do
		{
			printf("czy chcesz opuscic program? T/N\n");
			cout << "\n\n>";
			cin >> decision;
			if (decision == 'T' || decision == 't')
				return;
			else if (decision == 'N' || decision == 'n')
			{
				system("cls");
				break;
			}
			system("cls");
		} while (decision != 'T' || 't' || 'N' || 'n');
	}
}

void Menu::MainMenu()
{
	while (1)
	{
		printf("Projektowanie Efektywnych Algorytmow - Projekt\nZadanie projektowe nr 3\n\n");
		cout << "MENU glowne:\n"
			<< "1 - Testy manualne\n"
			<< "2 - Parametry\n"
			<< "3 - Graf\n"
			<< "4 - Zakoncz\n"
			<< endl;
		int x = 0;
		cout << "\n\n>";
		cin >> x;
		switch (x)
		{
		case 1:
			ManualTest();
			break;
		case 2:
			global->Params();
			break;
		case 3:
			GraphSetup();
			break;
		case 4:
			return;
		default:
			cout << "zly rozkaz sterujacy" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return;
}

void Menu::ManualTest()
{
	while (1)
	{
		system("cls");
		cout << "MENU Testow manualnych\n\n"
			<< "1 - Genetic Algorithm\n"
			<< "2 - Powrot\n"
			<< endl;
		cout << "\n\n>";
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			//AntColony* algorithm = new AntColony(*global, graph);
			// algorithm->Solve();
			// algorithm->PrintData();
			//delete algorithm;

			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			return;
		}
		default:
		{
			cout << "zly rozkaz sterujacy" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}

void Menu::GraphSetup()
{
	system("cls");

	while (1)
	{
		int from_file = -1, x = -1;

		system("cls");
		cout << "MENU Grafu\n\n"
			<< "wczytano graf: " << graph->name.c_str()
			<< "\n1 - Wczytaj\n"
			<< "2 - Wyswietl\n"
			<< "3 - Powrot\n"
			<< endl;
		cout << "\n\n>";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			graph->ReadGraph();
			system("cls");
			break;
		}
		case 2:
		{
			graph->PrintGraph();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			return;
		}
		default:
		{
			cout << "zly rozkaz sterujacy" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}

