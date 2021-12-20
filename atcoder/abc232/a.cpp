#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	cout << ((char) s[0]-48)*((char) s[2]-48);
}