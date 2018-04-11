#include "stdio.h"  //stand io
#include "stdlib.h" //stand lib

typedef struct LNodee{    // struct LNodee = LNode
	int data;
	struct LNodee *next; 
}LNode,*LinkList;       //结构体指针  ->指针指向成员 

typedef struct DuLNode{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

/* 
**   作用： 双向链表的建立 
**   输入： 链表L,链表数n 
**   输出： 
**    
*/
void DuListCreate(DuLinkList &L,int n){
	int i;
	DuLinkList pnew,phead;
	phead = L;  // 保存头指针 
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->next = NULL;	
	L->prior = NULL;
	for(i=n;i>0;i--)
	{
		pnew = (DuLinkList)malloc(sizeof(DuLNode));
	//	printf("h1");
		scanf("%d",&pnew->data);
	//	printf("h2");
		pnew->next = L->next;
	//	printf("h3");
		pnew->prior =L;
	//	printf("h4");
		L->next = pnew;
		L = pnew;
	}
}


void DuListShow(DuLinkList &L,int n){
	int i;
	DuLinkList p;
	p = L;
	for(i=0;i<n;i++)   //逆序 
	{		 
		printf("%d  ",p->data);
		p = p->prior;
	}
	for(i=0;i<n;i++)   //正序 
	{
		p = p->next; 
		printf("%d  ",p->data);
	}	
} 


/* 
**   函数名： 倒叙建立链表 
**   输入： 链表L,链表数n 
**   输出： 
**    
*/
void CreateList_L(LinkList &L,int n){
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L ->next = NULL;
	for(i=n;i>0;--i){
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
}

/* 
**   函数名： 展示链表元素 
**   输入： 链表L,链表数n 
**   输出：  
**    
*/
void ListShow( LinkList &L, int n){
	int i;
	LinkList p=L;
	printf("The list item is:");
	for(i=n;i>0;i--){
		p = p->next;
		printf("%d  ",p->data);		 
	} 
	printf("\n");
}
/* 
**   函数名： 插入元素函数 
**   输入： 链表L,插入位置n,元素e 
**   输出：  
**    
*/
void ListInsert(LinkList &L,int n, int e)
{
	int i=0;
	LinkList p,in; //带插入的节点 in
	p = L; 
	in = (LinkList)malloc(sizeof(LNode));
	for(i=0;i<n-1;i++)
		p = p->next;
	in->next = p->next;	
	p->next = in;
	in->data = e;
}
/* 
**   函数名： 删除元素函数 
**   输入： 链表L,删除位置n,被删除元素e 
**   输出：  
**    
*/
void ListDelete(LinkList &L,int n, int &e)
{
	int j;
	LinkList p = L;
	LinkList q;
	while(p->next&&j<n-1)
	{
		p = p->next; ++j;	
	}
	q = p->next;
	e = q->data; 
	p->next = q->next;
	free(q);	
}

int main() {
	DuLinkList List2;
	DuListCreate(List2,5); 
	DuListShow(List2,5);
	return 0;
}
