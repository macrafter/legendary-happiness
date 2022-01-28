#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

	if(a-b == 0){
		cout << 1;
		return 0;
	}
	long long int x = pow(32, (a-b));
	cout << x;
}