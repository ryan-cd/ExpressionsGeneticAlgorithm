#ifndef __GENE_MANAGER_H__
#define __GENE_MANAGER_H__

#include "Headers.h"
#include "Chromosome.h"

class GeneManager{
private:
	float target;
	unsigned int genesPerChromosome;
	unsigned int geneLength;
	vector<pair<string, string>> geneTranslations;
	void setTranslations();

public:
	GeneManager(float target);
	string toBitString(string expressionString);
	string toExpressionString(string bitString);
	unsigned int getGenesPerChrm();
	unsigned int getGeneLength();
	float getFitness(Chromosome chromosome);
};

#endif

