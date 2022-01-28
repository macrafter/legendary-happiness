#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];

	for(int i = 0;i < n; i++) {
		cin >> arr[i];
	}

	int minindex = 0;
	for(int i = 0;i < n; i++) {
		if(arr[i] < arr[minindex]) minindex = i;
		if(arr[minindex] == 1) break;
	}

	int maxindex = -1;
	for(int i = 0;i < minindex; i++) {
		if(maxindex == -1){
			if(arr[i] > arr[minindex])	
				maxindex = i;
		}
		else {
			if(arr[i] > arr[maxindex]) maxindex = i;
		}
	}

	if(maxindex == -1) {
		maxindex = n-1;
		for(int i = n-1;i > minindex; i--) {
			if(arr[i] > arr[maxindex]) maxindex = i;
		}
	}

	for(int i = 0;i < n; i++) {
		if(arr[i] != arr[maxindex]) cout << arr[i] << ' ';
	}
}

// 3 1 2 4 4 1 2

// 3 1 2 1 2
// 1 2 4 4 1 2

// 4 4 5 1 3 3 2 1

// 1 2 3
