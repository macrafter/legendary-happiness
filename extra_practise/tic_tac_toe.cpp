#include <iostream>
using namespace std;

int main() {
	string a[3]={"123","456","789"},tem;
	int x,o,i=0;

	while(true){

		if(i%2==0){
			tem = 'x';
		}else{
			tem = 'o';
		}

		cout << a[0] << endl << a[1] << endl << a[2] << endl; 
		cout << "Player " << tem << "'s turn: ";

		cin >> x >> o;
		a[x-1][o-1] = tem;
		
		//cross check
		if((a[0][0] == a[1][1] and a[1][1] == a[2][2]) or (a[0][2] == a[1][1] and a[1][1] == a[2][0])){
			cout << "Player " << tem << " wins!";
			return 0;
		
		//vertical check
		}else if((a[0][0] == a[0][1] and a[0][0] == a[0][2]) or (a[1][0] == a[1][1] and a[1][0] == a[1][2]) or (a[2][0] == a[2][1] and a[2][1] == a[2][2])){
			cout << "Player " << tem << " wins!";
			return 0;

		//horizontal check
		}else if((a[0][0] == a[1][0] and a[1][0] == a[2][0]) or (a[0][1] == a[1][1] and a[1][1] == a[2][1]) or (a[0][2] == a[1][2] and a[1][2] == a[2][2])){
			cout << "Player " << tem << " wins!";
			return 0;
		}

		i++;
	}
}