#include <iostream>

using namespace std;


int main() {
	int n, k, a;
	cin >> n >> k >> a;
	
	int x = k + a - 1;

	int ans = x % n;
	
	if(ans == 0){
		ans = n;
	}
		
	cout << ans;

	return 0;
}