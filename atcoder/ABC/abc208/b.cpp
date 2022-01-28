#include <iostream>
using namespace std;

int main() {
	int p,coins=0;
	cin >> p;
	
	for(int i=p;i>0;i++){
		for(int j=1,k=1;k*(j+1)<=i and j<i;j++){
			
			k=k*(j);
			coins++;
		}
	}

	cout << coins;
}