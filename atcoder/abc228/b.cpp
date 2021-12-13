#include <iostream>
using namespace std;

int main(){
	int n,x,secretnum=0;
	cin >> n >> x;
	int a[n],secret[n];

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

  for(int i=a[x-1],k=0;i<=n;k++,secretnum++){
		for(int j=0;j<=n;j++){
			if(i==secret[j]){
				cout << secretnum;
				return 0;
			}
		}
		secret[k]=i;
		i=a[i-1];
	}

}