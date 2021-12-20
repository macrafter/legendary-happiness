#include <iostream>
using namespace std;

int main() {
	string s[4],a[4] = {"H", "2B", "3B", "HR"};
	cin >> s[0] >> s[1] >> s[2] >> s[3];

	for(int i=0;i<4;i++){

		bool found =false;

		for(int j=0;j<4;j++){
			
			if(a[i]==s[j]){
				found = true;
				break;
			} 
		}

		if(!found){
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
}
