#ifndef __GENE_MANAGER_H__
#define __GENE_MANAGER_H__

#include "Headers.h"

class GeneManager{
private:
	float target;
	unsigned int genesPerChromosome;
	unsigned int geneLength;
	void setTranslations();

public:
	GeneManager(float target);
	vector<pair<string, string>> geneTranslations;
	string toBitString(string expressionString);
	string toExpressionString(string bitString);
	unsigned int getGenesPerChrm();
};

#endif

