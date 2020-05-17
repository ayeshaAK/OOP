/*
 * Polynomial.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: lab
 */

#include "Polynomial.h"
#include <string>
#include<sstream>
#include<cmath>

//Default constructor;
Polynomial::Polynomial()
{

	x = 0;
	y = 0;
	z = 0;
}

//Parameterized Constructor;
Polynomial::Polynomial(int a, int b, int c)
{
	x = a;
	y = b;
	z = c;
}

//Copy Constructor;
Polynomial::Polynomial(const Polynomial &toCopy)
{
	x = toCopy.x;
	y = toCopy.y;
	z = toCopy.z;
}

//Getters and Setters;
int Polynomial::getX() const {
	return x;
}

void Polynomial::setX(int a) {
	this->x = a;
}

int Polynomial::getY() const {
	return y;
}

void Polynomial::setY(int b) {
	this->y = b;
}

int Polynomial::getZ() const {
	return z;
}

void Polynomial::setZ(int c) {
	this->z = c;
}

//Operator Overloading;
Polynomial Polynomial::operator =(const Polynomial &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}
bool Polynomial::operator ==(const Polynomial &rhs)
{
	if((this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Polynomial Polynomial::operator +(const Polynomial &rhs)
{
	x = x + rhs.x;
	y = y + rhs.y;
	z = z + rhs.z;
	return *this;
}
Polynomial Polynomial::operator += (const Polynomial &rhs)
{
	*this = *this + rhs;
	return *this;
}
Polynomial Polynomial::operator-(const Polynomial &rhs)
{
	x = x - rhs.x;
	y = y - rhs.y;
	z = z - rhs.z;
	return *this;
}
Polynomial Polynomial::operator -= (const Polynomial &rhs)
{
	*this = *this - rhs;
	return *this;
}
Polynomial Polynomial::operator *(double d)
{
	this->x = x * d;
	this->y = y * d;
	this->z = z * d;
	return *this;
}
Polynomial Polynomial::operator *= (double d)
{
	*this = *this * d;
	return *this;
}
Polynomial::operator string() const
{
	string a,b,c;
	stringstream x2, x1, cons;
	if(x>=0)
	{
		x2 << x;
		a = "+(" + x2.str() + ")x^2";
	}
	else
	{

		x2 << -x;
		a = "-(" + x2.str() + ")x^2";
	}
	if(y>=0)
	{
		x1 << y;
		b = "+(" + x1.str() + ")x";
	}
	else
	{

		x1 << -y;
		b = "-(" + x1.str() + ")x";
	}
	if(z>=0)
	{
		cons  << z;
		c = "+(" + cons.str() + ")";
	}
	else
	{

		cons  << -z;
		c = "-(" + cons.str() + ")";
	}

	return a+b+c;
}
double Polynomial::evaluate (int value)
{
	double temp = 0.0;
	temp = x*(pow(value,2)) + y*value + z;
	return temp;
}
//Finding Roots;
void Polynomial::roots(Complex &c1,Complex &c2)
{
	int disc = pow(y,2) - 4*x*z;
	int root1 = (-y + sqrt(disc)) / (2*x);
	int root2 = (-y - sqrt(disc)) / (2*x);
	if(disc < 0)
	{
		c1.setImaginary(root1);
		c2.setImaginary(root2);
		c1.setReal(0);
		c2.setReal(0);
	}
	else
	{
		c1.setImaginary(0);
		c2.setImaginary(0);
		c1.setReal(root1);
		c2.setReal(root2);
	}
	
}
//Destructor;
Polynomial::~Polynomial()
{
	// TODO Auto-generated destructor stub
}

ostream & operator << (ostream &input, Polynomial &pol)
{
	cout << "Your Polynomial:  ";
	cout << string(pol) << endl;
	return input;
}

istream & operator >> (istream &output,Polynomial &pol)
{
	int a, b, c;
	cout << "Enter co-efficient of x^2 : ";
	cin >> a;
	cout << "Enter co-efficient of x : ";
	cin >> b;
	cout << "Enter co-efficient of constant : ";
	cin >> c;
	pol.setX(a);
	pol.setY(b);
	pol.setZ(c);
	return output;
}








