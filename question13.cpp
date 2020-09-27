#include<iostream>
using namespace std;


bool* initial(int rows, int cols, int threshold)
{
	bool* matrix = new bool[rows * cols];
	if (rows < 0 || cols < 0 || threshold < 0)
	{
		throw new exception("输入参数错误！请检查后重新输入！");
	}
	for (int i = 0; i < rows * cols; i++)
	{
		matrix[i] = false;
	}
	return matrix;
}


bool check_number(int m, int n, int threshold)
{
	int sum_m = 0, sum_n = 0, sum = 0;
	while (m > 0)
	{
		sum_m += m % 10;
		m /= 10;
	}
	while (n > 0)
	{
		sum_n += n % 10;
		n /= 10;
	}
	sum = sum_m + sum_n;
	return sum <= threshold ? true : false;
}


int count_grid(bool* matrix, int M, int N, int m, int n, int limit_number)
{
	int count = 0;
	if (m >= 0 && n >= 0 && m < M && n < N && !matrix[m * N + n])
	{
		if (check_number(m, n, limit_number))
		{
			matrix[m * N + n] = true;
			int count_1 = count_grid(matrix, M, N, m + 1, n, limit_number);
			int count_2 = count_grid(matrix, M, N, m - 1, n, limit_number);
			int count_3 = count_grid(matrix, M, N, m, n + 1, limit_number);
			int count_4 = count_grid(matrix, M, N, m, n - 1, limit_number);
			count =1 + count_1 + count_2 + count_3 + count_4;
		}
	}

	return count;
}


int main()
{
	bool* initial(int rows, int cols, int threshold);
	bool check_number(int m, int n, int threshold);
	int count_grid(bool* matrix, int M, int N, int m, int n, int limit_number);

	int count=0;
	bool* matrix;
	int threshlod = 5;
	int rows = 10;
	int cols = 10;

	matrix = initial(rows, cols, threshlod);
	count = count_grid(matrix, rows, cols, 0, 0, threshlod);
	cout << count << endl;
	return 0;
}
