#include "stdlib.h"
#include "stdio.h"


//本文件用于队列的链式表示与实现

//单链队列，队列的链式存储结构，队列是由队头指向队尾
typedef struct QNode {
	char data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr  front;   //队头指针
	QueuePtr rare;     //队尾指针
}LinkQueue;


//用于初始化队列
void initQueue(LinkQueue &lq) {
	lq.front = lq.rare = (QueuePtr)malloc(sizeof(QNode));
	lq.rare->next = NULL;

}

//用于插入队列
void enQueue(LinkQueue &lq,char data) {
	//插入元素为Q的新的队尾元素 data
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = data;
	p->next = NULL;
	lq.rare->next = p;
	lq.rare = lq.rare->next;
}

//用于取出头元素，在操作之前首先需要判断是不是空队列
void reQueue(LinkQueue &lq) {
	if (lq.front==lq.rare)
	{
		printf("队列为空，报错");
	}
	else
	{
		QueuePtr q;
		printf("%c",lq.front->next->data);  //这里是因为lq.front为一个空节点，因为在初始化队列的时候没有给这一个节点复制  数据机构P61有图
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