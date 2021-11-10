#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include <cstdint>
#include "point.h"
#include "figure.h"

class Trapezoid : public Figure
{
public:
	Trapezoid();
	Trapezoid(Point a_, Point b_, Point c_, Point d_);
	Trapezoid(std::istream &is);
	Trapezoid(const Trapezoid& other);

	friend std::istream& operator>>(std::istream& is, Trapezoid& obj);
	friend std::ostream& operator<<(std::ostream& os, Trapezoid& obj);
	Trapezoid& operator=(const Trapezoid& right);
	size_t VertexesNumber();
	double Area();
	void Print();

	virtual ~Trapezoid(); // деструктор 

private:
	Point a;
	Point b;
	Point c;
	Point d;
};

#endif /* TRAPEZOID_H */