#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	for(int i=0,min=0;i<n;i++){

		min = i;
		
		for(int j=i;j<n;j++) {	

			if(arr[min]>arr[j]){
				min=j;
			}

		}

		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;

		cout << arr[i] << endl;
	}
}


