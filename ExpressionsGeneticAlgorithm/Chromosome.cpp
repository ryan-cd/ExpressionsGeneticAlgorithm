#include "Chromosome.h"

Chromosome::Chromosome(unsigned int genesPerChromosome)
{
	string tempString = "";
	
	for (int i = 0; i < genesPerChromosome * 4; i++)
	{
		tempString += ((float)rand() / (float)RAND_MAX > 0.5) ? "0" : "1";
	}

	this->bitString = tempString;
	this->fitness = 0;
}

Chromosome::Chromosome(unsigned int genesPerChromosome, string bitString)
{
	this->bitString = bitString;
}

//getters
string Chromosome::getBitString()
{
	return this->bitString;
}

float Chromosome::getFitness()
{
	return this->fitness;
}

//setters
void Chromosome::setFitness(float newFitness)
{
	this->fitness = newFitness;
}
