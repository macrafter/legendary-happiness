#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	if(n<126){
		cout << 4;
	}else if(n<212){
		cout << 6;
	}else{
		cout << 8;
	}
}