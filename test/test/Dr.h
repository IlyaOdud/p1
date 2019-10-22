#pragma once

class Dr {
public:
	Dr();
	Dr(double, double);
	void x(double);
	void y(double);

	double x() const;
	double y() const;

	double norm() const;

	Dr sum(const Dr&) const;
	Dr sub(const Dr&) const;
	Dr mul(double) const;
	Dr mn(const Dr&) const;
	
	void read();
	void print() const;

	Dr operator-()const;

	void operator+=(const Dr&);
	void operator-=(const Dr&);

	double dot(const Dr&) const;

private:
	double x_, y_;
};