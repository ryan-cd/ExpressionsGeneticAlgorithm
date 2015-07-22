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
	vector<shared_ptr<Chromosome>> chrmContainer1;
	vector<shared_ptr<Chromosome>> chrmContainer2;

	void init();
	void assignFitnesses(vector<shared_ptr<Chromosome>>* chrmContainer);
	vector<int> chrmsToBreed();
	void mutateChrm(shared_ptr<Chromosome> chromosome);
	void createGeneration();
	void cleanupChrmContainer(vector<shared_ptr<Chromosome>>* chrmContainer);

public:
	Controller(const unsigned int maxPopulationSize, 
		const unsigned int crossoverRate, 
		const unsigned int mutationRate, 
		const unsigned int genesPerChromosome,
		const float target);
	
	string generateTarget();
	
};

#endif