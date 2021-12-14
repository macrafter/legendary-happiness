#include <iostream>
using namespace std;

int main() {
	string s,t;
	cin >> s >> t;
	string a=t;

	if(s==t){
		cout << "Yes";
	}else{
		for(int i=0;i<s.length()-1;i++){
			a[i]=t[i+1];
			a[i+1]=t[i];

			cout << a << endl;
			if(a==s){
				cout << "Yes";
				return 0;
			}
			a=t;
		}
	}

	cout << "No";
}