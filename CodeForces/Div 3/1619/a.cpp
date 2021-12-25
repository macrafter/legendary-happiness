#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		string s,a,b;
		cin >> s;

		if(s.length()%2!=0){
			cout << "no";
			continue;
		}

		for(int j=0;j<s.length()*0.5;j++){
			a[j]=s[j];
		}

		for(int j=0;j<s.length()*0.5;j++){
			b[j]=s[j+(s.length()*0.5)];
		}

		cout << b << a;



		if(b==a){
			cout << "yes";
		}else{
			cout << "no";
		}

	}
}