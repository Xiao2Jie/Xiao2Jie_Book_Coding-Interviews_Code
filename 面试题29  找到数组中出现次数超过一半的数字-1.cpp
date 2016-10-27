//方法一: 找出排序在中间的那个数字. 但是不是先排序,而是只要找到排在中间的数字就行.
#include<iostream>
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
int FindMoreThanHalfNum(int *nArray, int nLength)
{
	if(nArray == NULL || nLength <= 0)
		throw exception("ERROR");
	int nMiddle = nLength>>1;
	int nBegin = 0;
	int nEnd = nLength-1;
	//找出排在中间的那个数的值就是.
	int nNum = Partion(nArray, nBegin, nEnd);
	while(nNum != nMiddle)
	{
		if(nNum > nMiddle)
		{
			nNum = Partion(nArray, nBegin, nNum-1);
		}
		else
		{
			nNum = Partion(nArray, nNum+1, nEnd);
		}
	}
	return nArray[nNum];
	/**
	*省略检查这个数是不是超过数组一半 的代码
	*/
}
int main()
{
	int a[] = {0, 1, 2, 2,2,2,2,2,2, 3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6};
	cout<<FindMoreThanHalfNum(a, 25);
}


//方法二:那个数字的出现次数比其他所有数字次数和要多,保存两个值,一个是数字,一个是次数,本次和上次不同数字则次数减一,相同则加1,如果次数为0,则保存此次的数字,最后的那个数字一定是想要的.
#include<iostream>
using namespace std;
 int FindMoreThanHalfNum(int * nArray, int nLength)
 {
	 if(nArray == NULL || nLength <=0)
		 throw exception("ERROR");
	 int nNum = nArray[0];
	 int nCount = 1;
	 for(int i = 1; i < nLength; ++i)
	 {
		 if(nArray[i] == nNum)
			 ++nCount;
		 else
		 {
			 --nCount;
			 if(!nCount)
			 {
				 nNum = nArray[i];
				 ++nCount;
			 }
		 }
	 }
	 //省略总次数检查
	 return nNum;
 }
int main()
{
	int a[] = {0, 1, 2, 2,2,2,2,2,2, 3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6};
	cout<<FindMoreThanHalfNum(a, 25)<<endl;
}
