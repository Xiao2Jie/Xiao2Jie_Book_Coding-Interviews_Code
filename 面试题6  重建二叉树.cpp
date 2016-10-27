struct BinaryTreeNode
{
	int m_nValue;
	struct BinaryTreeNode* m_nLeft;
	struct BinaryTreeNode* m_nRight;
};
BinaryTreeNode* Construct(int* preorder, int* inorder,int length)
{
	if(preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return CoonstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}
//前序遍历的第一个值是root, 然后在中序遍历中找到root,则root前面的节点是root的左子树的节点,可知左子树节点个数n,
//那么前序遍历中root后的n个节点都是左子树节点,其中第一个节点是根,因此依次递归遍历就可以重建二叉树.
BinaryTreeNode* CoonstructCore(int* StartPreorder, int* EndPreorder, int* StartInorder, int* EndInder)
{
	int rootValue = StartPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_nRight = root->m_nLeft = NULL;
	if(StartPreorder == EndPreorder)
	{
		if(StartInorder == EndInder && *StartPreorder == *StartInorder)
			return root;
		else
			throw std::expection("Invalid Input.");
	}
	int* rootInorder = StartInorder;
	while(rootInorder <= EndInder && *rootInorder != rootValue)
		++rootInorder;
	if(rootInorder == EndInder && *rootInorder != rootValue)
		throw std::expection("Invalid Input.");
	int leftLength = rootInorder - StartInorder;
	int* leftPreorderEnd = StartPreorder + leftLength;
	if(leftLength >= 0)
	{
		root->m_nLeft = CoonstructCore(StartPreorder+1, leftPreorderEnd, StartInorder, rootInorder-1);
	}
	if(leftLength < EndPreorder - StartPreorder)
	{
		root->m_nRight = CoonstructCore(leftPreorderEnd+1, EndPreorder, rootInorder+1, EndInder);
	}
	return root;
}
