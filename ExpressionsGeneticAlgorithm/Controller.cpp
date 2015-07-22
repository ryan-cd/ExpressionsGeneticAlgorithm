#include "Controller.h"

Controller::Controller(const unsigned int maxPopulationSize, 
	const unsigned int crossoverRate, 
	const unsigned int mutationRate, 
	const unsigned int genesPerChromosome,
	const int target)
{
	this->maxPopulationSize = maxPopulationSize;
	this->crossoverRate = crossoverRate;
	this->mutationRate = mutationRate;
	this->genesPerChromosome = genesPerChromosome;
	this->generation = 0;
}

void Controller::start()
{
	for (int i = 0; i < maxPopulationSize; i++)
	{
		chromosomeContainer1.push_back(make_shared<Chromosome>(genesPerChromosome));
		chromosomeContainer2.push_back(make_shared<Chromosome>(genesPerChromosome));
	}

	cout << "\n initial length " << chromosomeContainer1.size() << "~~" << (*chromosomeContainer1[0]).getBitString();
	for (int i = 0; i < 10; i++)
		nextGeneration();
}

void Controller::nextGeneration()
{
	cout << "\nGeneration " << ++generation << endl;

	if (generation % 2 != 0)
		cleanupChromosomeContainer(&chromosomeContainer1);
	else
		cleanupChromosomeContainer(&chromosomeContainer2);

	cout << "\n after length is " << chromosomeContainer1.size() << " length: " << chromosomeContainer2.size();
}

void Controller::cleanupChromosomeContainer(vector<shared_ptr<Chromosome>> *chromosomeContainer)
{
	/*for (int i = (*chromosomeContainer).size() - 1; i >= 0;  i--)
	{
		delete (*chromosomeContainer)[i];
		(*chromosomeContainer).erase((*chromosomeContainer).begin() + i);
	}*/
}

