#include <iostream>
using namespace std;

int main(){
	int a,c,b;
	cin >> a >> b >> c;

	if((a==b and b==c) or (a-b==b-c) or (a-c==c-b) or (b-a==a-c) or (b-c==c-a) or (c-a==a-b) or (c-b==b-a)){
		cout << "Yes";
	}else{
		cout << "No";
	}
}