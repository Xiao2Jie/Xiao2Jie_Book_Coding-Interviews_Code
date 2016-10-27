//输入一个二叉树和一个整数,打印出二叉树终结点值的和为输入整数的所有路径.从树的根节点开始往下一直到叶节点经过的节点形成一条路径.
#include<iostream>
#include<vector>
using namespace std;
typedef  struct BinaryTreeNode* Tree;
typedef Tree Node;
struct BinaryTreeNode
{
	Node Left;
	Node Right;
	int Value;
};
void FindPath(Node node, int expectValue, vector<int> vecPath, int curentValue)
{
	curentValue += node->Value;
	vecPath.push_back(node->Value);
	//是叶子节点并且路径和符合要求,就打印
	if(node->Left == NULL && node->Right == NULL && expectValue == curentValue)
	{
		for(int i = vecPath[0]; i < vecPath.size(); ++i)
		{
			cout<<vecPath[i]<<", ";
		}
		cout<<endl;
	}
	//不是叶子节点就继续向下访问
	if(node->Left)
		FindPath(node->Left, expectValue, vecPath, curentValue);
	if(node->Right)
		FindPath(node->Right, expectValue, vecPath, curentValue);
	 //退出函数时,会向上返回,要在路径中删除自身; 如果路径和符合要求,打印
	//,并在路径中删除自身,返回到父节点,如果路径和不符合要求,路径中删除自身,然后返回到父节点
	vecPath.pop_back();  
}
void FindPath(Tree tree, int expectValue)
{
	if(tree == NULL)
		return;
	vector<int> vecPath;
	int currentValue = 0;
	FindPath(tree, expectValue, vecPath, currentValue);
}
int main()
{
}
