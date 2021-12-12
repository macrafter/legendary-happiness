#include <iostream>
using namespace std;

int main(){
	int h,w,x,y,n=0;
	cin >> h >> w >> x >> y;
	string s[h];

	for(int i = 0; i < h; i++){
		cin >> s[i];
	}

	for(int i=y-2;i>-1;i--){
		if(s[x-1][i]=='.'){
			n++;
		}else{
			break;
		}
	}

	for(int i=y;i<w;i++){
		if(s[x-1][i]=='.'){
			n++;
		}else{
			break;
		}
	}

	for(int i=x-2;i>-1;i--){
		if(s[i][y-1]=='.'){
			n++;
		}else{
			break;
		}
	}

	for(int i=x;i<h;i++){
		if(s[i][y-1]=='.'){
			n++;
		}else{
			break;
		}
	}

	cout << n+1;

}