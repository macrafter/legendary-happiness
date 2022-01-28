#include <iostream>
using namespace std;

int main() {
	string s,t="oxxoxxoxxoxxoxxoxxo";
	cin >> s;
	string a=s;

	for(int i=0;i<=s.length();i++){
		for(int j=0;j<s.length();j++){
			a[j]=t[i+j];
		}

		if(a==s){
			cout << "Yes";
			return 0;
		}
	
		a=s;
	}

	cout << "No"; 
}