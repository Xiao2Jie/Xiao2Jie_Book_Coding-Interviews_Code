//如果直接遍历数组，则时间复杂度是O(n);
//如果用二分法分别找出第一次出现的位置和最后一次的位置，再相减，时间复杂度就是O(log(n));
#include<iostream>
using namespace std;
int GetFirstK(int Array[], int length, int K, int start, int end)
{
	if(Array == NULL || length <= 0 || start<0 || end<0 || start>end)
		return -1;
	int mid = (start+end)/2;
	int midData = Array[mid];
	if(midData == K)
	{
		if((mid > 0  && Array[mid-1] < K) || mid == 0)
			return mid;
		else
			return GetFirstK(Array, length, K, start, mid-1);
	}
	else if(midData > K)
	{
		return GetFirstK(Array, length, K, start, mid-1);
	}
	else
	{
		return GetFirstK(Array, length, K, mid+1, end);
	}
}
int GetLastK(int Array[], int length, int K, int start, int end)
{
	if(Array == NULL || length <= 0 || start<0 || end<0 || start>end)
		return -1;
	int mid = (start+end)/2;
	int midData = Array[mid];
	if(midData == K)
	{
		if((mid < length-1  && Array[mid+1] > K) || mid == length-1)
			return mid;
		else
			return GetLastK(Array, length, K, mid+1, end);
	}
	else if(midData > K)
	{
		return GetLastK(Array, length, K, start, mid-1);
	}
	else
	{
		return GetLastK(Array, length, K, mid+1, end);
	}
}
int GetNumberOfK(int Array[], int length, int K)
{
	if(Array == NULL || length <= 0)
		return -1;
	int first = GetFirstK(Array, length, K, 0, length-1);
	int last = GetLastK(Array, length, K, 0, length-1);
	if(first > -1 && last > -1)
		return last-first+1;
	else
		return 0;
}
int main()
{
	int a[]={1,2,3,3,3,3,4,4,5,6,7};
	cout<<GetNumberOfK(a, 10, 4)<<endl;
}
