#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Headers.h"
#include "Chromosome.h"

class Controller
{
private:
	unsigned int maxPopulationSize;
	unsigned int crossoverRate;
	unsigned int mutationRate;
	unsigned int genesPerChromosome;
	unsigned int generation;
	vector<shared_ptr<Chromosome>> chromosomeContainer1;
	vector<shared_ptr<Chromosome>> chromosomeContainer2;

public:
	Controller(const unsigned int maxPopulationSize, 
		const unsigned int crossoverRate, 
		const unsigned int mutationRate, 
		const unsigned int genesPerChromosome,
		const int target);
	void start();
	void nextGeneration();
	void cleanupChromosomeContainer(vector<shared_ptr<Chromosome>> *chromosomeContainer);
};

#endif