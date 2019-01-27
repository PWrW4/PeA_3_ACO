#include "pch.h"
#include "Ant.h"


Ant::Ant(int dimension, int initialCity)
{
	this->initialCity = initialCity;
	this->currentCity = initialCity;
	this->dim = dimension;

	visitedCities.resize(dimension);
	for (int i = 0; i < dimension; i++) visitedCities[i] = false;

	currentOrder.push_back(initialCity);

	visitedCities[currentCity] = true;
}




Ant::~Ant()
{
}

void Ant::init()
{

	currentCity = initialCity;
	visitedCities.resize(dim);
	for (int i = 0; i < dim; i++) visitedCities[i] = false;

	currentOrder.push_back(initialCity);

	visitedCities[currentCity] = true;
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
	currentOrder.clear();
	initialCity = rand() % dim;
	init();
}

