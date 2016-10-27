//输入数字n, 打印从1到n位的最大数字,如输入2, 打印1~99
#include<iostream>
using namespace std;
bool IncreaseOne(char* charNumber, int n)
{
	int nOverFlow = 0;   //某一位需要进一位
	int nSum = 0;   //某一位的数计算后的和
	bool bHighestOver = false;   //最高位要进位了
	if(charNumber == NULL || n<=0)
		throw exception("Invalid input.");
	for(int i = n-1; i >=0; --i)
	{
		if(i == n-1)
		{
			nSum = charNumber[i] - '0' + nOverFlow + 1;   //最低位
		}
		else
		{
			nSum = charNumber[i] - '0' + nOverFlow;   //其他位,  如果某运行到这一步,说明需要进位,否则早就退出了
		}
		if(nSum >=10)
		{
			nSum -= 10;
			nOverFlow = 1;
			charNumber[i] = nSum + '0';
			if(i == 0)
			{
				bHighestOver = true;
			}
		}
		else
		{
			charNumber[i] = nSum +'0';
			break;
		}
	}
	return bHighestOver;
}
void PrintNumber(char* charNumber, int n)
{
	if(charNumber == NULL || n <=0)
		return;
	bool bPrint = false;
	int i = 0;
	while(i< n+1)
	{
		if(charNumber[i] != '0' && bPrint == false)   //第一个非0的位
		{
			bPrint = true;
		}
		if(bPrint)
		{
			cout<<charNumber[i]<<" ";
		}
		++i;
	}
}
void PrintToMaxOfNDigits(int n)
{
	if(n<=0)
		return;
	char* charNumber = new char[n+1];   //char最后是'\0',
	for(int i = n-1; i >= 0; --i)
	{
		charNumber[i] = '0';
	}
	charNumber[n] = '\0';
	while(!IncreaseOne(charNumber, n))
	{
		PrintNumber(charNumber, n);
	}
	delete []charNumber;
	return;
}
int main()
{
	PrintToMaxOfNDigits(2);
}

//需要考虑数字很大的情况, long long都表示不了.