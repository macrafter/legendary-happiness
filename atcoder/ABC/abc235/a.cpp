#include <iostream>
using namespace std;

int main() {
	string abc;
	cin >> abc;

	char a = abc[0]-48, b = abc[1]-48, c = abc[2]-48;

	cout << 111*(c + a + b);  
}