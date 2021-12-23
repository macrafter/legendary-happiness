#include <iostream>
using namespace std;

int fib(int n){

	if (n == 1 or n == 2)
		return 1;

	return fib(n -1) + fib(n - 2);
}

int sum(int n) {

	if(n == 1) {
		cout << "returning 1" << endl;
		return 1;
	}

	cout << "recursive call for n:" << n << endl;
	return n + sum(n - 1);
}

int main() {
	int n;

	cin >> n;

	cout << sum(n) << endl;

}
