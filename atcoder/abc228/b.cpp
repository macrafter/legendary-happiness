#include <iostream>
using namespace std;

int main() {
	int n,x,secretnum=0;
	cin >> n >> x;

	int a[n], secret[n];

	for(int i=0;i<n;i++) {
		cin >> a[i];
		secret[i] = 0;
	}

	for(int i = 1; i <= n; i++) {

		if(secret[x - 1] == 1)
			break;

		secret[x - 1] = 1;
		x = a[x - 1];
		secretnum++;
	}

	cout << secretnum << endl;

}