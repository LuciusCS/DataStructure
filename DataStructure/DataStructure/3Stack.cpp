#include "stdio.h"
#include "stdlib.h"

//三、方法一：使用顺序表实现栈
//实现栈的两种方法一种是动态数组一种是静态数组，使用动态数组可以动态增加栈的长度。使用静态数组不可以增加数组的长度

#define STACK_SIZE 50
#define STACK_INCREMENT 10


typedef struct {
	int stackSize;  //栈容量
	int *base;      //栈底指针
	int *top;       //栈顶指针

}SqStack, *pStack;

//三、1、栈初始化，base和top相当于栈中的索引
void initStack(pStack p) {
	p->base = (int *)malloc(STACK_SIZE * sizeof(int));
	if (p->base != NULL)
	{
		p->top = p->base;
		p->stackSize = STACK_SIZE;
	}
	else
	{
		printf("分配内存失败");
	}

}

//三、2、用于判断栈是否为空
bool isEmpty(pStack p) {
	return p->top == p->base ? true : false;
}
//三、3、用于判断栈是否为满
bool isFull(pStack p) {
	return (p->top - p->base) >= STACK_SIZE ? true : false;
}


//三、4、入栈，传入的是元素的名称
void push(pStack p, int topElement) {
	int *q = NULL;
	if (isFull(p))
	{
		q = (int *)realloc(p->base, STACK_INCREMENT * sizeof(int));  // 重新调整内存块的大小

		p->base = q;
		p->stackSize = p->stackSize + STACK_INCREMENT;
	}
	*(p->top)++ = topElement;
}
//三、5、出栈，传入的是元素的地址
void pop(pStack p, int *topElement) {
	if (isEmpty(p))
	{
		printf("空栈");

	}

	p->top--;
	*topElement = *p->top;
}

//三、6、求当前的长度
int getStackLength(SqStack s) {
	int i = 0;
	int *q = s.top;

	while (q != s.base)
	{
		q--;
		i++;
	}
	return i;
}
//三、7、求栈顶元素
int getStackTop(SqStack s) {
	int topElement;
	if (isEmpty(&s))
	{
		printf("栈空");
	}
	topElement = *(s.top - 1);
	return topElement;

}
//三、用于清空栈
void clearStack(SqStack s) {
	while (!isEmpty(&s))
	{
		int tmp;
		pop(&s, &tmp);
	}

}


//三、方法二：使用结构体和数组实现顺序栈
#define STATCK_MAX_SIZE 20

typedef struct {
	int data[STATCK_MAX_SIZE];
	int top;
}ArrayStack;
//构造一个空栈
bool intiStack(ArrayStack *s) {
	s->top = -1;//表示栈为空
	return true;
}





//四、使用单链表实现栈
//这一个文件用于对栈进行操作



//算法3.1 使用栈实现数制的转换,将10进制转换为2进制
void conversion(int num) {
	SqStack stack;
	initStack(&stack);
	while (num / 2)
	{
		push(&stack, num % 2);
		num /= 2;
	}
	push(&stack, num);

	int tmp = 0;
	while (!isEmpty(&stack))
	{
		pop(&stack, &tmp);
		printf("%d", tmp);

	}
}

//使用栈实现括号匹配的校验
void check_symbol() {
	char s[50] = { 0 };
	printf("请输入一串括号");
	scanf("%s", s);
	SqStack stack;
	initStack(&stack);
	push(&stack, s[0]);
	for (int i = 1; s[i] != 0; i++)
	{
		if (!isEmpty(&stack))
		{
			if (getStackTop(stack) == (int) '{'&&s[i] == (int)'}' || getStackTop(stack) == (int) '('&&s[i] == (int)')') {
				int tmp;
				pop(&stack, &tmp);
			}
			else
			{
				push(&stack, s[i]);
			}
		}
		else
		{
			int tmp;
			push(&stack, s[i]);
		}


	}
	if (isEmpty(&stack))
	{
		printf("括号匹配");
	}
	else
	{
		printf("括号不匹配");
	}

}
//使用栈实现行编辑程序，采用EOF使得输入结束  　EOF的输入由系统锁定。windows下是ctrl+z,linux/unix下是ctrl+d
void lineEdit() {
	//首先初始化栈
	SqStack stack;
	initStack(&stack);
	char ch = getchar();
	while (ch != EOF)
	{
		while (ch != EOF&&ch!='\n') {
			switch (ch)
			{
			case '@':clearStack(stack);
				break;
			case '#':if (isEmpty(&stack))
				break;
					 else
					 {
						 int tmp;
						 pop(&stack, &tmp);
						 break;
					 }
			default:
				push(&stack, ch); break;
			}
			ch = getchar();
		}
		ch = getchar();
	}

	//用于将存储在栈中的内容输出
	if (ch == EOF) {
		while (!isEmpty(&stack))
		{
			int tmp;
			pop(&stack, &tmp);
			printf("%c", tmp);
		}
	}
}
//使用栈对迷宫进行求解
void mazePath() {

}

//int main() {
//	//用于顺序栈的测试方法一
//	int tmp = 0;;
//	SqStack stack;
//	initStack(&stack);
//	//push(&stack, 'a');
//	//push(&stack, 'a');
//	//pop(&stack, &tmp);
//	//printf("\n%d", getStackTop(stack));
//
//
//	//用于进制转换函数
//	conversion(255);
//	//用于进行括号匹配
//	check_symbol();
//	//用于行编辑器的编程
//	lineEdit();
//
//	return 0;
//}