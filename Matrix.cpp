#include"Matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	array2D = new float*[rows];
	for(int i=0;i<rows;i++)
		array2D[i] = new float[cols];
}
Matrix::Matrix(int r,int c)
{
	rows = r;
	cols = c;
	array2D = new float*[rows];
	for(int i=0;i<rows;i++)
		array2D[i] = new float[cols];
}
Matrix::Matrix(const Matrix &obj)
{
	rows = obj.rows;
	cols = obj.cols;
	array2d = new float*[rows];
	for(int i=0;i<rows;i++)
		array2D[i] = new float[cols];
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			array2D[i][j] = obt.array2D[i][j];
}
float& Matrix::operator() (int &i, int &j)
{
	if(i>=0 && i<rows && j>=0 && j<cols)
	{ 
		return array2D[i][j]; 
	}
	exit(1);
}
float& Matrix::operator() (int &i, int &j) const
{
	if(i>=0 && i<rows && j>=0 && j<cols)
	{ 
		return array2D[i][j];
	}
	exit(1);
}
Matrix& Matrix::operator=(const Matrix &obj)
{
	if(this==&obj)
		return *this;
	for(int i=0;i<rows;i++)
		delete []array2D[i];
	delete []mat;
	rows = obj.rows;
	cols = obj.cols;
	array2D = new float*[rows];
	for(int i=0;i<rows;i++)
		array2D[i] = new float[cols];
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			arrat2D[i][j] = obj.array2D[i][j];
	return *this;
}
bool Matrix::operator==(const Matrix &obj)
{
	if(rows!=obj.rows || cols!=obj.cols)
		return false;
	else
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if(array2D[i][j]!=obj.array2D[i][j])
					return false;
			}
		}
		return true;
	}
}
Matrix Matrix::operator+(const Matrix &obj)
{
	if(rows!=obj.rows || cols!=obj.cols)
	{ 
		cout<<"Can not be added"<<endl;
	}
	else
	{
		Matrix add(rows,cols);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				add.array2D[i][j] = array2D[i][j] + obj.array2D[i][j];
			}
		}
		return add;
	}
}
Matrix Matrix::operator-(const Matrix &obj)
{
	if(rows!=obj.rows || cols!=obj.cols)
	{ 
		cout<<"Can not be subtracted"<<endl; 
	}
	else
	{
		Matrix sub(rows,cols);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				sub.array2D[i][j] = array2D[i][j] - obj.array2D[i][j];
			}
		}
		return sub;
	}
}
Matrix Matrix::operator*(const Matrix &obj)
{
	if(cols!=obj.rows)
	{ 
		cout<<"Can not be multiplied"<< endl; 
	}
	else
	{
		Matrix mul(rows,obj.cols);
	    for(int i=0;i<rows;i++)
	    {
	        for(int j=0;j<obj.cols;j++)
	        {
	        	int sum=0;
	            for(int k=0;k<cols;k++)
	            { 
					sum += array2D[i][k] * obj.array2D[k][j]; 
				}
	            mul.array2D[i][j] = sum;
	        }
	    }
		return mul;
	}
}
Matrix Matrix::operator++(int)
{
	Matrix temp;
	temp = *this;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			array2D[i][j] += 1;
		}
	}
	return temp;
}
void Matrix::operator +=(const Matrix &obj)
{ 
	*this = *this + obj; 
}
void Matrix::operator -=(const Matrix &obj)
{ 
	*this = *this - obj; 
}
int Matrix::getCols() const
{ 
	return cols; 
}
int Matrix::getRows() const
{ 
	return rows; 
}
Matrix::~Matrix()
{
	for(int i=0;i<rows;i++)
	{
		delete []array2D[i];
	}
	delete []array2D;
}

void Matrix::fill()
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			array2D[i][j] =  (rand() % 10);
		}
	}
}

ostream& operator<< (ostream &input,const Matrix &obj)
{
	for(int i=0;i<obj.getRows();i++)
	{
		for(int j=0;j<obj.getCols();j++)
		{
			input<<obj(i,j)<<" ";
		}
		cout<<endl;
	}
	return input;
}
istream& operator>> (istream &output,Matrix &obj)
{
	for(int i=0;i<obj.getRows();i++)
	{
		for(int j=0;j<obj.getCols();j++)
		{
			cout<<"Input value -> row="<<i<<" col="<<j<<" :";
			output>>obj(i,j);
		}
	}
	return output;
}
