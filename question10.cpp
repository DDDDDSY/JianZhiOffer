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

//ѭ��ʵ��Fibonacci���У�
long long unsigned int fibonacci(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	long long unsigned int f_1 = 1;//����f(n-1)
	long long unsigned int f_2 = 0;//����f(n-2)
	long long unsigned int f_n;//����f(n)
	for (int i = 2; i <= n; i++)
	{
		f_n = f_1 + f_2;
		f_2 = f_1;
		f_1 = f_n;
	}
	return f_n;
}

//�ݹ�ʵ��Fibonacci�������Ե�n����40ʱ���ݹ����ܶ�ܶ�ܶࡣ
long long unsigned int Fibonacci(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//�ݹ���һ�ο����� 1 �׻��� 2 �ף��� n ��¥��һ���ж������߷���
//ѭ��ʵ��Fibonacci���У�
long long unsigned int fibonacci(unsigned int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	long long unsigned int f_1 = 1;//����f(n-1)
	long long unsigned int f_2 = 2;//����f(n-2)
	long long unsigned int f_n;//����f(n)
	for (int i = 3; i <= n; i++)
	{
		f_n = f_1 + f_2;
		f_2 = f_1;
		f_1 = f_n;
	}
	return f_n;
}