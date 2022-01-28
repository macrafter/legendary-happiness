#include <iostream>
using namespace std;

int main() {
	int l,r;
	string s;
	cin >> l >> r >> s;

	for(int i=0;i<s.length();i++){
		
		if(l-1==i){
			i=r-1;
			for(int j=r-1,k=r-l;k>=0;j--,k--){
				cout << s[j];	
			}
		}else{
			cout << s[i];
		}


	}
}