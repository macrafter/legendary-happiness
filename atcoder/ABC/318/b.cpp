#include <iostream>
using namespace std;

int main() {
	int n,count = 0;
	bool arr[100][100] = {};
	cin >> n;
	int a[n],b[n],c[n],d[n];
	for(int i = 0;i < n;i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];

		
	}

	for(int i = 0;i < 100;i++) {
		for(int j = 0;j < 100;j++) {
			arr[i][j] = false;
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = a[i];j < b[i];j++) {
			for(int k = c[i];k < d[i];k++) {
				if(arr[j][k]){
					continue;
				}else{
					arr[j][k] = true;
					count++;
				}
			}
		}
	}

	cout << count << endl;
}