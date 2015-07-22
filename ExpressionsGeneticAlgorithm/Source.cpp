#include "Headers.h"
#include "Controller.h"

using namespace std;

////////////////////////////////////////
/// BEGIN GENETICS VARIABLES
//////
const unsigned int maxPopulationSize = 10;
const unsigned int crossoverRate = 0.7;
const unsigned int mutationRate = 0.001;
const unsigned int genesPerChromosome = 9;
const int target = 42;
//////
/// END GENETICS VARIABLES
////////////////////////////////////////


void main()
{
	srand(time(NULL));
	cout << "Welcome to Expressions Genetic Algorithm. Target is " << target << endl;

	Controller controller(maxPopulationSize, crossoverRate, mutationRate, genesPerChromosome, target);
	controller.start();

	getchar();
}