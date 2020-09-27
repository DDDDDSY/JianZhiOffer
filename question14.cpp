#include<iostream>
using namespace std;
int main()
{
	int max_multiple(int number);
	int greedy_algorithm(int number);
	int number = 20;
	cout << max_multiple(number) << endl;
	cout << greedy_algorithm(number) << endl;
}


//线性规划解法，时间复杂度O(n^2),空间O(n)
int max_multiple(int number)
{
	if (number < 2)
	{
		return 0;
	}
	if (number == 2)
	{
		return 1;
	}
	if (number == 3)
	{
		return 2;
	}
	int* max = new int[number + 1];
	max[0] = 0;
	max[1] = 1;
	max[2] = 2;
	max[3] = 3;
	int temp = 0;
	int Max;
	for (int i = 4; i <= number; i++)
	{
		for (int j = 1; j <= i/2; j++)
		{
			if (max[j] * max[i - j] > temp)
			{
				temp = max[j] * max[i - j];
			}
		}
		max[i] = temp;
	}
	Max = max[number];
	delete[] max;
	return Max;
}


//贪心算法
int greedy_algorithm(int number)
{
	if (number <= 1)
	{
		return 0;
	}
	if (number <= 3)
	{
		return number-1;
	}
	if (number == 4)
	{
		return number;
	}
	int numberOfthree = number / 3;
	if (number - numberOfthree * 3 == 0)
	{
		return pow(3, numberOfthree);
	}
	if (number - numberOfthree * 3 == 1)
	{
		numberOfthree -= 1;
		return pow(3, numberOfthree) * 4;
	}
	if (number - numberOfthree * 3 == 2)
	{
		return pow(3, numberOfthree) * 2;
	}
	//上面三个判断句可简化为：numberOftwo = pow(2,(number - numberOfthree * 3)/2)
}