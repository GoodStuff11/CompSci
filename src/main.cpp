#include <iostream>
#include "Calculator/Calculator.h"

using namespace std;

int main() {
	Calculator *calc = new Calculator();
	string expression;

	while(1){
		cout << "Input line to calculate: ";
		cin >> expression;

		calc->setExpression(expression);
		calc->parseExpression();

		cout << "Answer: " << calc->getValue();
	}
}
