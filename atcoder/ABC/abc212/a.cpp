#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

	if(a==0 and 0<b){
		cout << "Silver";
	}else if(b==0 and 0<a){
		cout << "Gold";
	}else{
		cout << "Alloy";
	}
}