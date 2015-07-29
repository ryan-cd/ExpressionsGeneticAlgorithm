#include "Controller.h"

Controller::Controller(const unsigned int maxPopulationSize, 
	float crossoverRate, 
	float mutationRate, 
	const float target)
{
	this->geneManager = make_shared<GeneManager>(target);
	this->maxPopulationSize = maxPopulationSize;
	this->crossoverRate = crossoverRate;
	this->mutationRate = mutationRate;

	this->genesPerChromosome = (*geneManager).getGenesPerChrm();
	this->geneLength = (*geneManager).getGeneLength();
	this->generatedTarget = make_shared<Chromosome>(this->genesPerChromosome, this->geneLength, "");
	this->generation = 0;
	
	//Chromosome chrm(9, "011010100101110001001101001010100001");
	//Chromosome chrm(this->genesPerChromosome, this->geneLength, "001001100000101110010111101110111111");
	//cout << (*geneManager).getFitness(chrm) << endl;
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
	//printContainer(&chrmContainer1);
	pair<int, int> chrmContainerIndexes = chooseChrms(&chrmContainer1);
	//cout << "\nfirst: " << chrmContainerIndexes.first << " second: " << chrmContainerIndexes.second;
	//cout << "\nnew chrm: " << (*geneManager).toExpressionString((*breedChrms(chrmContainer1[chrmContainerIndexes.first], chrmContainer1[chrmContainerIndexes.second])).getBitString());
	//cout << "\n mutating " << (*chrmContainer1[0]).getBitString() << "\n mutated: " << (*(mutateChrm(chrmContainer1[0]))).getBitString();
	//cout << "\n mutating " << (*geneManager).toExpressionString((*chrmContainer1[0]).getBitString()) << "\n mutated: " << (*geneManager).toExpressionString((*(mutateChrm(chrmContainer1[0]))).getBitString());

	
	container* currentContainer = &chrmContainer1;
	container* nextContainer = &chrmContainer2;
	shared_ptr<Chromosome> tempChromosome;
	
	
	while ((*this->generatedTarget).getBitString() == "")
	{
		cout << "\nGeneration: " << ++this->generation;
		while ((*nextContainer).size() < (*currentContainer).size())
		{
			do
			{
				chrmContainerIndexes = chooseChrms(currentContainer);
			} while ((float)rand() / (float)RAND_MAX > this->crossoverRate);
			tempChromosome = breedChrms(
				(*currentContainer)[chrmContainerIndexes.first],
				(*currentContainer)[chrmContainerIndexes.second]);

			if ((float)rand() / (float)RAND_MAX > this->mutationRate)
				tempChromosome = mutateChrm(tempChromosome);

			(*nextContainer).push_back(make_shared<Chromosome>(this->genesPerChromosome, this->geneLength, (*tempChromosome).getBitString()));
		}
		assignFitnesses(nextContainer);
		printContainer(nextContainer);

		(*currentContainer).clear();
		currentContainer = (currentContainer == &chrmContainer1) ? &chrmContainer2 : &chrmContainer1;
		nextContainer = (nextContainer == &chrmContainer1) ? &chrmContainer2 : &chrmContainer1;

		if (this->generation > 500)
			break;
	}
	//delete currentContainer;
	//delete nextContainer;

	return (*this->geneManager).toExpressionString((*this->generatedTarget).getBitString());
}

pair<int, int> Controller::chooseChrms(vector<shared_ptr<Chromosome>>* container)
{
	pair<int, int> returnValue{ -1, -1 };
	vector<float> roulette;
	float fitnessSum = 0;
	float wheelSpin1 = (float)rand() / (float)RAND_MAX;
	float wheelSpin2 = (float)rand() / (float)RAND_MAX;
	//cout << "\nwheel 1: " << wheelSpin1 << " wheel 2: " << wheelSpin2 << endl;
	
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
				//todo: make this check to see if the previous value is the same as the current
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

shared_ptr<Chromosome> Controller::breedChrms(shared_ptr<Chromosome> chromosome1, shared_ptr<Chromosome> chromosome2)
{
	//the crossover index guarantees at least one bit will be of chromosome 2
	int crossoverIndex = int(((float)rand() / (float)RAND_MAX) * (*chromosome1).getBitString().size() - 2);
	//cout << "\n Crossover index: " << crossoverIndex;
	
	shared_ptr<Chromosome> returnValue = make_shared<Chromosome>(this->genesPerChromosome, this->geneLength,
		(*chromosome1).getBitString().substr(0, crossoverIndex + 1) +
		(*chromosome2).getBitString().substr(crossoverIndex + 1, (*chromosome2).getBitString().size()));
	return returnValue;
}

shared_ptr<Chromosome> Controller::mutateChrm(shared_ptr<Chromosome> chromosome)
{
	string newBitString = (*chromosome).getBitString();

	for (int i = 0; i < (*chromosome).getBitString().size(); i++)
	{
		if ((float)rand() / (float)RAND_MAX <= 0.001)
		{
			newBitString[i] = newBitString[i] == '0' ? '1' : '0';
			//cout << "\n !!!mutation at " << i << endl;
		}
	}
	
	shared_ptr<Chromosome> returnValue = make_shared<Chromosome>(
		this->genesPerChromosome, this->geneLength, newBitString);

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

		if ((*(*chrmContainer)[i]).getFitness() == FLT_MAX)
			this->generatedTarget = make_shared<Chromosome>(this->genesPerChromosome, this->geneLength, (*(*chrmContainer)[i]).getBitString());
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





