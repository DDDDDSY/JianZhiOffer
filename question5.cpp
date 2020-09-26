#include<iostream>
#include <cstdio>
#include <cstring>

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
void replaceBlank(char str[], int length)
{
	int count = 0;
	int Len;//加上空格之后的长度
	int start_1, start_2;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	Len = length + count * 2;
	start_1 = length;
	start_2 = Len;
	while (start_2 != start_1)
	{
		while (str[start_1] != ' ')
		{
			str[start_2] = str[start_1];
			start_1--;
			start_2--;
		}
		str[start_2--] = '0';
		str[start_2--] = '2';
		str[start_2--] = '%';
		start_1--;
	}
	std::cout << str << std::endl;
}


int main()
{
	void replaceBlank(char str[], int length);
	char str[100] = "hello world";
	replaceBlank(str, 12);
}

