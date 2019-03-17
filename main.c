#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int elemType;

typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode,*LinkList;

//头插法建立单链表
LNode *creatList(){
	LNode *L,*s;
	int x;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("空间分配失败.\n");
		exit(0);
	}
	L->next = NULL;
	scanf("%d",&x);
	while(x != -999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}
//尾插法建立单链表
LNode *creatList2(){
	int x;
	LNode *L,*s,*r;
	L = (LNode *)malloc(sizeof(LNode));
	r = L;
	scanf("%d",&x);
	while(x != -999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
}
//单链表就地逆置
void SqList_reverse(LNode *L){
	//如果单链表为空或只有头结点或只有一个元素，不用进行逆置操作
	if(L == NULL || L->next == NULL || L->next->next == NULL)
		return;
	LNode *p,*q;
	p = L->next;       //将p指向链表的第一个元素
	L->next = NULL;		//将L链域指向空
	while(p != NULL){
		q = p->next;	//保存p的后继结点，防止断链
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
//遍历输出单链表
void printList(LNode *L){
	if(L == NULL)
		return;
	LNode *p = L->next;
	while(p){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
//在带头结点的单链表中第i个位置之前插入元素e
void ListInsert(LNode *L,int i,elemType e){
	LNode *p = L->next;
	int j = 1;
	while(p && j < i - 1){   //寻找第i-1个位置
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)     //如果插入位置过大，那么p=NULL,如果插入的位置是0或者负数，那么j>i-1
		return;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
//在带头结点的单链表L中，删除第i个元素，并由e返回
void ListDelete(LNode *L,int i,elemType *e){
	LNode *p = L->next;
	int j = 1;
	while(p && j < i - 1){
		p = p->next;
		++j;
	}
	if(!p || j > i-1)		//如果插入位置过大，那么p=NULL,如果插入的位置是0或者负数，那么j>i-1
		return;
	LNode *q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
}
int main(){
	LNode *L,*p,*p2;
	elemType e;
	L = creatList2();
	printList(L);
	//SqList_reverse(L);
	ListInsert(L,5,520);
	printList(L);
	ListDelete(L,5,&e);
	printList(L);
	system("pause");
	return 0;
}
