/*
author:��˪��
ʱ�䣺2020.07.25
*/

#include<iostream>
using namespace std;
int main()
{
	int FindMin(int next[], int start, int end);
	int next[] = { 1,1,1,1,1,1,1,1,1 };
	int min = FindMin(next, 0, 8);
	cout << min << endl;
	return 0;
}
int FindMin(int next[],int start,int end)
{
	if (next == nullptr || start < 0 || end < 0)
	{
		throw new exception("���벻�Ϸ��������¼�������");
	}
	int temp_1 = next[start];
	int temp_2 = next[end];
	int mid_index = int((start + end) / 2);
	if (start == mid_index)
	{
		 return temp_1 > temp_2 ? temp_2 : temp_1;
	}
	//���������û����ת
	if (temp_1 < temp_2)
	{
		return temp_1;
	}
	else if(temp_1 > temp_2)
	{
		if (temp_1 == temp_2 && next[mid_index] == temp_1)
		{
			int i;
			for (i = start + 1; i <= end - 1; i++)
			{
				if (next[i] <= next[i - 1])
				{
					if (next[i] <= next[i + 1])
					{
						return next[i];
					}
				}
			}
			return next[i];
		}
		else if(next[mid_index] >= temp_1)
		{
			FindMin(next, mid_index, end);
		}
		else if (next[mid_index] <= temp_2)
		{
			FindMin(next, start, mid_index);
		}

	}


}
