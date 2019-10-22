#include "Dr.h"
#include <iostream>
using namespace std;
int main() {
	//комплексное пространство
	Dr z1 = Dr(1, 2);
	Dr z2 = Dr(-1, 1);
	Dr z3 = z1.mn(z2);
	z3.print();//-3.-1
	int n;
	cout << "Write number. The point of sum:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		z1 += z2;
	}
	z1.print();
	cout << "Write number. The point of diff:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		z1 -= z2;
	}
	z1 = -z1;
	z1.print();
	return 0;
}
