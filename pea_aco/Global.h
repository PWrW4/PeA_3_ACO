#pragma once
class Global
{
public:

	double alpha = 1;
	double beta = 2;
	int iterations = 100;
	double evaporate = 0.7;

	Global();
	~Global();

	void Params();
};

