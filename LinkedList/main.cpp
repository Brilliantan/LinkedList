#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

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

#pragma warning (disable: 4996)	
//�߰汾Visual Studio��֧��scanf�Ⱥ������ᱨ��C4996���������ε����Errorǿ�����г���

int main()//����Ĳ���
{
	system("color 1F");		//������ڿ����������...���в���ֵ���Գ���
	printf("�������ƶ�̬���飬���԰���ʵ����Ҫ�洢����������������ȣ��Ӷ�ʵ�ֶԴ洢�ռ����Ч���á�\n");
	printf("���ڵ�����Ľṹ�ص㣬����ɾ�������ǳ���Ч����Ԫ�ز���ֱ�ӷ��ʶ�����Ҫ��ͷ����Ѱ�ң���˶�����Ҫ�������ҵ�Ӧ������Ч�ʽϲ\n");
	ElemType elem_test;
	int ElemNum = 0;
	int i;
	LinkList head = InitList();		//����ͷ�巨��������
	LinkList head2 = InitList();	//����β�巨��������
	printf("���������ԣ�����������Ԫ�ظ�����");
	scanf("%d", &ElemNum);
	for (i = 0; i < ElemNum; i++) {
		printf("�������%d��Ԫ�أ���������", i + 1);
		scanf("%d", &elem_test);
		ListFormerInsert(head, 1, elem_test);
		ListLaterInsert(head2, i, elem_test);
	}
	printf("ͷ�巨����������Ϊ��");
	PrintList(head);
	printf("β�巨����������Ϊ���������������ʹ�ã���");
	PrintList(head2);
	printf("\nɾ�����ݲ��ԣ�������ɾ�������еĵڼ���Ԫ��\n");
	scanf("%d", &i);
	if (DeleteElement(head, i, elem_test)) {
		printf("ɾ��������Ϊ%d\n", elem_test);
	}
	printf("��ʱ����Ϊ��\n");
	PrintList(head);
	printf("\n�������ò��ԣ�\n");
	printf("���ý����\n");
	InverseLinkedList(head);	//�͵����á���������Ʋ���֮һ��
	PrintList(head);			//������ý��
	printf("\n������ղ��ԣ�\n");
	ClearList(head);
	PrintList(head);	//�����յ����������������ȡ����head->next�Ƿ�ΪNULL
	printf("\n�������ٲ��ԣ�\n");
	DestroyList(head);
	PrintList(head);	//��������ڵ���������Ĵ������ȡ����head�Ƿ�ΪNULL
	printf("\n");
	system("pause");
	return 0;
}