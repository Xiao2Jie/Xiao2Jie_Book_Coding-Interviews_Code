#include<iostream>
using namespace std;
//常规方法
int FindMaxSumOfSubArray1(int Array[], int length)
{
	if(Array == NULL || length <= 0)
	{
		throw exception("ERROR");
	}
	int nMax = 0;
	int nCurSum = 0;
	for(int i = 0; i< length; ++i)
	{
		if(nCurSum<=0)
			nCurSum = Array[i];
		else
			nCurSum +=Array[i];
		if(nCurSum > nMax)
		{
			nMax = nCurSum;
		}
	}
	return nMax;
}
int FindMaxSumOfSubArray2(int Array[], int length)
{
	if(Array == NULL || length <= 0)
	{
		throw exception("ERROR");
	}
	//运用动态规划,f(i)表示以array[i]结尾的子数组的最大和, 求出所有的f(i)的最大值就行
	//如果f(i-1)<=0, 则f(i)=array[i], 否则f(i)=f(i-1)+array[i];
	int nPre = Array[0];   //表示以前一个数结尾的序列的最大值
	int nCur = 0;   //表示以当前数结尾的序列的最大值
	int nMax = 0x80000000;//代表int型最小的负数, 用于保存f(i)的最大值
	for(int i = 1; i< length; ++i)
	{
		if(nPre <= 0)
			nCur = Array[i];
		else
			nCur = nPre+Array[i];
		nPre = nCur;
		if(nCur > nMax)
			nMax = nCur;
	}
	return nMax;
}
int main()
{
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	cout<<FindMaxSumOfSubArray2(a, 8)<<endl;
}
