#include "Headers.h"
#include "GeneManager.h"

GeneManager::GeneManager(float target)
{
	this->target = target;
	this->genesPerChromosome = 9;
	setTranslations();
}

void GeneManager::setTranslations()
{
	this->geneTranslations["0000"] = "0";
	this->geneTranslations["0001"] = "1";
	this->geneTranslations["0010"] = "2";
	this->geneTranslations["0011"] = "3";
	this->geneTranslations["0100"] = "4";
	this->geneTranslations["0101"] = "5";
	this->geneTranslations["0110"] = "6";
	this->geneTranslations["0111"] = "7";
	this->geneTranslations["1000"] = "8";
	this->geneTranslations["1001"] = "9";
	this->geneTranslations["1010"] = "+";
	this->geneTranslations["1011"] = "-";
	this->geneTranslations["1100"] = "*";
	this->geneTranslations["1101"] = "/";
}

string GeneManager::toBitString(string expressionString)
{
	/*auto it = geneTranslations.find(expressionString);
	if (it != geneTranslations.end())
		return it->first;*/
	return "";
}

string GeneManager::toExpressionString(string bitString)
{
	return "";
}

unsigned int GeneManager::getGenesPerChrm()
{
	return this->genesPerChromosome;
}