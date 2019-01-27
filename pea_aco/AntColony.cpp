#include "pch.h"
#include <math.h>
#include <random>
#include "AntColony.h"
#include "Ant.h"
#include "Global.h"
#include <iostream>


double fRand(double fMin, double fMax)
{
	double lower_bound = fMin;
	double upper_bound = fMax;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;
	double a_random_double = unif(re);
	return a_random_double;
}

AntColony::AntColony(Graph * _graph, Global * glo)
{
	this->graph = _graph;
	dimension = graph->MatrixSize;
	prob.resize(dimension);
	Phero.assign(dimension, std::vector<double>(dimension));
	totalLength = INT_MAX;
	colonySize = dimension;

	this->alphaFactor = glo->alpha;
	this->betaFactor = glo->beta;
	this->iteration = glo->iterations;
	this->evapFactor = glo->evaporate;

	initializePhero();
	initAnts();
}

AntColony::~AntColony()
{
}

int AntColony::calcSolutionCost(const std::vector<int>& solutionToCalc)
{
	int cost = 0;

	for (int i = 0; i < dimension; ++i)
	{
		if (i == dimension - 1)
		{
			cost += graph->CityMatrix[solutionToCalc[i]][solutionToCalc[0]];
		}
		else
		{
			cost += graph->CityMatrix[solutionToCalc[i]][solutionToCalc[i + 1]];
		}
	}

	return cost;
}

void AntColony::initializePhero()
{
	for (int i = 0; i < Phero.size(); i++)
	{
		for (int j = 0; j < Phero[i].size(); j++)
		{
			Phero[i][j] = 0.5;
		}
	}
}

void AntColony::fadePhero()
{
	for (int i = 0; i < Phero.size(); i++)
	{
		for (int j = 0; j < Phero[i].size(); j++)
		{
			Phero[i][j] *= (evapFactor);
		}
	}
}

void AntColony::placePhero(std::vector<int>tour)
{
	int src = tour[0];
	int dst;
	for (int i = tour.size() - 1; i >= 0; i--)
	{
		dst = src;
		src = tour[i];
		Phero[src][dst] += (1.0 / graph->CityMatrix[src][dst]);
	}
}

void AntColony::initAnts()
{
	ants.resize(colonySize);
	for (int i = 0; i < ants.size(); i++)
	{
		Ant ant(dimension, rand() % dimension);
		ants[i] = ant;
	}

}

void AntColony::runAnt(int antIndex)
{
	int currentCity;

	while (!ants[antIndex].visitedAllCities(dimension))
	{
		currentCity = ants[antIndex].getCurrentCity();
		int city = drawCity(antIndex);

		ants[antIndex].move(city);
		ants[antIndex].updateDistance(graph->CityMatrix[currentCity][city]);
	}

	currentCity = ants[antIndex].getCurrentCity();
	int initialCity = ants[antIndex].getInitialCity();

	ants[antIndex].move(initialCity);
	ants[antIndex].updateDistance(graph->CityMatrix[currentCity][initialCity]);

	placePhero(ants[antIndex].getCurrentOrder());

	if (totalLength > ants[antIndex].getTotalDistance())
	{
		bestSolution = ants[antIndex].getCurrentOrder();
		totalLength = ants[antIndex].getTotalDistance();

		std::cout << totalLength<<std::endl;
	}

	ants[antIndex].clear();
	fadePhero();
}

void AntColony::runAllAnts()
{
	for (int i = 0; i < ants.size(); i++)
	{
		runAnt(i);
	}
}


int AntColony::drawCity(int antIndex)
{
	//Ca�kowicie losowy wyb�r �cie�ki
	if (fRand(0.001, 0.5) < pr)
	{
		int randomCity = rand() % (dimension);
		int index = -1;
		for (int i = 0; i < dimension; i++)
		{
			if (!ants[antIndex].cityVisited(i)) index++;
			if (index == randomCity) return index;
		}
	}

	calculateProb(antIndex);

	double boundary = fRand(0.4, 1.0);
	while (true)
	{
		int index = (rand() % dimension);
		double probs = prob[index];
		if (probs >= boundary) return index;

		if (probs != 0.0)
		{
			prob[index] += 0.2;
			probs = prob[index];
		}
	}

}

void AntColony::calculateProb(int antIndex)
{
	int currentCity = ants[antIndex].getCurrentCity();

	double denom = 0.0;
	double denom_tmp = 0.0;
	for (int i = 0; i < dimension; i++)
	{
		if (!ants[antIndex].cityVisited(i))
		{
			denom_tmp = pow(Phero[currentCity][i], alphaFactor);
			denom_tmp *= pow(1.0 / (double)graph->CityMatrix[currentCity][i], betaFactor);
			denom += denom_tmp;
		}
	}

	for (int i = 0; i < dimension; i++)
	{
		if (ants[antIndex].cityVisited(i)) prob[i] = 0.0;
		else
		{
			double numerator = pow(Phero[currentCity][i], alphaFactor) * pow(1.0 / (double)graph->CityMatrix[currentCity][i], betaFactor);
			prob[i] = numerator / denom;
		}
	}
}

void AntColony::startAlgorithm()
{

	int count = 0;
	while (count < iteration)
	{
		runAllAnts();
		count++;
	}

	std::cout << "Cost of route: " << calcSolutionCost(bestSolution) << std::endl;


	for (int i = 0; i < dimension; i++)
	{
		if (i == dimension - 1)
		{
			std::cout << bestSolution[i] << std::endl;
		}
		else
		{
			std::cout << bestSolution[i] << " -> ";
		}
	}
}
