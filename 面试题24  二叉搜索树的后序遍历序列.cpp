//输入一个整数数组,判断该数组是不是某个二叉搜索树的后序遍历的结果,假设数组任意两个数不同
#include<iostream>
using namespace std;
//判断左子树的所有值是否都小于根,右子树的值是否都大于根,然后递归.
bool VerifyBinaryOfBST(int sequence[], int length)
{
	if(sequence == NULL || length <= 0)
		return false;
	int root = sequence[length-1];
	//i 为右子树的起点
	int i = 0;
	while(i < length-1)
	{
		if(sequence[i] > root)
			break;
		++i;
	}
	int j = i;
	while(j < length-1)
	{
		if(sequence[i] < root)
			return false;
		++j;
	}
	bool left = true;
	if(i > 0) //如果有左子树
		left = VerifyBinaryOfBST(sequence, i);  //0到i-1,共i个
	bool right = true;
	if(j<length-1)  //如果有右子树
		right = VerifyBinaryOfBST(sequence+i, length-i-1);       //i个左子树, 1个根,
	
	return (left &&right);
}
