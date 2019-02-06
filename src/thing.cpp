#include <iostream>
using namespace std;

int main() {
	int x = 4;
	int b[] = {1,2,3,4};
	int* y = b;
	y++;
	string g;
	getline(cin,g);
	cout<<*y<<endl;
	cout<<g;
}
