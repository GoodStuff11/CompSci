#include <iostream>
#include "Calculator/Calculator.h"

using namespace std;

int main() {
	string expression;

	while(1){
		cout << "Input line to calculate: ";
		getline(cin,expression);

		printf("Answer: %f\n",parse(expression));
	}
}
