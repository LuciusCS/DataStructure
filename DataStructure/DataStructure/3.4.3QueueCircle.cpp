#include "stdio.h"
#include "stdlib.h"

//ѭ�����С����������е�˳���ʾ��ʵ�֣����Բ���ջ��˳���ʾ��ʵ��
//��c�����в���ʹ�ö�̬��������ʵ��ѭ�����У����Ҫʹ��ѭ������������趨һ�����ĳ��ȣ�
#define maxsize 100

typedef struct {
	int *base;    //����Ϊ���з���ռ�
	int front;
	int rear;
}sqqueue;


//��ʼ������
void initqueue(sqqueue &sq) {
	//����һ���ն���
	sq.base = (int *)malloc(maxsize*sizeof(int));
	if (!sq.base)
	{
		printf("�������ʧ��");
	}
	sq.front = sq.rear = 0;
}

//���
void enqueue(sqqueue &sq,int e) {
	//�����ж϶����Ƿ�Ϊ����ͨ���鿴��β����һ��Ԫ���ǲ��Ƕ�ͷ
	if ((sq.rear+1)%maxsize==sq.front)
	{
		printf("����Ϊ��");
	}
	sq.base[sq.rear] = e;
	sq.rear = (sq.rear + 1) % maxsize;  //��Ϊת��һȦ��sq.rare�Ѿ�������maxsize

}

//����
void requeue(sqqueue &sq) {
	//�����ж϶��Ƿ�Ϊ��
	if (sq.rear==sq.front)
	{
		printf("����Ϊ��");
	}
	printf("%d\n",sq.base[sq.front]);
	sq.front = (sq.front + 1) % maxsize;
}



//int main() {
//	sqqueue sq;
//	initqueue(sq);
//
//
//	enqueue(sq,10);
//	enqueue(sq,15);
//	enqueue(sq, 20);
//	enqueue(sq, 25);
//	enqueue(sq, 30);
//	enqueue(sq, 35);
//
//	requeue(sq);
//
//	requeue(sq);
//	requeue(sq);
//
//
//	return 0;
//}