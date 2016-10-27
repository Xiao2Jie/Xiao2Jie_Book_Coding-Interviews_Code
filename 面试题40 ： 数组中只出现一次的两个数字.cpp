//有一个数组，有两个数字只出现一次，其他数字都出现了两次，求这两个只出现一次的数字。

//先用异或求出那两个数字的异或和，因为这两个数字不同，那么他们肯定有一位是不同的，那么//这个异或和的二进制肯定至少有一位是1，找出这个位置，再根据这个位置将这个数组分为两组，分别异或求和，最后这两个数组就剩下那两个数字了。
#include<iostream>
using namespace std;
//找到一个二进制数字中从右向左第一位是1的位置
unsigned int FindFirstBite1(unsigned int num)
{
	unsigned int n = 0;
	while(((num&1) == 0) && (n<8*sizeof(int)))
	{
		++n;
		num = num>>1;
	}
	return n;
}
     //一个二进制数字的某一位是不是1
bool IsBit1(unsigned int num, unsigned int index)
{
	num = num>>index;
	return num&1;
}
void FindTwoNumbersAppearanceOnce(int Array[], int length)
{
	if(Array == NULL || length < 2)
		return;
	int sum = 0;
	for(int i = 0; i < length; ++i)
		sum ^=Array[i];
	
	int index = FindFirstBite1(sum);
	int num1 = 0; 
	int num2 = 0;
	for(int i = 0; i < length; ++i)
	{
		if(IsBit1(Array[i], index))
			num1 ^=Array[i];
		else
			num2 ^=Array[i];
	}
	cout<<num1<<" "<<num2<<endl;
}
int main()
{
	int a[] = {1, 1, 2, 2, 3, 4 ,5 ,4, 6, 7,6, 5};
	FindTwoNumbersAppearanceOnce(a, 12);
}

