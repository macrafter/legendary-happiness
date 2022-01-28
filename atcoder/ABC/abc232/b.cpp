#include <iostream>
using namespace std;

int main() {
	/*
	string s, t;
	cin >> s >> t;

	int diff = 0; 
	if(s[0] <= t[0])
		diff = t[0] - s[0];
	else
		diff = ('z' - s[0]) + (t[0] - 'a') + 1;

	bool yes = true;
	//cout << diff << endl;

	for(long unsigned int i = 1; i < s.length(); i++) {

		int ndiff = 0;
		
		if(s[i] <= t[i])
			ndiff = t[i] - s[i];
		else
			ndiff = ('z' - s[i]) + (t[i] - 'a') + 1;
		//cout << ndiff << endl;

		if(ndiff != diff) {
			yes = false;
			break;
		}

	}

	


		y 
		b


	*/

	//cout << (yes ? "Yes" : "No") << endl;


	string s,t;
	int i=0;
	cin >> s >> t;

	while(i<=26){
		if(((int) s[0])+i == (int) t[0]){
			break;
		}else{
			i++;	
		}
	}

	cout << (int) s[0] << i;

	for(int j=1;j<s.length();j++){
		if(((int) s[j]+i) != (int) t[j]){
			return 0;
		}

		cout << " " << j;
	}

	cout << "Yes";
}