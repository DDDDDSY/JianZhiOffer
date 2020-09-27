/*
author:dsy
time:2020/07/26
*/

#include<iostream>
const int Length = 3;
using namespace std;
int main()
{
	char matrix[][4] = { {'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'} };
	bool find_path(char next[][4], char path[], int m, int n, int* length, int M, int N, char direction);
	bool exist, Exist = false;
	char path[] = { 'a','c','c','c' };
	int M = 2, N = 3;//矩阵维度
	int length;//路径的长度
	char direction;//随意赋初值
	for (int m = 0; m <= M; m++)
	{
		for (int n = 0; n <= N; n++)
		{
			exist = false;
			length = 0;//路径的长度
			direction = 'O';
			if (matrix[m][n] == path[length])
			{
				length++;
				exist = find_path(matrix, path, m, n, &length, M, N, direction);
			}
			Exist = Exist || exist;
		}
	}
	if (Exist)
	{
		cout << "存在该路径" << endl;
	}
	else
	{
		cout << "不存在该路径" << endl;
	}
	return 0;
}


bool find_path(char next[][4], char path[], int m, int n, int* length, int M, int N, char direction)
{
	bool path_1 = false, path_2 = false, path_3 = false, path_4 = false;
	if (next == nullptr || path == nullptr || M < 0 || N < 0)
	{
		throw new exception("输入参数有问题，请检查后重新输入！");
	}
	if (m + 1 <= M)
	{
		if (next[m + 1][n] == path[*length] && direction != 'E')
		{
			if (*length == Length)
			{
				return true;
			}
			*length = *length + 1;
			direction = 'W';//West
			path_1 = find_path(next, path, m + 1, n, length, M, N, direction);
		}

	}
	if (m - 1 >= 0)
	{
		if (next[m - 1][n] == path[*length] && direction != 'W')
		{
			if (*length == Length)
			{
				return true;
			}
			*length = *length + 1;
			direction = 'E';//East
			path_2 = find_path(next, path, m - 1, n, length, M, N, direction);
		}
	}
	if (n + 1 <= N)
	{
		if (next[m][n + 1] == path[*length] && direction != 'S')
		{
			if (*length == Length)
			{
				return true;
			}
			*length = *length + 1;
			direction = 'N';//North
			path_3 = find_path(next, path, m, n + 1, length, M, N, direction);
		}
	}
	if (n - 1 >= 0)
	{
		if (next[m][n - 1] == path[*length] && direction != 'N')
		{
			if (*length == Length)
			{
				return true;
			}
			*length = *length + 1;
			direction = 'S';//South
			path_4 = find_path(next, path, m, n - 1, length, M, N, direction);

		}

	}
	if (!(path_1||path_2 || path_3 || path_4))
	{
		return false;
	}

}