#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int elemType;

typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode,*LinkList;

//ͷ�巨����������
LNode *creatList(){
	LNode *L,*s;
	int x;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("�ռ����ʧ��.\n");
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
//β�巨����������
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
//������͵�����
void SqList_reverse(LNode *L){
	//���������Ϊ�ջ�ֻ��ͷ����ֻ��һ��Ԫ�أ����ý������ò���
	if(L == NULL || L->next == NULL || L->next->next == NULL)
		return;
	LNode *p,*q;
	p = L->next;       //��pָ������ĵ�һ��Ԫ��
	L->next = NULL;		//��L����ָ���
	while(p != NULL){
		q = p->next;	//����p�ĺ�̽�㣬��ֹ����
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
//�������������
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
//�ڴ�ͷ���ĵ������е�i��λ��֮ǰ����Ԫ��e
void ListInsert(LNode *L,int i,elemType e){
	LNode *p = L->next;
	int j = 1;
	while(p && j < i - 1){   //Ѱ�ҵ�i-1��λ��
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)
		return;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�����e����
void ListDelete(LNode *L,int i,elemType *e){
	LNode *p = L->next;
	int j = 1;
	while(p && j < i - 1){
		p = p->next;
		++j;
	}
	if(!p || j > i-1)		// ����ѭ����������pΪ�գ���iΪ0����ʱ����˵��λ�ò�����
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
