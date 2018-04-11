#include "stdio.h"
#include "stdlib.h "

#define LIST_INIT_SIZE 100     //线性表大小 
#define LISTINCREMENT  10      //线性表大小增量 
#define OVERFLOW       1
#define OK             0
#define ERROR          2
typedef struct{
	int *elem; //线性表首地址 
	int length;
	int listsize;
}SqList; 

/* 
**   函数名：线性表初始化函数 
**   输入：线性表L 
**   输出：初始化成功与否（0/1） 
**   作用 ： 
*/
int InitList_Sq(SqList &L){
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int)); //malloc返回的是不确定类型的指针，所以返回之前必须经过类型强制转换 
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;			
} 

/* 
**   函数名：线性表固定位置插入数据 
**   输入：线性表L,位置i,数据e 
**   输出： 
**   作用 ： 
*/
int ListInsert_Sq(SqList &L,int i,int e){
	int *newbase;
	int *p,*q;
	if(i<1||i>L.length+1) return ERROR;
	if(L.length >= L.listsize){
		newbase = (int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase) exit(OVERFLOW); 
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i-1]); //q为插入位置 
	for(p = &(L.elem[L.length-1]); p>=q ;--p)  //插入位置及之后的右移 
		*(p+1) = *p;
	*q = e;
	++L.length;
	return OK;	
} 

/* 
**   函数名：线性表固定位置删除数据 
**   输入：线性表L,位置i,被删除的数据e 
**   输出： 
**   作用 ： 
*/
int ListDelect_Sq(SqList &L,int i,int &e){   //&e 传引用  形参的变化会改变实参 
	int *p,*q;
	if(i<1||i>L.length+1) return ERROR;	
	p = &(L.elem[i-1]);  //被删除元素的位置 
	e = *p;
	q = L.elem + L.length +1;
	for(++p; p<=q; ++p)
	 *(p-1) = *p;
	--L.length;
	return OK;
} 
/* 
**   函数名： 插入非重复元素e 
**   输入： 函数compare(int a,int b),待插入数e,线性表L 
**   输出： 
**    
*/
int LocateElem_Sq(SqList L,int e,int(* compare)(int,int)){ 
	int *p;
	int i;
	i = 1;
	p = L.elem;
	while(i<= L.length&&!(*compare)(*p++,e)) ++i;    //compare 返回值 
	if(i<= L.length) return i;
	else return 0;
} 

int main()
{
	SqList List1;
	int a;
	if(InitList_Sq(List1))
	{
		printf("Init error");
		exit(0);
	}
	//printf("The new list para is: \n");
	//printf("Add:%d\nLength:%d\nListsize:%d",List1.elem,List1.length,List1.listsize);
	ListInsert_Sq(List1,1,5);
	ListInsert_Sq(List1,2,19);
	ListInsert_Sq(List1,2,128);
	printf("%d\n",List1.elem[0]);  //List1.elem[1] = *(List1.elem+1)
	printf("%d\n",(List1.elem[1]));
	printf("%d\n",(List1.elem[2]));	
	printf("%d\n",List1.length); 
	ListDelect_Sq(List1,2,a);
	printf("%d\n-%d\n",(List1.elem[1]),a);
	printf("%d\n",List1.length); 
	//printf("%d-%d",&a,&b);  print a 为偏移地址 (a为指针)
}
