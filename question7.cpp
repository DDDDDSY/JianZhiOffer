#include<iostream>
using namespace std;
typedef struct BTreeNode
{
	int data;
	struct BTreeNode* pLBT;
	struct BTreeNode* pRBT;
}BTN,*pBTN;

struct TreeData
{
	int preStart;
	int preEnd;
	int midStart;
	int midEnd;
};


int main()
{
	void contruct_BT(TreeData * ordData, int PreSort[], int MidSort[], pBTN startNode);
	TreeData* ordData = new TreeData;
	ordData->midEnd = 7;
	ordData->midStart = 0;
	ordData->preEnd = 7;
	ordData->preStart = 0;
	int preOrd[] = { 1,2,4,7,3,5,6,8 };
	int midOrd[] = { 4,7,2,1,5,3,8,6 };
	pBTN pNew = new BTN;

	contruct_BT(ordData, preOrd, midOrd, pNew->pLBT);
	cout << "ÔËÐÐÍê±Ï" << endl;

}


void contruct_BT(TreeData*  ordData, int PreSort[], int MidSort[], pBTN startNode)
{
	int rootNode = PreSort[ordData->preStart];
	cout << rootNode << endl;
	pBTN pNew = new BTN;
	pNew->data = rootNode;
	startNode = pNew;
	TreeData temp = { ordData->preStart, ordData->preEnd, ordData->midStart, ordData->midEnd };
	TreeData* ordData_0 = new TreeData;
	TreeData* ordData_1 = new TreeData;
	if (ordData->midStart != ordData->midEnd)
	{
		while (temp.midStart <= temp.midEnd)
		{
			if (MidSort[temp.midStart] == rootNode)
			{
				if (temp.midStart > ordData->midStart)
				{
					ordData_0->preStart = ordData->preStart + 1;
					ordData_0->preEnd = ordData->preStart + temp.midStart - ordData->midStart;
					ordData_0->midEnd = temp.midStart - 1;
					ordData_0->midStart = ordData->midStart;
					contruct_BT(ordData_0, PreSort, MidSort, pNew->pLBT);
				}

				if (temp.midStart < ordData->midEnd)
				{
					ordData_1->midStart = temp.midStart + 1;
					ordData_1->midEnd = ordData->midEnd;
					ordData_1->preStart = ordData->preEnd - (ordData_1->midEnd - ordData_1->midStart);
					ordData_1->preEnd = ordData->preEnd;
					contruct_BT(ordData_1, PreSort, MidSort, pNew->pRBT);
				}
				break;
			}
			else
			{
				temp.midStart++;
			}
		}
	}
}