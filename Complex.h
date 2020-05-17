/*
 * Complex.h
 *
 *  Created on: Mar 27, 2019
 *      Author: lab
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex {
	double real;
	double imaginary;

public:
	Complex(double=0,double=0);
	virtual ~Complex();
	double getImaginary() const;
	void setImaginary(double imaginary);
	double getReal() const;
	void setReal(double real);
	Complex operator+(const Complex &obj);
	Complex operator-(const Complex &obj);
	Complex operator*(const Complex &obj);
	const Complex operator=(const Complex &obj);
	 bool operator==(const Complex &obj);
	 bool operator!()const;
};

#endif /* COMPLEX_H_ */
