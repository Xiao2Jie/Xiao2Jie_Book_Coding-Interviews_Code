//从上到下,从左到右,分层打印二叉树
//从上到下按层遍历二叉树,从本质上讲就是广度优先遍历二叉树,不管是广度优先遍历二叉树还是图,都要用到一个队列第一步我们把起始节点放入队列,接下来每次从队列头部取一个节点,遍历这个节点之后把从它能到达的节点(对于树来说是子节点)都一次放入队列,我们重复这个便利过程,直到队列为空为止.
#include<iostream>
#include<queue>
using namespace std;
typedef struct Tree* Node;
struct Tree
{
	Node Left;
	Node Right;
	int Value;
};
//每次弹出父节点打印时,都将左右子节点入队.
void PrintTreeByLayer(struct Tree* BinaryTree)
{
	if(BinaryTree == NULL)
		return;
	queue<Node>  queNode;
	queNode.push(BinaryTree);
	while(queNode.size())
	{
		Node node = queNode.front();
		queNode.pop();
		cout<<node->Value<<", ";
		if(node->Left)
			queNode.push(node->Left);
		if(node->Right)
			queNode.push(node->Right);
	}
}
