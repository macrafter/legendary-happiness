#include <iostream>
using namespace std;

int main() {
	int p[26];

	for(int i=0;i<26;i++){
		cin >> p[i];
		p[i]=p[i]+96;
	}

	for(int i=0;i<26;i++){
		cout << (char) p[i];
	}
}