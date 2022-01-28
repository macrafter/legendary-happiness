#include <iostream>
using namespace std;

int main() {
	int n;
	long long int maxx, a;
	cin >> n >> maxx;

	for(int i = 0;i < n - 1; i++) {
		cin >> a;
		if(a > maxx) {
			maxx = a;
		} else {
			break;
		}
	}

	cout << maxx;
}
