#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s[n],t[n];

	for(int i=0;i<n;i++){
		cin >> s[i];
		cin >> t[i];
	}

	for(int i=0;i<n;i++){

		for(int j=i+1;j<n;j++){

			if(s[i]==s[j] and t[i]==t[j]){
				cout << "Yes";
				return 0;
			}

		}
	}

	cout << "No";

}
