#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

//nhap x<y so thuc
void nhap (float &x , float &y)
{
	cout << "Nhap vao 2 so thuc x va y (x < y)" << endl;
	do
	{
		cout << "Nhap vao x (x < y): " << endl;
		cin >> x;
		cout << "Nhap vao y (x < y): " << endl;
		cin >> y;
		if (x >= y)
		{
			cout << "P(x,y) = exp(abs(x)) + abs(y) + sqrt(y-x) = 1" << endl;
		}
	}
	while (x >= y);
}

//P(x,y) = exp(abs(x)) + abs(y) + sqrt(y-x)
void task_1 (float x, float y)
{
	if (y > x)
	{
		double P = 0;
		P =  exp(abs(x)) + abs(y) + sqrt(y-x);
		cout << "P(x,y) = exp(abs(x)) + abs(y) + sqrt(y-x) = " << P << endl;
	}
}

//F(x,n) = 2020x + pow(x,2)/pow(2,2) ... + pow(x,n)/pow(n,n) 
void task_2 (float x, int &n)
{
	double F = 0;
	F = 2020*x;
	for (int i=2; i <= n; ++i)
	{
		/*cout << endl;
		cout << " "<< pow(x,n)/pow(n,n) <<endl;*/
		F += pow(x,n)/pow(n,n);
	}
	cout << "F(x,m) = 2020x + pow(x,2)/pow(2,2) ... + pow(x,m)/pow(m,m) = " << F;	
}

int main()
{
	float x,y;
	int n;
	nhap (x, y);
	cout << "Nhap vao so nguyen m: " << endl;
	cin >> n;
	task_1 (x, y);
	task_2 (x, n);
	return 0;
}

