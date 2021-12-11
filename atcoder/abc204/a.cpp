#include <iostream>
using namespace std;

int main(){
	int x,y;
	cin >> x >> y;

	if(x==y){
		cout << x;
	}else if((x==0 and y==1) or (x==1 and y==0)){
		cout << 2;
	}else if((x==0 and y==2) or (x==2 and y==0)){
		cout << 1;
	}else{
		cout << 0;
	}
}