#include "LorentzVector.h"
#include <iostream>
#include <cmath>

LorentzVector::LorentzVector() {
	x_ = y_ = z_ = t_ = 0;
}
LorentzVector::LorentzVector(double x, double y, double z, double t) {
	t_ = t;
	x_ = x;
	y_ = y;
	z_ = z;
}
//getters
void LorentzVector::t(double t) {
	t_ = t;
}
void LorentzVector::x(double x) {
	x_ = x;
}
void LorentzVector::y(double y) {
	y_ = y;
}
void LorentzVector::z(double z) {
	z_ = z;
}

//setters
double LorentzVector::t() const {
	return t_;
}
double LorentzVector::x() const {
	return x_;
}
double LorentzVector::y() const {
	return y_;
}
double LorentzVector::z() const {
	return z_;
}

double LorentzVector::dot(const LorentzVector& other) const {
	return c * c * t_ * other.t() - x_ * other.x() - y_ * other.y_ - z_ * other.z_;
}
double LorentzVector::norm() const {
	return c * c * t()*t() - x()*x() - y()*y() - z()*z();
}

LorentzVector LorentzVector::add(const LorentzVector& other) const {
	return LorentzVector(x_ + other.x(), y_ + other.y(), z_ + other.z(), t_ + other.t());
}
LorentzVector LorentzVector::sub(const LorentzVector& other) const {
	return LorentzVector(x_ - other.x(), y_ - other.y(), z_ - other.z(), t_ - other.t());
}
LorentzVector LorentzVector::mulc(double a) const {
	return LorentzVector(x_ * a, y_ * a, z_ * a, t_ * a);
}
//supports stuff
void LorentzVector::read() {
	std::cout << "t: " << std::endl;
	std::cin >> t_;
	std::cout << "x: " << std::endl;
	std::cin >> x_;
	std::cout << "y: " << std::endl;
	std::cin >> y_;
	std::cout << "z: " << std::endl;
	std::cin >> z_;
}
void LorentzVector::print() const {
	std::cout << std::endl << "ct: " << c * t_ << std::endl;
	std::cout << "x: " << c * x_ << std::endl;
	std::cout << "y: " << c * y_ << std::endl;
	std::cout << "z: " << c * z_ << std::endl;
}
//
//Second part of all Tasks
LorentzVector LorentzVector::operator-() const{
	return LorentzVector(-t_, -x_, -y_, -z_);
}
void LorentzVector::operator+=(const LorentzVector& other) {
	t_ += other.t_;
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;
}
void LorentzVector::operator-=(const LorentzVector& other) {
	t_ -= other.t_;
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;
}
void LorentzVector::operator*=(double a) {
	t_ *= a;
	x_ *= a;
	y_ *= a;
	z_ *= a;
}

LorentzVector LorentzVector::operator+(const LorentzVector& o)const {
	return add(o);
}
LorentzVector LorentzVector::operator-(const LorentzVector& other)const {
	return add(-other);
}
LorentzVector operator*( const LorentzVector& lv, double a) {
	return LorentzVector(lv.t_ * a, lv.x_ * a, lv.y_ * a, lv.z_ * a);
}
void LorentzVector::zboost(double v) {
	double gamma = sqrt(1 - (v * v) / (c * c));
	x_ = (x_ - v * t_) / gamma;
	t_ = (t_ - v * x_ / (c * c)) / gamma;
}
std::ostream& operator<<(std::ostream& out, const LorentzVector& lv) {
	out << "(" << lv.c * lv.t() << "; " << lv.x() << "; " << lv.y() << "; " << lv.z() << ")";
	return out;
}