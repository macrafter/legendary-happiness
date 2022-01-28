#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];

	int max1=0, max2=0;

	int answer = 0;
	int max1i = 0;

	for(int i=0;i<n;i++) {
		int t;
		cin >> t;

		if(t > max2) {			
			if(t > max1) {
				max2 = max1;
				max1 = t;
				answer = max1i;
				max1i = i;
			} else {
				max2 = t;
				answer = i;
			}
		}

		//cout << max1 << " " << max2 << endl;
	}

	cout << (answer+1) << endl;


	// for(int i=0;i<n;i++){
	// 	int ji=0;

	// 	for(int j=0;j<n;j++){
	// 		if(a[i]>a[j]){
	// 			ji++;
	// 		}
	// 	}

	// 	if(ji==n-2){
	// 		cout << (i+1);
	// 		return 0;
	// 	}
	// }


}