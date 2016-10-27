//在国际象棋棋盘上摆放八个皇后,要求任意两个不能再同一行,同一列,同一对角线,.
//先把一个8个数的数组用0~7填充,则每个排列都是一种放置方法,并且满足不在一行和一列,接下来求他们//的全排列,再判断是否满足不在一个对角线.
#include<iostream>
using namespace std;
void Swap(int &a, int &b)
{
	int temp = a;
	a= b;
	b = temp;
}
void EightQueen(int num[], int start)
{
	if(num == NULL || start < 0 || start >7)
		return;
	if(start == 7)
	{
		bool bUse = true;
		for(int i = 0; i < 8; ++i)
		{
			for(int j = i+1; j < 8; ++j)
			{
				if(abs(i-j)==abs(num[i]-num[j]))
				{
					bUse = false;
					break;
				}
			}
		}
		static int n = 0;
		if(bUse)
		{
			++n;
			cout<<n<<"   ";
			for(int i = 0; i< 8 ;++i)
			{
				cout<<num[i]<<", ";
			}
			cout<<endl;
		}
	}
	else
	{
		for(int i = start; i < 8; ++i)
		{
			Swap(num[i], num[start]);
			EightQueen(num, start+1);
			Swap(num[i], num[start]);
		}
	}
}
int main()
{
	int num[] = {0, 1, 2, 3, 4, 5, 6, 7};
	EightQueen(num, 0);
}

