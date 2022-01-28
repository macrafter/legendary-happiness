#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int an = (4*n) - 1;

	int a[an], nums[n+1];

	for(int i = 0;i < an;i++) {
		cin >> a[i];
	}

	for(int i = 0;i < n;i++) {
		nums[i] = 4;
	}

	for(int i = 0;i < an;i++) {
		//cout << a[i] << endl;
		nums[a[i] - 1]--;
	}

	for(int i = 0;i < n;i++) {
		if(nums[i] == 1) cout << (i + 1);
	}
}