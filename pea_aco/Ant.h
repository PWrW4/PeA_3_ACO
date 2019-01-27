#pragma once
#include <vector>

class Ant
{
	std::vector<int> currentOrder;
	std::vector<bool> visitedCities;

	int initialCity;
	int currentCity;
	int totalDistance;
	int dim;
public:
	Ant();
	Ant(int dimension, int initialCity);
	~Ant();

	void init();

	std::vector<int> getCurrentOrder() { return currentOrder; }
	int getCurrentCity() { return currentCity; }
	int getInitialCity() const { return initialCity; }

	int getTotalDistance() { return totalDistance; }
	bool visitedAllCities(int dimension) { return currentOrder.size() == dimension; }
	bool cityVisited(int city) { return visitedCities[city]; }

	void move(int city);
	void updateDistance(int distance) { this->totalDistance += distance; }
	void clear();
};

