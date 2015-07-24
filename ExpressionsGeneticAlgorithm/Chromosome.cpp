#include "Chromosome.h"

Chromosome::Chromosome(unsigned int genesPerChromosome)
{
	string tempString = "";
	
	for (int i = 0; i < genesPerChromosome * 4; i++)
	{
		tempString += ((float)rand() / (float)RAND_MAX > 0.5) ? "0" : "1";
	}

	this->bitString = tempString;
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

//setters
void Chromosome::setFitness(float newFitness)
{
	this->fitness = newFitness;
}
