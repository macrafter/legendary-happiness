#include <iostream>

using namespace std;


int main() {

	string s;

	cin >> s;

	if(s[0] == s[1] and s[0] == s[2]){
		cout << 1;
	}else if(s[0] == s[1] or s[0] == s[2] or s[1] == s[2]){
		cout << 3;
	}else{
		cout << 6;
	}
}
