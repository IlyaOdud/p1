#pragma once
#include <iosfwd>

class LorentzVector {
public:
	LorentzVector();
	LorentzVector(double x, double y, double z, double t);
	void x(double x);
	void y(double y);
	void z(double z);
	void t(double t);
	double x() const;
	double y() const;
	double z() const;
	double t() const;
	double norm() const;

	LorentzVector add(const LorentzVector&) const;
	LorentzVector sub(const LorentzVector&) const;
	LorentzVector mulc(double a) const;
	void zboost(double v);
	double dot(const LorentzVector&) const;
	void read();
	void print() const;

	LorentzVector operator-() const;
	void operator+=(const LorentzVector&);
	void operator-=(const LorentzVector&);
	void operator*=(double);
	LorentzVector operator+ (const LorentzVector&) const;
	LorentzVector operator- (const LorentzVector&) const;

	friend LorentzVector operator* (const LorentzVector& lv, double a);
	friend std::ostream& operator<< (std::ostream& out, const LorentzVector& lv);
	
private:
	double x_, y_, z_, t_;
	const unsigned long long c = 1;// 299792458;
};

std::ostream& operator<<(std::ostream&, const LorentzVector&);