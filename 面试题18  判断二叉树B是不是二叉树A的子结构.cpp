//输入两颗二叉树A, B,判断B是不是A的子结构
typedef Tree* Node;
struct Tree
{
	Node LeftNode;
	Node RightNode;
	int value;
};
//判断NodeB是否是NodeA的子结构
bool HasSubTree(Node NodeA, Node NOdeB)
{
	bool result = false;
	if(NodeA != NULL && NOdeB != NULL)
	{
//先判断此节点是不是他们开始相同的节点,如果deepFind的返回值是true,则b是子结构,如果返回时false,则至少b不是从次节点开始的子结构,继续从次节点的左右节点开始寻找
		if(NodeA->value == NodeB->value)
			result = DeepFind(NodeA, NodeB);
		if(!result)
			result = HasSubTree(NodeA->LeftNode, NodeB);
		if(!result)
			result = HasSubTree(NodeA->RightNode, NodeB);
	}
	return result;
}
//找到节点值相同后,继续向下找
bool DeepFind(Node NodeA, Node NodeB)
{
	if(NodeB == NULL) 
		return true;
	if(NodeA == NULL)
		return false;
	if(NodeA->value != NodeB->value)
		return false;
	return DeepFind(NodeA->LeftNode, NodeB->LeftNode) && DeepFind(NodeA->RightNode, NodeB->RightNode);
}
