#include "Controller.h"

Controller::Controller(const unsigned int initialPopulationSize, const unsigned int crossoverRate, const unsigned int mutationRate, const unsigned int genesPerChromosome)
{
	this->initialPopulationSize = initialPopulationSize;
	this->crossoverRate = crossoverRate;
	this->mutationRate = mutationRate;
	this->genesPerChromosome = genesPerChromosome;

}

void Controller::start()
{
	for (int i = 0; i < initialPopulationSize; i++)
	{
		chromosomeContainer1.push_back(new Chromosome(genesPerChromosome));
	}
}