#include "pch.h"
#include "Ant.h"


Ant::Ant(int dimension, int initialCity)
{
	this->initialCity = initialCity;
	this->currentCity = initialCity;

	visitedCities.resize(dimension);
	for (int i = 0; i < dimension; i++) visitedCities[i] = false;

	currentOrder.push_back(initialCity);

	visitedCities[currentCity] = true;
}


Ant::~Ant()
{
}

Ant::Ant()
{
}

void Ant::move(int city)
{
	currentCity = city;
	currentOrder.push_back(currentCity);
	visitedCities[city] = true;

}

void Ant::clear()
{
	for (int i = 0; i < visitedCities.size(); i++) visitedCities[i] = false;
	currentOrder.clear();
}

