#include "Calculator.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void Calculator::setExpression(string expression_) {
	//removing spaces which are completely unnecessary
	//https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
	expression_.erase(remove(expression_.begin(), expression_.end(), ' '), expression_.end());
	expression = expression_;

}

void Calculator::parseExpression() {
	// check for equal number of ( and )
	//https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string
	if (count(expression.begin(), expression.end(), '(') == count(expression.begin(), expression.end(), ')')){
		for(char& c : expression){

		}
		value = 0;
	}else{
		cout << "Error occurred: not equal number of ( and )";
		value = -1;
	}

}

double Calculator::getValue() {
	return value;
}

double Calculator::parseAddSub(string expression_){

}

