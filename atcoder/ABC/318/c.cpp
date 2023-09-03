#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long int n,d,p;
	long long batches = 0, maxsum = 0;
	cin >> n >> d >> p;
	vector<long long int> f(n);

	for(int i = 0;i < n;i++)
		cin >> f[i];

	sort(f.begin(),f.end());

	
	for(int i = n; i >= 0; i -= d) {
		long long sum = 0;

		for(int j = 1;j <= d && j <= i;j++) {
			sum += f[i-j];
		}

		if(sum > p) {
			batches += 1;
		} else if(sum < p)
			break;
	}

	for(int i = 0;i < n - (batches * d);i++) {
		maxsum += f[i];
	}

	cout << maxsum + (batches * p) << endl;
}



