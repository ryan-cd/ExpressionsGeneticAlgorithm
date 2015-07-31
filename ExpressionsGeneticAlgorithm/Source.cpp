#include "Headers.h"
#include "Controller.h"

using namespace std;

////////////////////////////////////////
/// BEGIN GENETICS VARIABLES
//////
const unsigned int maxPopulationSize = 10;
const float crossoverRate = 0.7;
const float mutationRate = 0.001;
const int target = 24;
//////
/// END GENETICS VARIABLES
////////////////////////////////////////


int main()
{
	srand(time(NULL));
	cout << "Welcome to Expressions Genetic Algorithm. Target is " << target << endl;

	Controller controller(maxPopulationSize, crossoverRate, mutationRate, target);
	string result = controller.generateTarget();

	cout << "Result: " << target << " = " << result;

	getchar();

	return 0;
}