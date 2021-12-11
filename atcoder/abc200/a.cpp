#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	if(n<=100){
		cout << 1;
		return 0;
	}

	if(n%100==0){
		cout << (n/100);
	}else{
		cout << (n/100) + 1;
	}
}