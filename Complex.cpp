/*
 * Complex.cpp
 */

#include "Complex.h"

Complex::Complex(double r, double i) {
	// TODO Auto-generated constructor stub
	real=r;
	imaginary=i;
}

double Complex::getImaginary() const {
	return imaginary;
}

void Complex::setImaginary(double imaginary) {
	this->imaginary = imaginary;
}

double Complex::getReal() const {
	return real;
}

void Complex::setReal(double real) {
	this->real = real;
}
Complex Complex::operator+(const Complex &obj){
	this->real=this->real+obj.real;
	this->imaginary=this->imaginary+obj.imaginary;
	return *this;

}
Complex Complex::operator-(const Complex &obj){
	this->real=this->real-obj.real;
	this->imaginary=this->imaginary-obj.imaginary;
	return *this;

}
Complex Complex::operator*(const Complex &obj){
	this->real=(this->real*obj.real)-(this->imaginary*obj.imaginary);
	this->imaginary=(this->imaginary*obj.real)+(this->real*obj.imaginary);
	return *this;
}
const Complex Complex::operator=(const Complex &obj){
		this->real=obj.real;
		this->imaginary=obj.imaginary;
		return *this;

}
bool Complex::operator==(const Complex &obj){
	if(this->real==obj.real && this->imaginary==obj.imaginary)
	{
		return true;
	}
	else{
		return false;
	}

}
bool Complex::operator!()const{
	if(this->real==0 && this->imaginary==0)
	{
		return true;
	}
	else{
		return false;
	}
}

Complex::~Complex()
{
}

