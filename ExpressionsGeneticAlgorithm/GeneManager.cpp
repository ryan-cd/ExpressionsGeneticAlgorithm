#include "Headers.h"
#include "GeneManager.h"

GeneManager::GeneManager(float target)
{
	this->target = target;
	this->genesPerChromosome = 9;
	this->geneLength = 4;
	setTranslations();
	//cout << endl << "gene manager\n" << toExpressionString("10110010001000100010001000101011") << endl;
	//cout << endl << "gene manager\n" << toExpressionString("0010001010101110101101110010") << endl;
	//cout << endl << "gene manager\n" << toExpressionString("011010100101110001001101001010100001") << endl;
	
}

void GeneManager::setTranslations()
{
	this->geneTranslations.push_back(make_pair("0000", "0"));
	this->geneTranslations.push_back(make_pair("0001", "1"));
	this->geneTranslations.push_back(make_pair("0010", "2"));
	this->geneTranslations.push_back(make_pair("0011", "3"));
	this->geneTranslations.push_back(make_pair("0100", "4"));
	this->geneTranslations.push_back(make_pair("0101", "5"));
	this->geneTranslations.push_back(make_pair("0110", "6"));
	this->geneTranslations.push_back(make_pair("0111", "7"));
	this->geneTranslations.push_back(make_pair("1000", "8"));
	this->geneTranslations.push_back(make_pair("1001", "9"));
	this->geneTranslations.push_back(make_pair("1010", "+"));
	this->geneTranslations.push_back(make_pair("1011", "-"));
	this->geneTranslations.push_back(make_pair("1100", "*"));
	this->geneTranslations.push_back(make_pair("1101", "/"));
}

string GeneManager::toBitString(string expressionString)
{
	string result = "";
	for (int i = 0; i < expressionString.size(); i++)
	{
		for (int j = 0; j < geneTranslations.size(); j++)
		{
			if (expressionString.substr(i, 1) == this->geneTranslations[j].second)
				result += this->geneTranslations[j].first;
		}
	}
	return result;
}

string GeneManager::toExpressionString(string bitString)
{
	string result = "";
	enum ExpressionLeaf {NUMBER, OPERATOR};
	ExpressionLeaf lastLeafType = OPERATOR;

	for (int i = 0; i < bitString.size(); i+= this->geneLength)
	{
		for (int j = 0; j < geneTranslations.size(); j++)
		{
			if (bitString.substr(i, this->geneLength) == this->geneTranslations[j].first
				&& ((lastLeafType == NUMBER && j > 9 && i < bitString.size() - this->geneLength) || lastLeafType == OPERATOR && j <= 9))
			{
				result += this->geneTranslations[j].second;
				if (j <= 9)
					lastLeafType = NUMBER;
				else
					lastLeafType = OPERATOR;
			}

		}
	}
	return result;
}

unsigned int GeneManager::getGenesPerChrm()
{
	return this->genesPerChromosome;
}

float GeneManager::getFitness(Chromosome chromosome)
{
	string expression = toExpressionString(chromosome.getBitString());

	float currentResult = (int)expression[0] - '0';
	for (int i = 0; i < expression.size()-1; i += 2)
	{
		string subexpression = to_string(currentResult) + expression.substr(i+1, 2);
		
		int operand2 = (int)subexpression[subexpression.size()-1] - '0';
		
		if (subexpression.substr(subexpression.size()-2, 1) == "+")
			currentResult = (currentResult + operand2);
		else if (subexpression.substr(subexpression.size() - 2, 1) == "-")
			currentResult = (currentResult - operand2);
		else if (subexpression.substr(subexpression.size() - 2, 1) == "*")
			currentResult = (currentResult * operand2);
		else if (subexpression.substr(subexpression.size() - 2, 1) == "/")
			currentResult = (currentResult / operand2);
		else
			throw new exception("Subexpression in invalid format"); 

	}
	if (currentResult == this->target)
		return FLT_MAX;
	else 
		return 1/(this->target - currentResult);
}