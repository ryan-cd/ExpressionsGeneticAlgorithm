#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Headers.h"
#include "Chromosome.h"

class Controller
{
private:
	unsigned int initialPopulationSize;
	unsigned int crossoverRate;
	unsigned int mutationRate;
	unsigned int genesPerChromosome;
	vector<Chromosome *> chromosomeContainer1;
	vector<Chromosome *> chromosomeContainer2;

public:
	Controller(const unsigned int initialPopulationSize, const unsigned int crossoverRate, const unsigned int mutationRate, const unsigned int genesPerChromosome);
	void start();
};

#endif