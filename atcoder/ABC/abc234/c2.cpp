#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	unsigned long long k, t = 1;
	cin >> k;

	char a[64];
	
	for(int i = 63; i >= 0;i--) {
		
		if(k & t) {
			a[i] = '2';
		}else {
			a[i] = '0';
		}

		t = t << 1; 
	}

	bool leadingZeros = true;
	for(int i = 0; i < 64;i++) {
		if(a[i] == '2') {
			leadingZeros = false;
		}
		
		if(!leadingZeros){
			cout << a[i]; 
		}
	}
}