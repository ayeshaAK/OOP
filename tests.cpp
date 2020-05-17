#include "Complex.h"
#include "Matrix.h"
#include "Polynomial.h"
#include <gtest/gtest.h>


// ____________________________QUESTION 1a ___________________________________________

TEST(Polynominal, Constructors) { 

Polynomial x(4,3,2);
string s1=(string)x;
string s2="4x^2 + 3x + 2";
ASSERT_EQ(0, s1.compare(s2));



}

TEST(Polynominal, EqualityOperator) { 

Polynomial x(4,3,1);

Polynomial y=x;
string s1=(string)y;
string s2="4x^2 + 3x + 1";
ASSERT_EQ(0, s1.compare(s2));



}

TEST(Polynominal, ComparisonOperator) { 

Polynomial x(4,3,1);
Polynomial y(5,3,1);
Polynomial z(5,3,1);
ASSERT_EQ(false, x==y);
ASSERT_EQ(true, z==y);


}

TEST(Polynominal, ArithmeticOperatorsplus) { 

Polynomial x(4,3,1);
Polynomial z(0,1,1);
Polynomial y=x+z;
string s3=(string)y;
string s4="4x^2 + 4x + 2";
ASSERT_EQ(0, s3.compare(s4));



}

TEST(Polynominal, ArithmeticOperatorssub) { 
Polynomial x(4,3,1);
Polynomial z(0,1,1);
Polynomial y=x-z;
string s3=(string)y;
string s4="4x^2 + 2x";
ASSERT_EQ(0, s3.compare(s4));

}

TEST(Polynominal, ArithmeticOperatorMul) { 
Polynomial x(2,0,1);

Polynomial y=x*2;
string s3=(string)y;
string s4="4x^2 + 2";
ASSERT_EQ(0, s3.compare(s4));

}


// ____________________________QUESTION 1b ___________________________________________


TEST(Polynominal, Evaluation) { 
Polynomial x(2,1,1);
int a=4;
int y=x.evaluate(a);
ASSERT_EQ((int)37, y);

Polynomial z(0,2,1);
y=z.evaluate(a);
cout<<y<<endl;
ASSERT_EQ((int)9, y);

}



TEST(Polynominal, Roots) { 
Polynomial x(2,10,1);
Complex c1,c2;
x.roots(c1,c2);
cout<<c1.getReal()<< "+" <<c1.getImaginary()<<"i"<<endl;  // match getter/setter accordingly
// should display 0.5+1.65831i

cout<<c2.getReal()<< "+" <<c2.getImaginary()<<"i"<<endl;  // match getter/setter accordingly
// should display 0.5−1.65831i
}


// ____________________________QUESTION 2 ___________________________________________

TEST(Matrix, Constructors)
 { 
 Matrix a(2,2);
string s1="2X2\n0-0\n0-0";
string s2=(string)a;
ASSERT_EQ(0, s1.compare(s2));
 
}


TEST(Matrix, Assignmnet)
 { 
 
string s1="2X2\n4-2\n4-2";
Matrix c;
cin>>c;  //enter 4,2,4,2
string s2=(string)c;
ASSERT_EQ(0, s1.compare(s2));
 
}

TEST(Matrix, ArithmeticOperatorsplus)
 { 
 
Matrix c(2,2);
cin>>c;  //enter 4,2,4,2
c=c+2;
string s1="2X2\n6-4\n6-4";
string s2=(string)c;
ASSERT_EQ(0, s1.compare(s2));


c=c+c;
string s3="2X2\n12-8\n12-8";
string s4=(string)c;
ASSERT_EQ(0, s3.compare(s4));
 
}

TEST(Matrix, ArithmeticOperatorssub)
 { 
 
Matrix c(2,2);
cin>>c;  //enter 4,2,4,2
c=c-2;
string s1="2X2\n2-0\n2-0";
string s2=(string)c;
ASSERT_EQ(0, s1.compare(s2));


c=c-c;
string s3="2X2\n0-0\n0-0";
string s4=(string)c;
ASSERT_EQ(0, s3.compare(s4));
 
}

TEST(Matrix, UnaryOperators)
{

	Matrix c(2, 2);
	cin >> c;  //enter 4,2,4,2
	c++;
	string s1 = "2X2\n5-3\n5-3";
	string s2 = (string)c;
	ASSERT_EQ(0, s1.compare(s2));

	c--;
	string s3 = "2X2\n04-2\n4-2";
	string s4 = (string)c;
	ASSERT_EQ(0, s3.compare(s4));
	++c;
	string s5 = "2X2\n5-3\n5-3";
	string s6 = (string)c;
	ASSERT_EQ(0, s5.compare(s6));

	c--;
	string s7 = "2X2\n04-2\n4-2";
	string s8 = (string)c;
	ASSERT_EQ(0, s7.compare(s8));
	


}


TEST(Matrix, ArithmeticOperatorsMul)
 { 
 
Matrix c(2,2);
cin>>c;  //enter 4,2,4,2
c=c*2;
string s1="2X2\n8-4\n8-4";
string s2=(string)c;
ASSERT_EQ(0, s1.compare(s2));

 
}


TEST(Matrix, ArithmeticOperatorsDivision)
 { 
Matrix c(2,2);
cin>>c;  //enter 4,2,4,2
c=c/2;
string s1="2X2\n2-1\n2-1";
string s2=(string)c;
ASSERT_EQ(0, s1.compare(s2));

 
}


TEST(Matrix, Determinant)
 { 
 
Matrix c(2,2);
cin>>c;  //enter 2,1,3,4
int d=~c;
ASSERT_EQ(5, d);
Matrix e(2,3);
int f=~e;
ASSERT_EQ(-1, f);

 
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
