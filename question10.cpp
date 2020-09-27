#include<iostream>
using namespace std;
int main()
{
	long long unsigned int fibonacci(unsigned int n);
	long long unsigned int Fibonacci(unsigned int n);
	unsigned int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	cout << Fibonacci(n) << endl;
	return 0;
}

//循环实现Fibonacci数列；
long long unsigned int fibonacci(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	long long unsigned int f_1 = 1;//代表f(n-1)
	long long unsigned int f_2 = 0;//代表f(n-2)
	long long unsigned int f_n;//代表f(n)
	for (int i = 2; i <= n; i++)
	{
		f_n = f_1 + f_2;
		f_2 = f_1;
		f_1 = f_n;
	}
	return f_n;
}

//递归实现Fibonacci。很明显当n大于40时，递归慢很多很多很多。
long long unsigned int Fibonacci(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//递归解决一次可以上 1 阶或者 2 阶，上 n 阶楼梯一共有多少种走法。
//循环实现Fibonacci数列；
long long unsigned int fibonacci(unsigned int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	long long unsigned int f_1 = 1;//代表f(n-1)
	long long unsigned int f_2 = 2;//代表f(n-2)
	long long unsigned int f_n;//代表f(n)
	for (int i = 3; i <= n; i++)
	{
		f_n = f_1 + f_2;
		f_2 = f_1;
		f_1 = f_n;
	}
	return f_n;
}