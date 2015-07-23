#ifndef __GENE_MANAGER_H__
#define __GENE_MANAGER_H__

#include "Headers.h"

class GeneManager{
private:
	float target;
	unsigned int genesPerChromosome;
	void setTranslations();

public:
	GeneManager(float target);
	map<string, string> geneTranslations;
	string toBitString(string expressionString);
	string toExpressionString(string bitString);
	unsigned int getGenesPerChrm();
};

#endif

