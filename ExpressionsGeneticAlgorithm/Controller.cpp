#include "Controller.h"

Controller::Controller(const unsigned int maxPopulationSize, 
	const unsigned int crossoverRate, 
	const unsigned int mutationRate, 
	const unsigned int genesPerChromosome,
	const float target)
{
	this->maxPopulationSize = maxPopulationSize;
	this->crossoverRate = crossoverRate;
	this->mutationRate = mutationRate;
	this->genesPerChromosome = genesPerChromosome;
	this->generation = 0;
}

void Controller::init()
{
	for (int i = 0; i < maxPopulationSize; i++)
	{
		chrmContainer1.push_back(make_shared<Chromosome>(genesPerChromosome));
		chrmContainer2.push_back(make_shared<Chromosome>(genesPerChromosome));
	}
}

string Controller::generateTarget()
{
	init();

	return "Hello world!";
}

void assignFitnesses(vector<shared_ptr<Chromosome>>* chrmContainer)
{
	for (int i = 0; i < (*chrmContainer).size(); i++)
	{
		//float fitness = 1 / (this->target - );
		(*(*chrmContainer)[i]).setFitness(1);
	}
}

void Controller::createGeneration()
{
	cout << "\nGeneration " << ++generation << endl;

	if (generation % 2 != 0)
		cleanupChrmContainer(&chrmContainer1);
	else
		cleanupChrmContainer(&chrmContainer2);

	cout << "\n after length is " << chrmContainer1.size() << " length: " << chrmContainer2.size();
}

void Controller::cleanupChrmContainer(vector<shared_ptr<Chromosome>> *chrmContainer)
{
	/*for (int i = (*chrmContainer).size() - 1; i >= 0;  i--)
	{
		delete (*chrmContainer)[i];
		(*chrmContainer).erase((*chrmContainer).begin() + i);
	}*/
}



