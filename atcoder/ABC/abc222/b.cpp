#include <iostream>
using namespace std;

int main() {
	int n,p,o=0;
	cin >> n >> p;
	int a[n];

	for(int i=0;i<n;i++){
		cin >> a[i];

		if(a[i]<p){
			o++;
		}
	}

	cout << o;
}