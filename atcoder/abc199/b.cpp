#include <iostream>
using namespace std;

int main(){
	int x[1000],n,y[1000],a[100],b[100],z[1000];
	cin >> n;
	int xsize=0,ysize=0,zsize=0;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<n;i++){
		cin >> b[i];
	}

	for(int i=0;i<n;i++){
		
		for(int j=a[i],k=0;j<b[i];j++,k++){
			x[k]=j;
			xsize++;
		}


		for(int j=a[i+1],k=0;j<b[i+1];j++,k++){
			y[k]=j;
			ysize++;
		}

		for(int j=0,l=0;j<=xsize or j<=ysize;j++){
			for(int k=0;k<ysize;k++){
				if(x[j]==y[k]){
					z[l]=x[j];
					l++
;					zsize++;
				}
			}

		}
		xsize=0,ysize=0;
	}
	cout << zsize;
}