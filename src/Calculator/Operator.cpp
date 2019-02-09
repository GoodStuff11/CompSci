#include "Operator.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double firstValue(string expression,char op){
	return stod(expression.substr(0, expression.find(op)));
}

double lastValue(string expression,char op){
	return stod(expression.substr(expression.find(op), expression.length()));
}

double parseAdd(string expression){
	return firstValue(expression,'+') + lastValue(expression,'+');
}


double parseSub(string expression){
	return firstValue(expression,'-') - lastValue(expression,'-');
}

double parseMult(string expression){
	return firstValue(expression,'*') * lastValue(expression,'*');
}

double parseDiv(string expression){
	return firstValue(expression,'/') / lastValue(expression,'/');
}

double parseExp(string expression){
	return pow(firstValue(expression,'^'),lastValue(expression,'^'));
}
