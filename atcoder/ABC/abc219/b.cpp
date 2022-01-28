#include <iostream>
using namespace std;

int main() {
	string s[3],t;

	cin >> s[0] >> s[1] >> s[2] >> t;
	
	for(int i=0;i<t.length();i++){
		cout << s[t[i]-'1'];
	}

	
}