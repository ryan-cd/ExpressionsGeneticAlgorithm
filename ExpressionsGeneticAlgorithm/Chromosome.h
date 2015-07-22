#ifndef __CHROMOSOME_H__
#define __CHROMOSOME_H__

#include "Headers.h"


class Chromosome
{
private:
	string bitString;
	float fitness;

public:
	Chromosome(unsigned int genesPerChromosome);
	Chromosome(unsigned int genesPerChromosome, string bitString);

	//getters
	string getBitString();
	unsigned int getFitness();
	
	//mutators
	void setFitness(float newFitness);
	void setBitStringAt(unsigned int index, unsigned int value);

};

#endif