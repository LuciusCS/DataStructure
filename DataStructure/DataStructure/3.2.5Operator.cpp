//#include "stdio.h"
//#include "stdlib.h"
//#include "stdbool.h"
//
////���ļ������㷨3.4���Ա��ʽ�������
//
//
//typedef struct operate
//{
//	int size;
//	int *base;
//	int *top;
//}*pOperate;
//
//void initOperate(pOperate p,int size) {
//	p->base = (int *)malloc(sizeof(int)*size);
//	if (p->base!=NULL)
//	{
//		p->top = p->base;
//		p->size = size;
//	}
//	else
//	{
//		printf("�����ڴ�ʧ��");
//	}
//}
//bool isEmpty(pOperate p) {
//	if (p->base==p->top)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//void push(pOperate p,int num) {
//	*(p->top)++ = num;
//}
//
//void pop(pOperate p) {
//
//	if (isEmpty(p))
//	{
//		printf("ջ��");
//	}
//	else
//	{
//		printf("%d", *(--p->top));
//	}
//}
//
//int main() {
//	int result;
//
//	operate num;
//	initOperate(&num, 20);
//	push(&num,'c');
//	pop(&num);
//	return 0;
//}