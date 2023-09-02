#include <iostream>
using namespace std;

int main() {
	int n,m,p;
	cin >> n >> m >> p;
	
	if(n<m) {
		cout << 0;
	}else if(((p * (n / p)) + m) <= n) {
		cout << (n / p) + 1;
	}else {
		cout << n / p;
	}

}
