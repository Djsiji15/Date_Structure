#include "stdio.h"


void move(char a, int n, char b)
{
	printf("move%d %c->%c\n",n,a,b);
}

void hanoi(int n,char x,char y,char z)   
{
	if(n==1)
		move(x,1,z);
	else
	{
		hanoi(n-1,x,z,y); //借助 y 移动 x 到 z 
		move(x,n,z);
		hanoi(n-1,y,x,z); //借助 z 移动 y 到 x	
	}	
}



int main()
{
	hanoi(3,'x','y','z');
}
