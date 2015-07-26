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
	cout << (*geneManager).getFitness(chrm) << endl;
}

void Controller::init()
{
	for (int i = 0; i < maxPopulationSize; i++)
	{
		chrmContainer1.push_back(make_shared<Chromosome>(this->genesPerChromosome, this->geneLength));
	}
}

string Controller::generateTarget()
{
	init();
	assignFitnesses(&chrmContainer1);
	printContainer(&chrmContainer1);
	pair<int, int> chrmContainerIndexes = chooseChrms(&chrmContainer1);
	cout << "\nfirst: " << chrmContainerIndexes.first << " second: " << chrmContainerIndexes.second;
	return "Hello world!";
}

pair<int, int> Controller::chooseChrms(vector<shared_ptr<Chromosome>>* container)
{
	pair<int, int> returnValue{ -1, -1 };
	vector<float> roulette;
	float fitnessSum = 0;
	float wheelSpin1 = (float)rand() / (float)RAND_MAX;
	float wheelSpin2 = (float)rand() / (float)RAND_MAX;
	cout << "\nwheel 1: " << wheelSpin1 << " wheel 2: " << wheelSpin2 << endl;
	
	//calculate fitness sum
	for (int i = 0; i < (*container).size(); i++)
	{
		fitnessSum += (*(*container)[i]).getFitness();
	}

	//fill the roulette wheel, and set the return values as it is getting filled
	for (int i = 0; i < (*container).size(); i++)
	{
		roulette.push_back((*(*container)[i]).getFitness() / fitnessSum);
		if (i > 0)
			roulette[i] += roulette[i - 1];

		if (wheelSpin1 < roulette[i] && returnValue.first == -1)
		{
			returnValue.first = i;
			if (i < (*container).size() - 1)
				continue;
			else 
			{
				//todo: makee this check to see if the previous value is the same as the current
				//if so, this section currently would pick a chrm with fitness = 0
				returnValue.second = i - 1;
			}
		}

		if (wheelSpin2 < roulette[i] && returnValue.second == -1)
			returnValue.second = i;

		if (returnValue.first != -1 && returnValue.second != -1)
			break;
	}
	return returnValue;
}

void Controller::printContainer(vector<shared_ptr<Chromosome>>* container)
{
	cout << "\nPrinting container\n";
	for (int i = 0; i < (*container).size(); i++)
	{
		cout << "Index: " << i << " ";
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





