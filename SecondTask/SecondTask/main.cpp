#include "LorentzVector.h"
#include <iostream>

int main() {
	LorentzVector v1;
	LorentzVector v2;
	v1.read();
	v2.read();

	LorentzVector V1 = v1.add(v2);
	V1.print();
	LorentzVector V2 = v1.sub(v2);
	V2.print();

	double a = 10.5;
	LorentzVector V3 = v1 * a;
	V3.print();

	std::cout << v1 << v2;
//	operator << (std::cout, v1);
	return 0;
}