#pragma once
class Global
{
public:

	double alpha = 1;
	double beta = 2;
	int iterations = 100;
	double evaporate = 0.7;
	int colonySize = 1;

	Global();
	~Global();

	void Params();
};

