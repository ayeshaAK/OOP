/*
 *  Polynomial.h
 *  Created on: Apr 4, 2019
 *  Author: Ayesha khan
 */
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include <iostream>
#include "Complex.cpp"
using namespace std;

class Polynomial {
	int x;
	int y;
	int z;
public:
	Polynomial();
	Polynomial(int a,int b,int c);
	Polynomial(const Polynomial &toCopy);
	int getX() const;
	void setX(int a);
	int getY() const;
	void setY(int b);
	int getZ() const;
	void setZ(int c);
	Polynomial operator =  (const Polynomial &rhs);
	bool operator == (const Polynomial &rhs);
	Polynomial operator +  (const Polynomial &rhs);
	Polynomial operator +=  (const Polynomial &rhs);
	Polynomial operator -= (const Polynomial &rhs);
	Polynomial operator -  (const Polynomial &rhs);
	Polynomial operator *  (double d);
	Polynomial operator *= (double d);
	operator string()const;
	double evaluate (int value);
	void roots(Complex &c1,Complex &c2);
	virtual ~Polynomial();
};

ostream & operator << (ostream &input, Polynomial const &pol);
istream & operator >> (istream &output, Polynomial &pol);

#endif /* POLYNOMIAL_H_ */
