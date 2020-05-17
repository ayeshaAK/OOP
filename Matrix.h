#ifndef MATRIX_H_
#define MATRIX_H_

#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	float **array2D;
	
public:

    Matrix();
    Matrix(int, int);
    Matrix(const Matrix &);
    Matrix& operator=(const Matrix &);
    bool operator==(const Matrix &);
    Matrix& operator ++();
    Matrix& operator ++(int ignoreMe);
    Matrix& operator --();
    Matrix& operator --(int ignoreMe); 
    Matrix operator+(int x);
    Matrix operator+(const Matrix &); 
    Matrix operator-(int x); 
    Matrix operator-(const Matrix &); 
    Matrix operator*(const Matrix &);
    Matrix operator*(int x); 
    Matrix operator/(int x);
    double operator~(); 
    operator string(); 
    ~Matrix();
};
    ostream& operator<<(ostream& output, const Matrix&);
    istream& operator>>(istream& input, Matrix&); 
#endif /* MATRIX_H_ */
