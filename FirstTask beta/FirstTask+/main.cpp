#include "LorentzVector.h"
#include <iostream>
using namespace std;
int main() {
	LorentzVector v1;
	LorentzVector v2;
	v1.read();
	v2.read();
	double a = v1.norm();
	cout << a;
	return 0;
}