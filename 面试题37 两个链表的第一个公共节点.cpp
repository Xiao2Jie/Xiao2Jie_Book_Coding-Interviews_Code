/*如果两个链表有公共节点，那么从公共节点开始，他后面的节点就都相同了。
可以从后向前找出第一个不相同的节点，那么上一个就是第一个相同的，
可以先让长链表先走几步，直到长短相同，再同步走，直到第一个相同的*/
#include<iostream>
#include<stack>
using namespace std;
typedef  struct ListNode* Node;
struct ListNode  
{
	int Value;
	Node Next;
};
//运用两个栈
Node FindFirstCommonNode1(Node list1, Node list2)
{
	if(list1 == NULL || list2 == NULL)
	{
		return NULL;
	}
	stack<Node> stkFirst;
	stack<Node> stkSecond;
	while(list1->Next != NULL)
	{
		stkFirst.push(list1);
	}
	while(list2->Next != NULL)
	{
		stkSecond.push(list2);
	}
	Node lastCommonNode;
	while(stkFirst.empty() || stkSecond.empty())
	{
		if(stkFirst.top() == stkSecond.top())
		{
			lastCommonNode = stkFirst.top();
			stkFirst.pop();
			stkSecond.pop();
		}
		else
		{
			return lastCommonNode;
		}
	}
	return NULL;
}
//同步走
Node FindFirstCommonNode2(Node list1, Node list2)
{
	if(list1 == NULL || list2 == NULL)
	{
		return NULL;
	}
	int length1 = 0;
	int length2 = 0;
	while(list1->Next != NULL)
	{
		++length1;
	}
	while(list2->Next != NULL)
	{
		++length2;
	}
	int diff = abs(length1-length2);
	Node longList;
	Node shortList;
	if(length1 <= length2)
	{
		longList = list2;
		shortList = list1;
	}
	else
	{
		longList = list1;
		shortList = list2;
	}
	for(int i = 0; i < diff; ++i)
	{
		longList = longList->Next;
	}
	while(longList != shortList)
	{
		longList = longList->Next;
		shortList = shortList->Next;
	}
	return longList;
}
