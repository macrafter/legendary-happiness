#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	for(int i=0;true;i++){
		if(x>=y){
			cout << i;
			return 0;
		}
		x += 10;
	}
}