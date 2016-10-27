typedef struct ListNode* List;
struct ListNode
{
	int Value;
	struct ListNode* Next;
};
void ReverseList1(List list)   //使用递归
{
	if(list != NULL)
	{
		if(list->Next != NULL)
		{
			ReverseList(list->Next);
		}
		std::cout<<list->Value<<" ";
	}
}
void ReverseList2(List list)   //使用栈
{
	std::stack<List> stackList;
	struct ListNode* node = list;
	while(node != NULL)
	{
		stackList.push(node);
		node = node->Next;
	}
	while(!stackList.isEmpty())
	{
		std::cout<<stackList.top()->Value<<" ";
		stackList.pop();
	}
}
void ReverseList3(List list)    //反转指针指向
{
	List p = NULL;
	List temp = NULL;
	if(list != NULL)
	{
		return NULL;
	}else
	{
		temp = list->Next;
		while(temp->Next != NULL)
		{
			p = temp->Next;
			temp->Next = p->Next;
			p->Next = list->Next;
			list->Next = p;
		}
		while(list != NULL)
		{
			std::cout<<list->Value<<" ";
			list = list->Next;
		}
	}
}
//反转链表
ListNode* ReverseList2(ListNode* pHead)
{
    ListNode* pNode=pHead;//当前结点
    ListNode* pPrev=NULL;//当前结点的前一个结点
    while(pNode!=NULL)
    {
        ListNode* pNext=pNode->m_pNext;
        pNode->m_pNext=pPrev;//当前结点指向前一个结点
        pPrev=pNode;//pPrev和pNode往前移动。
        pNode=pNext;//这里要使用前面保存下来的pNext，不能使用pNode->m_pNext
    }
    return pPrev;//返回反转链表头指针。
}
