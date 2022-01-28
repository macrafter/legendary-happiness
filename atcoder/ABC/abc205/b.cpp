#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	for(int i=1;i<=n;i++){
		bool boo=false;

		for(int j=0;j<n;j++){
			if(i==arr[j]){
				boo=true;
				break;
			}
		}

		if(boo==false){
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
}