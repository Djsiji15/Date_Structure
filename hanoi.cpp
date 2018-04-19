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
		hanoi(n-1,x,z,y); //���� y �ƶ� x �� z 
		move(x,n,z);
		hanoi(n-1,y,x,z); //���� z �ƶ� y �� x	
	}	
}



int main()
{
	hanoi(3,'x','y','z');
}
