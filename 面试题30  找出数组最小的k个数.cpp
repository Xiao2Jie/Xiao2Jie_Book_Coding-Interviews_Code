//方法1 : 通过类似快排的方法找到排在第k+1位置的数,并且左边都是比他小的,因此桌面的书就是k个最小的数
#include<iostream>
#include<vector>
using namespace std;
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//和快排类似, 找一个枢纽元,把小于枢纽元的数放在枢纽元左边, 返回枢纽元的位置
int Partion(int *nArray, int nBegin, int nEnd)
{
	if(nArray == NULL|| nBegin <0 || nEnd<0)
		throw exception("ERROR");
	int nPivot = nArray[nBegin];  //枢纽元
	int nLeft = nBegin;
	int nRight = nEnd;
	while(nLeft != nRight)
	{
		while(nArray[nRight]>=nPivot && nLeft < nRight)
			--nRight;
		while(nArray[nLeft]<=nPivot && nLeft < nRight)
			++nLeft;
		if(nLeft<nRight)
		{
			Swap(nArray[nLeft], nArray[nRight]);
		}
	}
	Swap(nArray[nBegin], nArray[nLeft]);
	return nLeft;
}
void GetLeastNum(int *nArray, int nLength, int k)
{
	if(nArray == NULL || nLength <= 0)
		throw exception("ERROR");
	int nBegin = 0;
	int nEnd = nLength-1;
	//找出排在第k+1个位置的那个数的值.
	int nNum = Partion(nArray, nBegin, nEnd);
	while(nNum != k+1)
	{
		if(nNum > k+1)
		{
			nNum = Partion(nArray, nBegin, nNum-1);
		}
		else
		{
			nNum = Partion(nArray, nNum+1, nEnd);
		}
	}
	for(int i = 0; i < k;++i)
	{
		cout<<nArray[i]<<", ";
	}
	cout<<endl;
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	GetLeastNum(a, 10, 5);
}
