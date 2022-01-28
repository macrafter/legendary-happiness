#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	string names[n];

	for(int i=0;i<n;i++){
		cin >> names[i];
	}

	int maxvotes = 0;
	string maxname;

	for(int i=0;i<n;i++){
		int cnt=0;

		for(int j=i;j<n;j++){
			if(names[i]==names[j]){
				cnt++;
			}
		}

		if(cnt>maxvotes){
			maxname=names[i];
			maxvotes=cnt;
		}
	}
	cout << maxname;
	return 0;
}