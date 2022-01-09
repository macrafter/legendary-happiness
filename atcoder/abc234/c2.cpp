#include <iostream>
#include <cstudio>
using namespace std;

int main() {
	unsigned long long int k, t = 1;
	cin >> k;

	char a[64];
	for(int i = 63; i >= 0;i--) {
		if(k & t) {
			a[i] = '2';
		}else {
			a[i] = '0';
		}
		cout << a[i];
	}


}