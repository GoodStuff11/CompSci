#include <iostream>
using namespace std;

class Calculator{
private:
	double value;
	string expression;
	double parseAddSub(string expression);
public:
	void setExpression(string expression);
	void parseExpression();
	double getValue();
};
