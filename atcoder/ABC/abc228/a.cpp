#include <iostream>

using namespace std;


int main() {

	int S, T, X;

	cin >> S >> T >> X;


	if( S > T && T < (X + 0.5) && (X + 0.5) < S ) {
		cout << "No";
	}else if(S > T){
		cout << "Yes";
	}
	
	if(S < T && S < (X + 0.5) && (X + 0.5) < T ){
		cout << "Yes";
	}else if(S < T){
		cout << "No";
	}



	// double xp = X + 0.5;

	// // same day off
	// if(S < T) {

	// 	if(S < xp && xp < T)
	// 		cout << "Yes";
	// 	else
	// 		cout << "No";

	// }


	// // next day off
	// if(S > T) {

	// 	//if((S < xp < 24) || (0 < xp < T))
	// 	if(T < xp && xp < S)
	// 		cout << "No";
	// 	else
	// 		cout << "Yes";

	// } 

}






