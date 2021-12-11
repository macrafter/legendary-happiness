#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	
	for(int i = 1;(i * c) <= b; i++){
		if(a <= (i * c) and (i * c) <= b){
			cout << (i * c);
			return 0;
		}
	}

	// for(int i = a; i <= b; i++) {
	// 	if(i % c == 0) {
	// 		cout << i;
	// 		return 0;
	// 	}
	// }

	cout << -1;
}