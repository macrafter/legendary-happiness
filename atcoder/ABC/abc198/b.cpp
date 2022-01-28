#include <iostream>
using namespace std;

int main(){
	string n,a[20];
	cin >> n;
	
	for(int i=n.length()-1,j=0;j<=n.length()-1;i--,j++){
		a[j]=n[i];
	}

	cout << a;
}
