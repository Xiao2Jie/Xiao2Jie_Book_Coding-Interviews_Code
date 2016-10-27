//输入两个递增序列的链表,合并这两个链表,使其还是递增序列
typedef struct List *Node;
struct List
{
	Node next;
	int value;
};
Node Merge(Node node1, Node node2)
{
	if(node1 == NULL)
		return node2;
	else if(node2 == NULL)
		return node1;
	Node head;
	if(node1->value >= node2->value)
	{
		head = node2;
		head->next = Merge(node1, node2->next);
	}
	else
	{
		head = node1;
		head->next = Merge(node->next, node2);
	}
	return head;
} 
