#include "pch.h"
#include "Global.h"
#include <iostream>

using namespace std;

Global::Global()
{
}


Global::~Global()
{
}

void Global::Params()
{
	while (1)
	{
		int x = -1;
		std::cout << "Menu Parametrow\n\n"
			<< "1 - liczba iteracji: " << iterations << "\n"
			<< "2 - alpha: " << alpha << "\n"
			<< "3 - beta: " << beta << "\n"
			<< "4 - evaporate: " << evaporate << "\n"
			<< "0 - Powrot\n";

		std::cin >> x;

		switch (x)
		{
		case 1:
			{
				int _iterations;
				printf("> ");
				cin >> _iterations;
				iterations = _iterations;


				system("cls");
				break;
			}
		case 2:
			{
				float _alpha;
				printf("> ");
				cin >> _alpha;
				alpha = _alpha;


				system("cls");
				break;
			}
		case 3:
			{
				int _beta;
				printf("> ");
				cin >> _beta;
				beta = _beta;


				system("cls");
				break;
			}
		case 4:
			{
				float _evaporate;
				printf("> ");
				cin >> _evaporate;
				evaporate = _evaporate;


				system("cls");
				break;
			}
		case 0:
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
