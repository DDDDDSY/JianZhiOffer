#include<iostream>
using namespace std;
typedef struct BTreeNode
{
	char data;
	BTreeNode* pLBT;
	BTreeNode* pRBT;
	BTreeNode* pFather;
}BTN,*pBTN;

int main() 
{
	pBTN* CreateBT(pBTN * T, pBTN pFather, int* i, char element[]);
	void Find_Node(pBTN NowNode, char Node, pBTN* find_node_address);
	pBTN FindNextNodeInMidOrd(pBTN NowNode);
	void traverseBT(pBTN StartNode);
	pBTN HeadNode = new BTN;
	HeadNode->pFather = nullptr;
	int i = 0;
	char element[] = {'b','d','#','#','e','h','#','#','i','#','#','c','f','#','#','g','#','#'};
	HeadNode->data = 'a';
	pBTN* T = &HeadNode;
	cout << HeadNode->data << "节点地址" << HeadNode << endl;
	CreateBT(&((*T)->pLBT), HeadNode, &i, element);
	CreateBT(&((*T)->pRBT), HeadNode, &i, element);
	//traverseBT(t);
	char find_node = 'e';
	pBTN find_node_address = nullptr;
	Find_Node(HeadNode, find_node, &find_node_address);
	cout << "要查找的节点为"<<find_node<< ','<<"该节点地址为"<< find_node_address << endl;
	pBTN NextNodeAddress = FindNextNodeInMidOrd(find_node_address);
	cout << find_node <<"下一个结点的地址为：" << NextNodeAddress << endl;
	return 0;
}

pBTN* CreateBT(pBTN* T, pBTN pFather, int* i, char element[])
{
	/*
		注意此处必须使用二级指针 pBTN* T，因为要保留修改的实参为指针。
	*/
	char ch = element[*i];
	(*i)++;
	if (ch == '#')
	{
		*T = nullptr;
	}
	else
	{
		*T = new BTN;
		if (!(*T))
		{
			exit(OVERFLOW);
		}
		else
		{
			(*T)->data = ch;
			(*T)->pFather = pFather;
			cout << ch <<"节点地址" << *T << endl;
			CreateBT(&((*T)->pLBT), *T, i, element);
			CreateBT(&((*T)->pRBT), *T, i, element);
		}
	}
}


//下面的这种方法是错误的，要想在函数中改变实参的值，只能通过指针实现
pBTN createBT(pBTN T)
{
	int data;
	cin >> data;
	if (data == '#')
	{
		T = nullptr;
	}
	else
	{
		pBTN pNew = new BTN;
		if (pNew == nullptr)
		{
			exit(OVERFLOW);
		}
		else
		{
			T = pNew;
			createBT(T->pLBT);
			createBT(T->pRBT);
		}
	}
}

pBTN FindNextNodeInMidOrd(pBTN NowNode)
{
	pBTN FatherNode;
	//先判段是否有右子树，如果有，直接输出。
	if (NowNode->pRBT == nullptr)
	{
		//如果没有右子树，判断是否本身为父节点的左子树，如果是，直接输出父节点。
		if ((NowNode->pFather)->pLBT == NowNode)
		{
			return NowNode->pFather;
		}
		//如果既没有右子树，也不是父节点的左子树，
		//就寻找是否存在父辈节点为左子树，如果存在，则输出父辈的父节点，
		//如果不存在，则说明该节点为最后一个节点，不存在下一个节点。
		else
		{
			FatherNode = NowNode->pFather;
			while (FatherNode != nullptr)
			{
				if (FatherNode->pFather != nullptr)
				{
					if ((FatherNode->pFather)->pLBT == FatherNode)
					{
						return FatherNode->pFather;
					}
					else
					{
						FatherNode = FatherNode->pFather;
					}
				}
				else
				{
					cout << "该节点为最后一个节点！没有下一个节点" << endl;
					return nullptr;
				}

			}
		}
	}
	else
	{
		return NowNode->pRBT;
	}
}

void traverseBT(pBTN StartNode)
{
	//cout << StartNode->data << endl;
	cout << StartNode->data << "父节点地址：" << StartNode->pFather << endl;
	if (StartNode->pLBT != nullptr)
	{
		traverseBT(StartNode->pLBT);
	}
	if (StartNode->pRBT != nullptr)
	{
		traverseBT(StartNode->pRBT);
	}
}

void Find_Node(pBTN StartNode, char Node, pBTN* find_node_address)
{
	if (StartNode->data == Node)
	{
		if (StartNode->pFather == nullptr)
		{
			cout << "该节点为根节点" << endl;
			*find_node_address  = nullptr;
		}
		else if (((StartNode->pFather)->pLBT)->data == Node)
		{
			cout << "该节点地址为" << (StartNode->pFather)->pLBT << endl;
			*find_node_address = (StartNode->pFather)->pLBT;
		}
		else if(((StartNode->pFather)->pRBT)->data == Node)
		{
			cout << "该节点地址为" << (StartNode->pFather)->pRBT << endl;
			*find_node_address = (StartNode->pFather)->pRBT;
		}
	}

	if (StartNode->pLBT != nullptr)
	{
		Find_Node(StartNode->pLBT, Node, find_node_address);
	}
	if (StartNode->pRBT != nullptr)
	{
		Find_Node(StartNode->pRBT, Node, find_node_address);
	}
}