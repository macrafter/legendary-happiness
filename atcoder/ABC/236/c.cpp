#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s[n], t[m];

	for(int i = 0;i < n;i++) cin >> s[i];
	for(int i = 0;i < m;i++) cin >> t[i];

	for(int i = 0, j = 0; i < n;i++) {
		if(s[i] == t[j]) {
			cout << "Yes" << endl;
			j++;
		}else {
			cout << "No" << endl;
		}
	}
}