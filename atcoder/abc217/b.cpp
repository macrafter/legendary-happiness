#include <iostream>
using namespace std;

int main() {
	string s[3],a[4] = {"ABC", "ARC", "AGC", "AHC"};

	for(int i=0;i<3;i++){
		cin >> s[i];
	}

	for(int i=0;i<4;i++){

		for(int j=0;j<3;j++){
			
			if(a[i]==s[j]){
				break;
				
			}else if(a[i]!=s[j] and j==2){
				cout << a[i];
				return 0;
			}
			
		}
	}	
}