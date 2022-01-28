#include <iostream>
using namespace std;

int main() {
	long long int n,a=1,i;
	cin >> n;

	for(i=0;a*2<=n;i++){
		a=a*2;
	}

	cout << i;
}