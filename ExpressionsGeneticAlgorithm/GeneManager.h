#ifndef __GENE_MANAGER_H__
#define __GENE_MANAGER_H__

#include "Headers.h"

class GeneManager{
private:
	float target;

public:
	string toBitString(string expressionString);
	string toExpressionString(string bitString);
};

#endif

