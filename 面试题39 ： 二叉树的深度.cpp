#include<windows.h>
typedef struct TreeNode* Node;
struct TreeNode
{
	int nValue;
	Node pLeft;
	Node pRight;
};
int BinaryTreeDepth(Node TreeRoot)
{
	if(TreeRoot == NULL)
		return 0;
	int nLeftDepth = BinaryTreeDepth(TreeRoot->pLeft);
	int nRightDepth = BinaryTreeDepth(TreeRoot->pRight);
	return (nLeftDepth > nRightDepth) ? nLeftDepth+1 : nRightDepth+1;
}
