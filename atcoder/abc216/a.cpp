#include <iostream>
using namespace std;

int main(){
	float a;
	cin >> a;
	
	int x = a;
	int y = a*10;
	y = y % 10;

	if(y<=2){
		cout << x << "-";
	}else if(y<=6){
		cout << x;
	}else{
		cout << x << "+";
	}
}