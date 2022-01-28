#include <iostream>
using namespace std;

int f(long long int x) {
	return x*x + 2*x + 3;
}  

int main() {
	long long int t;
	cin >> t;

	t = f(f(f(t) + t) + f(f(t)));

	cout << t;  
}
