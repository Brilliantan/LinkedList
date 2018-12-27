#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

//////////////////////////////////////////////////////////////////////////////////
//��������������
//���ߣ�Geng
//�޸����ڣ�2018.12.27
//�汾��v1.2
//All rights reserved
//��Ctrl+����������F12)����׷�ٺ���
//���Ի�����Visual Studio 2017
//�Ƽ�ͷ�ļ�����+c�ļ�ʵ������������+�������ļ��ļܹ������һЩ�ϴ����Ŀ���а�����
//////////////////////////////////////////////////////////////////////////////////

#define  TRUE  1  
#define  FALSE 0 
#define  OK    1 
#define  ERROR  0
#define  OVERFLOW   -2  
#define  MALLOC_ERROR  -3
typedef int Status;
typedef int ElemType;  //������Ԫ��,�ݶ�Ϊint����

typedef struct LNode {
	ElemType data;		//������������
	struct LNode *next;	//������ָ���򡣸�ָ��ָ��һ��LNode�ͽ�㣬��ָ����һ��������ṹ��
}Node, *LinkList;	//ͨ��InitList���������Խ�LinkList��Ϊͷ��㡣

//�����󳤣����س���
int ListLength(LinkList head);

//����ȫ�հ���������ͷָ��
LinkList InitList();

//ͷ�巨��������������ͷָ��
LinkList CreateList_A(int length);

//β�巨��������������ͷָ��
LinkList CreateList_B(int length);

//�����������ͷָ��
Status ClearList(LinkList head);

//��������ʲôҲ��ʣ��
Status DestroyList(LinkList &head);		//�����õ��á����Ը�Ϊ��ָ�����Ч��һ������������㡣

//�ڵ�i��Ԫ��ǰ����Ԫ��e��ListFormerInsert����������һ���հ������в���Ԫ�أ���ʱӦ��i=1.
ElemType ListFormerInsert(LinkList head, int i, ElemType e);

//�ڵ�i��Ԫ��֮�����Ԫ��e��ListLaterInsert���������ڿհ������в���Ԫ�أ���ʱӦ��i=0
ElemType ListLaterInsert(LinkList head, int i, ElemType e);

//ɾ����i��Ԫ�ز����ء������õ��ã�����C++�﷨���ļ���չ��������.cpp�ſ��ã�.c����
//�йش����õ��òμ�linkedlist_run.cpp�ļ�ĩβ
Status DeleteElement(LinkList head, int i, ElemType &e);

//������͵�����
Status InverseLinkedList(LinkList L);

//�������
Status PrintList(LinkList head);

#endif