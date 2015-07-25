#include "Controller.h"

Controller::Controller(const unsigned int maxPopulationSize, 
	const unsigned int crossoverRate, 
	const unsigned int mutationRate, 
	const float target)
{
	this->geneManager = make_shared<GeneManager>(target);
	this->maxPopulationSize = maxPopulationSize;
	this->crossoverRate = crossoverRate;
	this->mutationRate = mutationRate;

	this->genesPerChromosome = (*geneManager).getGenesPerChrm();
	this->geneLength = (*geneManager).getGeneLength();
	this->generation = 0;
	
	//Chromosome chrm(9, "011010100101110001001101001010100001");
	Chromosome chrm(this->genesPerChromosome, this->geneLength, "001001100000101110010111101110111111");
	cout << (*geneManager).getFitness(chrm);
}

void Controller::init()
{
	for (int i = 0; i < maxPopulationSize; i++)
	{
		chrmContainer1.push_back(make_shared<Chromosome>(this->genesPerChromosome, this->geneLength));
		chrmContainer2.push_back(make_shared<Chromosome>(this->genesPerChromosome, this->geneLength));
	}
}

string Controller::generateTarget()
{
	init();
	assignFitnesses(&chrmContainer1);
	printContainer(&chrmContainer1);
	return "Hello world!";
}

void Controller::printContainer(vector<shared_ptr<Chromosome>>* container)
{
	cout << "\nPrinting container";
	for (int i = 0; i < (*container).size(); i++)
	{
		cout << "expression: " << (*geneManager).toExpressionString((*(*container)[i]).getBitString());
		cout << " fitness: " << (*(*container)[i]).getFitness() << endl;
	}
}

void Controller::assignFitnesses(vector<shared_ptr<Chromosome>>* chrmContainer)
{
	for (int i = 0; i < (*chrmContainer).size(); i++)
	{
		(*(*chrmContainer)[i]).setFitness((*this->geneManager).getFitness((*(*chrmContainer)[i])));
	}
}

void Controller::createGeneration()
{
	cout << "\nGeneration " << ++generation << endl;
	/*
	if (generation % 2 != 0)
		cleanupChrmContainer(&chrmContainer1);
	else
		cleanupChrmContainer(&chrmContainer2);*/

	cout << "\n after length is " << chrmContainer1.size() << " length: " << chrmContainer2.size();
}





