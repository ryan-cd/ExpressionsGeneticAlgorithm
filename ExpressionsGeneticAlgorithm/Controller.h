#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Headers.h"
#include "Chromosome.h"
#include "GeneManager.h"

class Controller
{
private:
	shared_ptr<GeneManager> geneManager;
	unsigned int maxPopulationSize;
	unsigned int crossoverRate;
	unsigned int mutationRate;
	unsigned int genesPerChromosome;
	unsigned int geneLength;
	unsigned int generation;
	vector<shared_ptr<Chromosome>> chrmContainer1;
	vector<shared_ptr<Chromosome>> chrmContainer2;

	void init();
	void assignFitnesses(vector<shared_ptr<Chromosome>>* chrmContainer);
	pair<int, int> chooseChrms(vector<shared_ptr<Chromosome>>* container);
	shared_ptr<Chromosome> breedChrms(shared_ptr<Chromosome> chromosome1, shared_ptr<Chromosome> chromosome2);
	shared_ptr<Chromosome> mutateChrm(shared_ptr<Chromosome> chromosome);
	void createGeneration();

public:
	Controller(const unsigned int maxPopulationSize, 
		const unsigned int crossoverRate, 
		const unsigned int mutationRate, 
		const float target);
	
	string generateTarget();
	void printContainer(vector<shared_ptr<Chromosome>>* container);
};

#endif