#include<iostream>
#include "Queue.h"
using namespace std;
int main()
{
	CQueue<char>queue;
	const int length = 11;
	char DataArray[length] = { 'a','b','c','d','e','f','g','h','i','j','k' };
	int j = 0;
	while (j < length)
	{
		queue.appendTail(DataArray[j]);
		j++;
	}

	char DeleteData;
	for(int i = 0; i < length; i++)
	{
		DeleteData = queue.deleteHead();
		cout << DeleteData << endl;
	}
	return 0;
}
