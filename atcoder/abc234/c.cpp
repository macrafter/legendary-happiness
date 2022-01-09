#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {

	unsigned long long k;
	cin >> k;

	unsigned long long t = 1;

	char arr[64];

	for(int i = 63; i >= 0; i--) {

		if(k & t)
			arr[i] = '2';
		else
			arr[i] = '0';

		t = t << 1;
	}

	bool leading_zero = true;

	for(int i = 0; i < 64; i++) {
		if(arr[i] == '2')
			leading_zero = false;

		if(!leading_zero)
			cout << arr[i];
	}

	cout << endl;
}





