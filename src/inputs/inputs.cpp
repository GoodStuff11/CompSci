#include "inputs.h"
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;

void input() {
	int x;
	int n;
	char c = '0';

	cout << "Give number" << endl;
	cin >> x;
	cout << "Give field width" << endl;
	cin >> n;
	cout << "Give char to fill with" << endl;
	cin >> c;

	//http://www.cplusplus.com/forum/beginner/55961/
	//prints an amount of 0s until the total is the field width
	//if it starts over, then it will just print the input

	string repeatedChar = string(relu(n - numDigits(x)), c);

	//https://stackoverflow.com/questions/7352099/stdstring-to-char
	const char* cstr = repeatedChar.c_str();

	cout << repeatedChar << x << endl;
	cout << "----" << endl;
	printf("%s%u", cstr, x);

	delete cstr;
}

int relu(int x) {
	return (abs(x) + x) / 2;
}
//https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
int numDigits(int number) {
	int digits = 0;
	if (number < 0)
		digits = 1;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}

