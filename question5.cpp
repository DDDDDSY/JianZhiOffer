#include<iostream>
#include <cstdio>
#include <cstring>

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����
void replaceBlank(char str[], int length)
{
	int count = 0;
	int Len;//���Ͽո�֮��ĳ���
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

