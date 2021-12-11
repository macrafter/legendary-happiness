#include <iostream>
using namespace std;

int main(){
	string s;
	int n;
	cin >> n >> s;

	if(s[n-1] == 'o'){
		cout << "Yes";
	}else{
		cout << "No";
	}
}