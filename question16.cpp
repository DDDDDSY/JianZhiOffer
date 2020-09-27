#include<iostream>
using namespace std;
int main()
{
	double ABS(double n);
	double power(double base, int exponent);
	double PowerWithRecursion(double base, int exponent);
	double POW(double base, int exponent);
	double base = -4.0;
	int n = 5;
	cout << power(base, n) << endl;
	cout << POW(base, n) << endl;
	return 0;
}

int ABS(int n)
{
	if (n >= 0)
	{
		return n;
	}
	return -n;
}

double power(double base, int exponent)
{
	double result = 1;
	if (base == 0.0)
	{
		return 0;//此处设置为0的0次方为0
	}
	if (exponent == 0 && base != 0.0)
	{
		return 1.0;
	}
	for (int i = 0; i < ABS(exponent); i++)
	{
		result = result * base;
	}
	if (exponent > 0)
	{
		return result;
	}
	else
	{
		return 1.0 / result;
	}
}


//高效实现方法
double PowerWithRecursion(double base, int exponent)
{
	int exp = 2;
	double result = base;
	if (exponent == 0)
	{
		return 1.0;
	}
	if (exponent == 1)
	{
		return base;
	}
	while (exp < exponent)
	{
		result = result * result;
		exp = exp * 2;
	}
	if (exp == exponent)
	{
		return result; 
	}
	return result * PowerWithRecursion(base, exponent - (exp >> 1));

}

double POW(double base, int exponent)
{
	double result = 1;
	if (base == 0.0)
	{
		return 0;//此处设置为0的0次方为0
	}
	if (exponent == 0 && base != 0.0)
	{
		return 1.0;
	}
	result = PowerWithRecursion(base, ABS(exponent));
	if (exponent > 0)
	{
		return result;
	}
	else
	{
		return 1.0 / result;
	}
}
