#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;
	double x[n], y[n];

	for(int i = 0;i < n;i++) {
		cin >> x[i] >> y[i];
	}

	double max = 0;
	for(int i = 0;i < n;i++) {
		for(int j = i+1;j < n;j++) {

			double dist = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
			if(dist > max) {
				max = dist;
			}
		}
	}

	cout.precision(10);
	cout << fixed << max;

	//printf("%lf", max);
}