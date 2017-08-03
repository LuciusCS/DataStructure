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
////1、初始化链表
//void initList(pStudent head) {
//	head = NULL;
//	printf("链表初始化执行");
//}
//
////2、创建链表，并进行赋值，一共有5个数据
//pStudent createList(pStudent head) {
//	pStudent p1 = (pStudent)malloc(sizeof(Student));
//	pStudent p2;
//	if (NULL == p1)
//	{
//		printf("内存分配失败");
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
////3、打印链表，链表的遍历
//void printList(pStudent head) {
//	if (NULL == head) {
//		printf("链表为空空");
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
////4、用于将链表请空，并释放内存
//void clearList(pStudent head) {
//	pStudent p = NULL;
//	while (NULL != head->next) {
//		p = head->next;
//		free(head);
//		head = p;
//	}
//
//}


//二、一元多项式的加减
//多项式的结构体
typedef struct Polyn {
	float conf;   //系数
	int expn;     //指数
	struct Polyn *next;

}Polyn, *pPolyn;
//二、1、用于构建m项一元多项式，多项式的指数递增
pPolyn creatPolyn(pPolyn head, int m) {
	pPolyn p1 = (pPolyn)malloc(sizeof(Polyn));
	head = p1;
	for (int i = 0; i < m; i++)
	{
		//在输入时应增加空格或者换行符
		scanf("%f%d", &(p1->conf), &(p1->expn));
		pPolyn p2 = (pPolyn)malloc(sizeof(Polyn));
		p1->next = p2;
		p1 = p2;
		p2->next = NULL;
	}
	return head;
}

//二、2、用于两个一元多项式相加
pPolyn addPolyn(pPolyn poly1, pPolyn poly2) {
	pPolyn head;
	pPolyn p1 = (pPolyn)malloc(sizeof(Polyn));
	head = p1;
	//首先判断两个一元多项式是否为空
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

//二、3、用于两个一元多项式相减
//二、4、用于输出一元多项式
void printPoly(pPolyn head) {
	if (NULL == head->next) {
		printf("多项式为空");
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
//	//用于链表初始化
//	//pStudent init = NULL;
//	//init=createList(init);
//	//printList(init);
//	//clearList(init);
//
//
//
//
//	//用于一元多项式的处理函数
//	pPolyn polyn1 = NULL;
//	pPolyn polyn2 = NULL;
//	pPolyn result = NULL;
//
//
//	printf("请输入第一个一元多项式的系数和指数\n");
//	polyn1=creatPolyn(polyn1,3);
//	printPoly(polyn1);
//
//
//	printf("请输入第二个一元多项式的系数和指数\n");
//	polyn2 = creatPolyn(polyn2, 4);
//	printPoly(polyn2);
//
//	printf("\n");
//	result=addPolyn(polyn1, polyn2);
//	printPoly(result);
//	return 0;
//
//
//	//自己测试 * & 什么时候取值、什么时候取址
//
//
//	//汉诺塔函数测试
////	hanoi(5, ' a', 'b', ' c'); 
////	return 0;
//	
//}
//
