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
	cout << HeadNode->data << "�ڵ��ַ" << HeadNode << endl;
	CreateBT(&((*T)->pLBT), HeadNode, &i, element);
	CreateBT(&((*T)->pRBT), HeadNode, &i, element);
	//traverseBT(t);
	char find_node = 'e';
	pBTN find_node_address = nullptr;
	Find_Node(HeadNode, find_node, &find_node_address);
	cout << "Ҫ���ҵĽڵ�Ϊ"<<find_node<< ','<<"�ýڵ��ַΪ"<< find_node_address << endl;
	pBTN NextNodeAddress = FindNextNodeInMidOrd(find_node_address);
	cout << find_node <<"��һ�����ĵ�ַΪ��" << NextNodeAddress << endl;
	return 0;
}

pBTN* CreateBT(pBTN* T, pBTN pFather, int* i, char element[])
{
	/*
		ע��˴�����ʹ�ö���ָ�� pBTN* T����ΪҪ�����޸ĵ�ʵ��Ϊָ�롣
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
			cout << ch <<"�ڵ��ַ" << *T << endl;
			CreateBT(&((*T)->pLBT), *T, i, element);
			CreateBT(&((*T)->pRBT), *T, i, element);
		}
	}
}


//��������ַ����Ǵ���ģ�Ҫ���ں����иı�ʵ�ε�ֵ��ֻ��ͨ��ָ��ʵ��
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
	//���ж��Ƿ���������������У�ֱ�������
	if (NowNode->pRBT == nullptr)
	{
		//���û�����������ж��Ƿ���Ϊ���ڵ��������������ǣ�ֱ��������ڵ㡣
		if ((NowNode->pFather)->pLBT == NowNode)
		{
			return NowNode->pFather;
		}
		//�����û����������Ҳ���Ǹ��ڵ����������
		//��Ѱ���Ƿ���ڸ����ڵ�Ϊ��������������ڣ�����������ĸ��ڵ㣬
		//��������ڣ���˵���ýڵ�Ϊ���һ���ڵ㣬��������һ���ڵ㡣
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
					cout << "�ýڵ�Ϊ���һ���ڵ㣡û����һ���ڵ�" << endl;
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
	cout << StartNode->data << "���ڵ��ַ��" << StartNode->pFather << endl;
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
			cout << "�ýڵ�Ϊ���ڵ�" << endl;
			*find_node_address  = nullptr;
		}
		else if (((StartNode->pFather)->pLBT)->data == Node)
		{
			cout << "�ýڵ��ַΪ" << (StartNode->pFather)->pLBT << endl;
			*find_node_address = (StartNode->pFather)->pLBT;
		}
		else if(((StartNode->pFather)->pRBT)->data == Node)
		{
			cout << "�ýڵ��ַΪ" << (StartNode->pFather)->pRBT << endl;
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