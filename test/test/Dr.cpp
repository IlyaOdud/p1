#include "Dr.h"
#include <iostream>
#include <cmath>

Dr::Dr() {
	x_ = y_ = 0;
}
Dr::Dr(double x, double y) {
	x_ = x;
	y_ = y;
}

void Dr::x(double x) {
	x_ = x;
}
void Dr::y(double y) {
	y_ = y;
}

double Dr::x() const {
	return x_;
}
double Dr::y() const {
	return y_;
}

double Dr::dot(const Dr& other) const {
	return sqrt(x_ * x_ + y_ * y_);
}
double Dr::norm() const {
	return this->dot(*this);
}

Dr Dr::sum(const Dr& other) const {
	return Dr(x_ + other.x(), y_ + other.y());
}
Dr Dr::mul(double a) const {
	return Dr(x_*a, y_*a);
}
Dr Dr::sub(const Dr& other) const {
	return Dr(x_ - other.x(), y_ - other.y());
}
Dr Dr::mn(const Dr& other) const {//(a+ib)(c+id)=ac + iad + ibc - bd
	return Dr(x_ * other.x() - y_ * other.y(), x_*other.y() + y_ * other.x());
}
//деление
//сопряжение
void Dr::read() {
	std::cout << "x: " << std::endl;
	std::cin >> x_;
	std::cout << "y: " << std::endl;
	std::cin >> y_;
}
void Dr::print() const {
	std::cout << "x: " <<  x_ << std::endl;
	std::cout << "y: " <<  y_ << std::endl;
}
Dr Dr::operator-() const {
	return Dr(-x_, -y_);
}
void Dr::operator+=(const Dr& other) {
	x_ += other.x_;
	y_ += other.y_;
}
void Dr::operator-=(const Dr& other) {
	x_ -= other.x_;
	y_ -= other.y_;
}
Dr operator*(const Dr& lv, double a) {
	return Dr(lv.x() * a, lv.y() * a);
}