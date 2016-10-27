//输入一个字符串.打印出该字符串中字符的所有排列.如输入abc, 打印abc,acb,bac, bca, cab,cba.
#include <iostream>
using namespace std;
void Swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}
void Permutation(char pStr[], int start, int end)
{
	if(start == end)
		cout<<pStr<<endl;
	else
	{
		for(int i = start; i<= end; ++i)
		{
			Swap(pStr[i], pStr[start]);
			Permutation(pStr, start+1, end);
			Swap(pStr[i], pStr[start]);   //已某一个字母开头的排列打印完后,回复成原状,再把start++,取后一个字母与开头交换.
		}
	}
}
int main()
{
	char p[] = "abc";
	Permutation(p, 0, strlen(p)-1);
	return 0;
}

