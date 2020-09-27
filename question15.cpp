#include<iostream>
using namespace std;
int main()
{
	int CountOneOfBinary_1(int number);
	int CountOneOfBinary_2(int number);
	int CountOneOfBinary_3(int number);
	int number = 0x80000000;
	//cout << CountOneOfBinary_1(number) << endl;
	cout << CountOneOfBinary_2(number) << endl;
	cout << CountOneOfBinary_3(number) << endl;
	return 0;
}


//方法1：该方法的问题在于只能处理无符号二进制数，
//如果存在有符号数则会变成死循环。
int CountOneOfBinary_1(int number)
{
	int count = 0,temp = 0;
	while (number)
	{
		temp = number & 1;
		if (temp)
		{
			count++;
		}
		number = number >> 1;
	}
	return count;
}

//方法2：是方法2的改进，改变移位的对象。
int CountOneOfBinary_2(int number)
{
	int count = 0;
	int unsigned key = 1;
	int temp = 0;
	while (key)
	{
		temp = key & number;
		if (temp)
		{
			count++;
		}
		key = key << 1;
	}
	return count;
}

//方法3：优秀版本
int CountOneOfBinary_3(int number)
{
	int count = 0;
	while (number)
	{
		number = (number - 1) & number;
		count++;
	}
	return count;
}

