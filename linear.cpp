#include "stdio.h"
#include "stdlib.h "

#define LIST_INIT_SIZE 100     //���Ա��С 
#define LISTINCREMENT  10      //���Ա��С���� 
#define OVERFLOW       1
#define OK             0
#define ERROR          2
typedef struct{
	int *elem; //���Ա��׵�ַ 
	int length;
	int listsize;
}SqList; 

/* 
**   �����������Ա��ʼ������ 
**   ���룺���Ա�L 
**   �������ʼ���ɹ����0/1�� 
**   ���� �� 
*/
int InitList_Sq(SqList &L){
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int)); //malloc���ص��ǲ�ȷ�����͵�ָ�룬���Է���֮ǰ���뾭������ǿ��ת�� 
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;			
} 

/* 
**   �����������Ա�̶�λ�ò������� 
**   ���룺���Ա�L,λ��i,����e 
**   ����� 
**   ���� �� 
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
	q = &(L.elem[i-1]); //qΪ����λ�� 
	for(p = &(L.elem[L.length-1]); p>=q ;--p)  //����λ�ü�֮������� 
		*(p+1) = *p;
	*q = e;
	++L.length;
	return OK;	
} 

/* 
**   �����������Ա�̶�λ��ɾ������ 
**   ���룺���Ա�L,λ��i,��ɾ��������e 
**   ����� 
**   ���� �� 
*/
int ListDelect_Sq(SqList &L,int i,int &e){   //&e ������  �βεı仯��ı�ʵ�� 
	int *p,*q;
	if(i<1||i>L.length+1) return ERROR;	
	p = &(L.elem[i-1]);  //��ɾ��Ԫ�ص�λ�� 
	e = *p;
	q = L.elem + L.length +1;
	for(++p; p<=q; ++p)
	 *(p-1) = *p;
	--L.length;
	return OK;
} 
/* 
**   �������� ������ظ�Ԫ��e 
**   ���룺 ����compare(int a,int b),��������e,���Ա�L 
**   ����� 
**    
*/
int LocateElem_Sq(SqList L,int e,int(* compare)(int,int)){ 
	int *p;
	int i;
	i = 1;
	p = L.elem;
	while(i<= L.length&&!(*compare)(*p++,e)) ++i;    //compare ����ֵ 
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
	//printf("%d-%d",&a,&b);  print a Ϊƫ�Ƶ�ַ (aΪָ��)
}
