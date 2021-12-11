#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;

	if((a==b and a==c) or (a==b and a!=c)){
		cout << c;
	}else if(a==c and a!=b){
		cout << b;
	}else if(a!=c and c==b){
		cout << a;
	}else{
		cout << 0;
	}
}