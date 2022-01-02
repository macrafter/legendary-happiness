#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y;
};


int main() {

	Point p;
	p.x = 10;
	p.y = 20;

	cout << p.x << " " << p.y << " " << endl;


	Point *ptr;

	ptr = &p;	

	cout << ptr << endl;
	cout << &p << endl;


	ptr->x = 100;
	ptr->y = 200;

	cout << p.x << " " << p.y << " " << endl;
}
