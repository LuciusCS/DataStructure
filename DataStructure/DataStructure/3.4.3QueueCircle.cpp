#include "stdio.h"
#include "stdlib.h"

//循环队列————队列的顺序表示和实现，可以参照栈的顺序表示和实现
//在c语言中不能使用动态数组来分实现循环队列，如果要使用循环队列则必须设定一个最大的长度；
#define maxsize 100

typedef struct {
	int *base;    //用于为队列分配空间
	int front;
	int rear;
}sqqueue;


//初始化队列
void initqueue(sqqueue &sq) {
	//构造一个空队列
	sq.base = (int *)malloc(maxsize*sizeof(int));
	if (!sq.base)
	{
		printf("构造队列失败");
	}
	sq.front = sq.rear = 0;
}

//入队
void enqueue(sqqueue &sq,int e) {
	//用于判断队列是否为满，通过查看队尾的下一个元素是不是队头
	if ((sq.rear+1)%maxsize==sq.front)
	{
		printf("队列为满");
	}
	sq.base[sq.rear] = e;
	sq.rear = (sq.rear + 1) % maxsize;  //因为转了一圈后sq.rare已经超过了maxsize

}

//出队
void requeue(sqqueue &sq) {
	//用于判断队是否为空
	if (sq.rear==sq.front)
	{
		printf("队列为空");
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