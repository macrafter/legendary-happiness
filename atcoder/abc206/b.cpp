#include <iostream>
using namespace std;

int main() {
	int n,a=0;
	cin >> n;

	for(int i=0;true;i++){
		if(i+a>=n){
			cout << i;
			return 0;
		}

		a=i+a;
	}
}