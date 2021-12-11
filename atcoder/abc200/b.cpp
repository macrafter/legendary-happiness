#include <iostream>
using namespace std;

int main(){
	long long int n;
	int k;
	cin >> n >> k;

	for(int i=1;i<=k;i++){
		if(n%200==0){
			n=n/200;
		}else{
			n=n*1000+200;
		}
	}

	cout << n;
}