#include "Calculator.h"
#include "Operator.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double parse(string expression){
	// 3  + 2 -> 3+2
	if(count(expression.begin(), expression.end(), ' ') > 0){
		expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
	}
	if (!expression.length())
		return 0;

	//search for operators
	int layer = 0;
	// go from right to left so 6/2/3 will be first split into 6/2 and 3 -> 3/3
	for(int i = expression.length()-1; i>= 0; i--) {
		char c = expression[i];
		// differentiate between (2+3)*3 where the + is on the 1st layer
		// and * is on the 0th layer. In this case, we split the expression
		// into (2+3) and 3
		if (c == '(')
			layer++;
		else if (c == ')')
			layer--;
		else if (c == '+' && !layer)
			return parse(expression.substr(0,i)) + parse(expression.substr(i+1,expression.length()));
		else if (c == '-' && !layer)
			return parse(expression.substr(0,i)) - parse(expression.substr(i+1,expression.length()));
		else if (c == '*' && !layer)
			return parse(expression.substr(0,i)) * parse(expression.substr(i+1,expression.length()));
		else if (c == '/' && !layer)
			return parse(expression.substr(0,i)) / parse(expression.substr(i+1,expression.length()));
		else if (c == '^' && !layer)
			return pow(parse(expression.substr(0,i)), parse(expression.substr(i+1,expression.length())));
	}
	//search for functions
	if (count(expression.begin(),expression.end(),'(')){
		int i = expression.find('(');
		string funcName = expression.substr(0,i);
		double input = parse(expression.substr(i+1,expression.length()-funcName.length()-2));

		if ("sin" == funcName)
			return sin(input);
		else if ("cos" == funcName)
			return cos(input);
		else if ("tan" == funcName)
			return tan(input);
		else if ("asin" == funcName)
			return asin(input);
		else if ("acos" == funcName)
			return acos(input);
		else if ("atan" == funcName)
			return atan(input);
		else if ("sqrt" == funcName)
			return sqrt(input);
		else if ("ln" == funcName)
			return log(input);
		else if ("exp" == funcName)
			return exp(input);
	}
	// (2+3) -> 2+3
	// if the program makes it this far, the only possible case is where the
	// brackets are not doing anything
	if (expression[0] == '(' && expression[expression.length()-1] == ')')
		return parse(expression.substr(1,expression.length()-2));

	return parseValue(expression);
}

// parsing value
double parseValue(string expression){
	if (expression == "pi")
		return PI;
	else if (expression == "e")
		return E;
	return stod(expression);
}
