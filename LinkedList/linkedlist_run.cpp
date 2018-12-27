#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

//////////////////////////////////////////////////////////////////////////////////
//��������������
//���ߣ�Genng
//�޸����ڣ�2018.12.27
//�汾��v1.3
//All rights reserved
//��Ctrl+����������F12)����׷�ٺ���
//���Ի�����Visual Studio 2017
//�Ƽ�ͷ�ļ�����+c�ļ�ʵ������������+�������ļ��ļܹ������һЩ�ϴ����Ŀ���а�����
//
//////////////////////////////////////////////////////////////////////////////////


int ListLength(LinkList head) {
	int length = 0;
	if (head == NULL) return length;
	LinkList go;
	go = head;
	while (go->next) {
		length++;
		go = go->next;
	}
	return length;
}
LinkList InitList() {
	Node *head;
	head = (Node*)malloc(sizeof(Node));	//Ϊͷ������洢�ռ�
	head->next = NULL;
	return head;
}

LinkList CreateList_A(int length) {//ͷ�巨����������
	Node *head, *p;
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	int i, go = length;
	for (i = length; i>0; --i) {
		p = (LinkList)malloc(sizeof(Node));
		p->next = head->next;
		head->next = p;
	}
	return head;//headΪͷָ��
};

LinkList CreateList_B(int length) {//β�巨����������
	Node *head, *last;//headΪͷ��� 
	int go = 0;
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("OverFlow!\n");
		return head;
	}
	head->next = NULL;
	last = head;
	while (go<length) {
		Node *p;
		p = (Node*)malloc(sizeof(Node));
		last->next = p;
		last = p;
		/*	p->next=head->next;
		head->next=p;*///ͷ�巨 
		go++;
	}
	last->next = NULL;
	return head;
}
ElemType ListFormerInsert(LinkList head, int i, ElemType e) {
	Node *qian;//����ǰ�����
	qian = head;
	int go;
	for (go = 0; qian&&go<i - 1; go++) {
		qian = qian->next;
	} //��qian������qian
	if (!qian || go>i - 1) return ERROR;
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("OVERFLOW!");
		return OVERFLOW;
	}
	p->data = e;
	p->next = qian->next;
	qian->next = p;
	return e;
}

ElemType ListLaterInsert(LinkList head, int i, ElemType e) {
	Node *qian;//����ǰ�����
	qian = head;
	int go;
	for (go = 0; qian&&go<i; go++) {
		qian = qian->next;
	}//ֱ����qianָ���i�����
	if (!qian || go>i) return ERROR;
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = qian->next;
	qian->next = p;
	return e;
}

Status InverseLinkedList(LinkList head)
{
	LinkList p, q;  //p������������
	//����������������Ԫ�ز�������һ˵
	//���head->nextΪNULL��������Ϊ��
	//���head->next->nextΪNULL��������ֻ��һ��Ԫ��
	//����������������������һ���Ͳ���Ҫ����ֱ�����ԭͷ��㼴�ɡ�
	if (head == NULL) {
		printf("��������");
		return OK;
	}
	if (head->next == NULL) {
		printf("����Ϊ��");
		return OK;
	}
	if (head->next->next)
	{
		p = q = head->next; //p,s��ʼָ���һ�����
		p = p->next;       //pָ��ڶ������
		q->next = NULL;
		while (p)
		{
			q = p;        //sָ�������Ľ��
			p = p->next;   //pָ��ԭ�������һ�����
			//������
			q->next = head->next;
			head->next = q;           //��������˳���ܵߵ�
		}
		return OK;
	}
	else {
		return OK;
	}
}
void InverseLinkedList_D(LinkList head) {
	Node *p, *q, *r;
	q = head->next;
	p = NULL;
	while (q) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;
}

Status DeleteElement(LinkList head, int i, ElemType &e) {
	Node *qian;
	int go;
	qian = head;
	for (go = 0; qian && go< i - 1; go++) {
		qian = qian->next;
	}
	if (!qian || go > i - 1)
	{
		printf("�޷�ɾ����%d��Ԫ�أ�ɾ��ʧ��\n",i);
		e = 0;
		return ERROR;
	}
	Node *q;
	q = qian->next; qian->next = q->next;
	e = q->data;
	free(q);
	return OK;
}
Status PrintList(LinkList head) {//�������
	if (head == NULL) {
		printf("�������ڣ�");
		return OK;
	}
	LinkList p = head->next;//����p=head
	if (p == NULL) {
		printf("����Ϊ�գ�");
		return OK;
	}
	while (p) {//����while(p->next)
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}

Status ClearList(LinkList head) {
	LinkList p, q;
	p = head->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
	return OK;
}

Status DestroyList(LinkList &head) {
	LinkList q;
	while (head)
	{
		q = head->next;
		free(head);
		head = q;
	}
	return OK;
}

/*
//��չ�����ڴ�ֵ����ָ�룬�����õ���
//�����õ�����C++�﷨��Ҳ����˵�ļ���׺������.cpp�ſ���ʹ�ô����õ���
//���庯��
int test_A(int &a) {	//������
	a = 1;
	return a;
}
int test_B(int a) {		//��ֵ
	a = 1;
	return a;
}
int test_C(int *a) {	//��ָ��
	*a = 1;
	return *a;
}
//��main����Ϊ
int main() {
	int a = 2;
	int A, B, C;

	//�����õ��ã������������뺯���ڲ������ã���C��֧��
	A = test_A(a);
	printf("�����ã�a=%d, A=%d\n", a, A);

	//��ֵ���ã�����������һ�ݴ��뺯���ڲ�
	a = 2;
	B = test_B(a);
	printf("��ֵ��a=%d, B=%d\n", a, B);

	//��ָ����ã���������ַ���뺯���ڲ�
	a = 2;
	C = test_C(&a);
	printf("��ָ�룺a=%d, C=%d\n", a, C);

	system("pause");
	return 0;
}
*/