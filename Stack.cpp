#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S){
	S.base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base) exit(2);  //储存分配失败
	S.top = S.base;
	S.stacksize =  STACK_INIT_SIZE;
	return 0;
}

int GetTop(SqStack S,int &e){
	if(S.top==S.base) return 1;
	e = *(S.top-1);
	return 0;
}

int Push(SqStack &S,int e){
	if(S.top-S.base >= S.stacksize){
		S.base = (int *)realloc(S.base,(STACKINCREMENT+STACK_INIT_SIZE)*sizeof(int));
	if(!S.base) exit(2);
	S.top = S.base + S.stacksize;   //回到原位置 
	S.stacksize += STACKINCREMENT;	
	}
	*S.top++ = e;  //先赋值在加加 
	return 0;
}

int Pop(SqStack &S,int &e){
	if(S.top == S.base) return 1;
	e = *--S.top;
	return 0;
} 

int main()
{
	SqStack s1;
	char string[10];
	int length,i; 
	int state;
	int e; 
	InitStack(s1); 
	//括号匹配的检验 
	scanf("%s",&string);
	length = strlen(string);
	for(i=0;i<length;i++)
	{
		switch(string[i]) {
			case '(':Push(s1,')'); printf("("); break;
			case '[':Push(s1,']'); printf("["); break;
			case '{':Push(s1,'}'); printf("{"); break;
			case ')':
				state = Pop(s1,e);
				if(state)
					exit(4);
				if(e!=string[i])
					exit(3);
				break;	
			case ']':
				state = Pop(s1,e);
				if(state)
					exit(4);
				if(e!=string[i])
					exit(3);
				break;
			case '}':
				state = Pop(s1,e);
				if(state)
					exit(4);
				if(e!=string[i])
					exit(3);
				break;										
			default: break;
		}
	}
	printf("OK");
} 
 
