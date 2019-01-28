#pragma once
#include "Ant.h"
#include "Graph.h"

class Global;

class AntColony
{
private:
	double PCFreq = 0.0;
	__int64 CounterStart = 0;

	void StartCounter();
	double GetCounter();



	std::vector<std::vector<double>> Phero;
	std::vector<int> bestSolution;
	std::vector<Ant> ants;
	std::vector<double>prob;

	double evapFactor;		//Wsp�czynnik odparowywania feromonu ze �cie�ki
	double alphaFactor;		//Wsp�czynnik wp�ywu pozostawionego feromonu na pr wyboru �cie�ki
	double betaFactor;		//Wsp�czynnik wp�ywu odleg�o�ci mi�dzy miastami na pr wyboru �cie�ki

	Graph * graph;
	int dimension;
	int colonySize;
	double pr = 0.01;
	int totalLength;
	int iteration;

	//Dzia�ania na mr�wkach
	void initAnts();
	void runAnt(int antIndex);
	void runAllAnts();
	void calculateProb(int antIndex);

	//Dzia�ania na poziomie feromonu
	void initializePhero();
	void fadePhero();
	void placePhero(std::vector<int> tour);

	int drawCity(int antIndex);


public:
	AntColony(Graph * _graph, Global * glo);
	~AntColony();

	int calcSolutionCost(const std::vector<int>& solutionToCalc);
	void startAlgorithm();
};

