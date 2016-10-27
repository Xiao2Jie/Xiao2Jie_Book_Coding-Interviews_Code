//实现复制一个复杂连表,在复杂连表中吗,每个节点出了指向下个节点的指针外,还有一个指针指向任意一个节点或者为NULL
#include<iostream>
using namespace std;
 
typedef struct ListNode* List;
typedef List Node;
struct ListNode
{
	Node next;
	Node sibling;
	int value;
};
//将拷贝的节点放在原节点后面
void ClonComplexList1(List pHead)
{
	Node pNode = pHead;   //为了保存pHead的指针,供下个函数用
	if(pNode == NULL)
		return;
	while(pNode != NULL)
	{
		Node pCopyNode = (Node)malloc(sizeof(Node));
		pCopyNode->next = pNode->next;
		pNode->next = pCopyNode;
		pNode = pNode->next;
	}
}
//赋值拷贝节点sibling指向
void ClonComplexList2(List pHead)
{
	Node pNode = pHead; //为了保存pHead的指针,供下个函数用
	while(pNode != NULL)
	{
		Node pCopyNode = pNode->next;
		if(pNode->sibling != NULL)
		{
			pCopyNode->sibling = pNode->sibling->next;
		}
		pNode = pCopyNode->next;
	}
}
//将两个链表分离
List ClonComplexList3(List pHead)
{
	Node pNode = pHead;
	Node pCopyHead = NULL;  //为了保存pHead的指针,供返回用
	Node pCopyNode = NULL;
	if(pNode == NULL)
		return;
	pCopyNode = pCopyHead = pNode->next;
	pNode->next = pCopyNode->next;
	pNode = pNode->next;
	while(pNode != NULL)
	{
		pCopyNode->next = pNode->next;
		pCopyNode = pNode->next;
		pNode->next = pCopyNode->next;
		pNode = pNode->next;
	}
	return pCopyHead;
}
List ClonComplexList(List pHead)
{
	ClonComplexList1(pHead);
	ClonComplexList2(pHead);
	return	ClonComplexList3(pHead);
}
void main()
 {
 }
