#include "stdlib.h"
#include "stdio.h"


//���ļ����ڶ��е���ʽ��ʾ��ʵ��

//�������У����е���ʽ�洢�ṹ���������ɶ�ͷָ���β
typedef struct QNode {
	char data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr  front;   //��ͷָ��
	QueuePtr rare;     //��βָ��
}LinkQueue;


//���ڳ�ʼ������
void initQueue(LinkQueue &lq) {
	lq.front = lq.rare = (QueuePtr)malloc(sizeof(QNode));
	lq.rare->next = NULL;

}

//���ڲ������
void enQueue(LinkQueue &lq,char data) {
	//����Ԫ��ΪQ���µĶ�βԪ�� data
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = data;
	p->next = NULL;
	lq.rare->next = p;
	lq.rare = lq.rare->next;
}

//����ȡ��ͷԪ�أ��ڲ���֮ǰ������Ҫ�ж��ǲ��ǿն���
void reQueue(LinkQueue &lq) {
	if (lq.front==lq.rare)
	{
		printf("����Ϊ�գ�����");
	}
	else
	{
		QueuePtr q;
		printf("%c",lq.front->next->data);  //��������Ϊlq.frontΪһ���սڵ㣬��Ϊ�ڳ�ʼ�����е�ʱ��û�и���һ���ڵ㸴��  ���ݻ���P61��ͼ
		q = lq.front;
		lq.front = lq.front->next;
		free(q);
	}
}




//int main() {
//	LinkQueue lq;
//	initQueue(lq);
//
//	enQueue(lq,'a');
//	enQueue(lq,'b');
//	enQueue(lq, 'c');
//	enQueue(lq, 'd');
//
//	enQueue(lq, 'e');
//
//	reQueue(lq);
//	reQueue(lq);
//	reQueue(lq);
//	reQueue(lq);
//	reQueue(lq);
//	reQueue(lq);
//
//	return 0;
//}