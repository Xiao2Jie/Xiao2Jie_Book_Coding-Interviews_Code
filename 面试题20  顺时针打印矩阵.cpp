//输入一个矩阵,按照从外向里依次顺时针打印每个数字
#include<iostream>
using namespace std;
void PrintOneCircle(int **Matrix, int columns, int rows, int start)
{
	int startX = start;
	int startY = start;
	int endX = columns-1-start;    //y坐标末尾
	int endY = rows-1-start;        //x坐标末尾
	//打印第一行
	for(int i = startY; i <= endY; ++i)   
	{
		cout<<Matrix[startX][i]<<", ";		
	}
	//打印右边一列,要求至少有两列
	if(endX > startX)   
	{
		for(int i =startX+1; i <= endX; ++i)
		{
			cout<<Matrix[i][endY]<<", ";
		}
	}
	//打印下面一行,要求至少要有两列,并且至少两行
	if(endX > startX && endY > startY)
	{
		for(int i = endY-1; i >= startY; --i)
		{
			cout<<Matrix[endX][i]<<", ";
		}
	}
	//打印左边一列,要求至少两列并且至少三行
	if(endY > startY && endX > startX+1)
	{
		for(int i = endX-1; i >= startX+1; --i)
		{
			cout<<Matrix[i][startY]<<", ";
		}
	}
}
//不知道具体行列个数的二维数组只能以指针的指针的形式传参
void CirclePrintMatrix(int **Matrix, int columns, int rows)
{
	if(Matrix == NULL || columns<=0 || rows <= 0)
		return;
	int start = 0;
	while(2*start < columns && 2*start < rows)
	{
		PrintOneCircle(Matrix, columns, rows, start);
		++start;
	}
}
int main()
{
	int M[4][4] = {1, 2, 3, 4,5,6,7,8,9,10,11,12,13,14,15,16};
	int **p = new int *[4];  
	for(int i = 0; i < 4; ++i)
	{
		p[i] = M[i];
	}
	CirclePrintMatrix(p ,4, 4);
}

