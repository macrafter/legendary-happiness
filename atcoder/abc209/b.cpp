#include <iostream>
using namespace std;

int main() {
	int n,x,cnt=0;
	cin >> n >> x;
	int a[n];

	for(int i=0;i<n;i++){
		cin >> a[i];

		if(i%2==1){
			a[i]=a[i]-1;
		}

		cnt = cnt + a[i];
	}

	if(cnt > x){
		cout << "No";
	}else{
		cout << "Yes";
	}

}