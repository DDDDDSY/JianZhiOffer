/*
author:dsy
time:2020/07/26
*/

#include<iostream>
const int Length=10;
using namespace std;
int main()
{
	char matrix[][4] = { {'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'} };
	bool find_path(char next[][4], char path[], int m, int n, int* length, int M, int N, char direction);
	bool Exist;
	char path = { 'b','f','c','e' };
	int M = 2, N = 3;//矩阵维度
	int length = 3;//路径的长度
	char direction = 'O';//随意赋初值
	for (int m = 0; m <=M; m++)
	{
		for (int n = 0; n <= N; n++)
		{
			Exist = find_path(next[][4], path[], m, n, &length, M, N, direction);
			if (Exist)
			{
				cout << "存在 bfce 路径" << endl;
			}
		}
	}
	return 0;
}


bool find_path(char next[][4],char path[],int m, int n,int* length,int M, int N, char direction)
{
	if (next == nullptr || path == nullptr || M < 0 || N < 0)
	{
		throw new exception("输入参数有问题，请检查后重新输入！");
	}
	if (*length == Length)
	{
		return true;
	}

	if (m+1 <= M)
	{
		if (next[m + 1][n] == path[*length] && direction != 'E')
		{
			*length = *length - 1;
			direction = 'W';//West
			find_path(next, path, m+1, n, length, M, N, direction);
		}
	}
	if (m-1 >= 0)
	{
		if (next[m - 1][n] == path[*length] && direction != 'W')
		{
			*length = *length - 1;
			direction = 'E';//East
			find_path(next, path, m-1, n, length, M, N, direction);
		}
	}
	if (n+1 <= N)
	{
		if (next[m][n+1] == path[*length] && direction != 'S')
		{
			*length = *length - 1;
			direction = 'N';//North
			find_path(next, path, m, n+1, length, M, N, direction);
		}
	}
	if (n - 1 >= 0)
	{
		if (next[m][n - 1] == path[*length] && direction != 'N')
		{
			*length = *length - 1;
			direction = 'S';//South
			find_path(next, path, m, n-1, length, M, N, direction);
		}
	}

 }