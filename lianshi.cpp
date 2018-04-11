#include "stdio.h"  //stand io
#include "stdlib.h" //stand lib

typedef struct LNodee{    // struct LNodee = LNode
	int data;
	struct LNodee *next; 
}LNode,*LinkList;       //�ṹ��ָ��  ->ָ��ָ���Ա 

typedef struct DuLNode{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

/* 
**   ���ã� ˫������Ľ��� 
**   ���룺 ����L,������n 
**   ����� 
**    
*/
void DuListCreate(DuLinkList &L,int n){
	int i;
	DuLinkList pnew,phead;
	phead = L;  // ����ͷָ�� 
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
	for(i=0;i<n;i++)   //���� 
	{		 
		printf("%d  ",p->data);
		p = p->prior;
	}
	for(i=0;i<n;i++)   //���� 
	{
		p = p->next; 
		printf("%d  ",p->data);
	}	
} 


/* 
**   �������� ���������� 
**   ���룺 ����L,������n 
**   ����� 
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
**   �������� չʾ����Ԫ�� 
**   ���룺 ����L,������n 
**   �����  
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
**   �������� ����Ԫ�غ��� 
**   ���룺 ����L,����λ��n,Ԫ��e 
**   �����  
**    
*/
void ListInsert(LinkList &L,int n, int e)
{
	int i=0;
	LinkList p,in; //������Ľڵ� in
	p = L; 
	in = (LinkList)malloc(sizeof(LNode));
	for(i=0;i<n-1;i++)
		p = p->next;
	in->next = p->next;	
	p->next = in;
	in->data = e;
}
/* 
**   �������� ɾ��Ԫ�غ��� 
**   ���룺 ����L,ɾ��λ��n,��ɾ��Ԫ��e 
**   �����  
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
