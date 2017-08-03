// LinkList.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//
//typedef struct Student {
//	int num;
//	char name[5];
//	struct Student *previoue;
//	struct Student *next;
//}Student, *pStudent;
//
////1����ʼ������
//void initList(pStudent head) {
//	head = NULL;
//	printf("�����ʼ��ִ��");
//}
//
////2���������������и�ֵ��һ����5������
//pStudent createList(pStudent head) {
//	pStudent p1 = (pStudent)malloc(sizeof(Student));
//	pStudent p2;
//	if (NULL == p1)
//	{
//		printf("�ڴ����ʧ��");
//	}
//	head = p1;
//	for (int i = 0; i < 5; i++)
//	{
//		p1->num = i;
//		p2 = (pStudent)malloc(sizeof(Student));
//		p1->next = p2;
//		p1 = p2;
//	}
//	p1->next = NULL;
//
//	return head;
//}
//
////3����ӡ��������ı���
//void printList(pStudent head) {
//	if (NULL == head) {
//		printf("����Ϊ�տ�");
//	}
//	else {
//		while (NULL != (head->next)) {
//			printf("%d\n", head->num);
//			head = head->next;
//		}
//	}
//}
//
//
////4�����ڽ�������գ����ͷ��ڴ�
//void clearList(pStudent head) {
//	pStudent p = NULL;
//	while (NULL != head->next) {
//		p = head->next;
//		free(head);
//		head = p;
//	}
//
//}


//����һԪ����ʽ�ļӼ�
//����ʽ�Ľṹ��
typedef struct Polyn {
	float conf;   //ϵ��
	int expn;     //ָ��
	struct Polyn *next;

}Polyn, *pPolyn;
//����1�����ڹ���m��һԪ����ʽ������ʽ��ָ������
pPolyn creatPolyn(pPolyn head, int m) {
	pPolyn p1 = (pPolyn)malloc(sizeof(Polyn));
	head = p1;
	for (int i = 0; i < m; i++)
	{
		//������ʱӦ���ӿո���߻��з�
		scanf("%f%d", &(p1->conf), &(p1->expn));
		pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
		p1->next = p2;
		p1 = p2;
		p2->next = NULL;
	}
	return head;
}

//����2����������һԪ����ʽ���
pPolyn addPolyn(pPolyn poly1, pPolyn poly2) {
	pPolyn head;
	pPolyn p1 = (pPolyn)malloc(sizeof(Polyn));
	head = p1;
	//�����ж�����һԪ����ʽ�Ƿ�Ϊ��
	if ((NULL == poly1->next) || (NULL == poly2->next)) {
		return head;
	}
	else
	{

		while ((NULL != poly1->next) && (NULL != poly2->next))
		{
			if (poly1->expn == poly2->expn)
			{
				p1->conf = poly1->conf + poly2->conf;
				p1->expn = poly1->expn;
				pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
				p1->next = p2;
				p1 = p2;
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
			else if (poly1->expn > poly2->expn) {

				p1->conf = poly2->conf;
				p1->expn = poly2->expn;
				pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
				p1->next = p2;
				p1 = p2;
				poly2 = poly2->next;
			}
			else
			{
				p1->conf = poly1->conf;
				p1->expn = poly1->expn;
				pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
				p1->next = p2;
				p1 = p2;
				poly1 = poly1->next;
			}
			p1->next = NULL;
		}if (NULL != poly1->next)
		{
			while (NULL != poly1->next) {
				p1->conf = poly1->conf;
				p1->expn = poly1->expn;
				pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
				p1->next = p2;
				p1 = p2;
				poly1 = poly1->next;
			}
			p1->next = NULL;
		}
		else if (NULL != poly2->next)
		{
			while (NULL != poly2->next) {
				p1->conf = poly2->conf;
				p1->expn = poly2->expn;
				pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
				p1->next = p2;
				p1 = p2;
				poly2 = poly2->next;
			}
			p1->next = NULL;
		}
	}
	return head;
}

//����3����������һԪ����ʽ���
//����4���������һԪ����ʽ
void printPoly(pPolyn head) {
	if (NULL == head->next) {
		printf("����ʽΪ��");
	}
	else
	{
		while (NULL != head->next)
		{
			printf("(%f,%d)", head->conf, head->expn);
			head = head->next;
		}
	}
}






//int main()
//{
//	//���������ʼ��
//	//pStudent init = NULL;
//	//init=createList(init);
//	//printList(init);
//	//clearList(init);
//
//
//
//
//	//����һԪ����ʽ�Ĵ�����
//	pPolyn polyn1 = NULL;
//	pPolyn polyn2 = NULL;
//	pPolyn result = NULL;
//
//
//	printf("�������һ��һԪ����ʽ��ϵ����ָ��\n");
//	polyn1=creatPolyn(polyn1,3);
//	printPoly(polyn1);
//
//
//	printf("������ڶ���һԪ����ʽ��ϵ����ָ��\n");
//	polyn2 = creatPolyn(polyn2, 4);
//	printPoly(polyn2);
//
//	printf("\n");
//	result=addPolyn(polyn1, polyn2);
//	printPoly(result);
//	return 0;
//
//
//	//�Լ����� * & ʲôʱ��ȡֵ��ʲôʱ��ȡַ
//
//
//	//��ŵ����������
////	hanoi(5, ' a', 'b', ' c'); 
////	return 0;
//	
//}
//
