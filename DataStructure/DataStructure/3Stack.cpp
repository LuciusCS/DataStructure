#include "stdio.h"
#include "stdlib.h"

//��������һ��ʹ��˳���ʵ��ջ
//ʵ��ջ�����ַ���һ���Ƕ�̬����һ���Ǿ�̬���飬ʹ�ö�̬������Զ�̬����ջ�ĳ��ȡ�ʹ�þ�̬���鲻������������ĳ���

#define STACK_SIZE 50
#define STACK_INCREMENT 10


typedef struct {
	int stackSize;  //ջ����
	int *base;      //ջ��ָ��
	int *top;       //ջ��ָ��

}SqStack, *pStack;

//����1��ջ��ʼ����base��top�൱��ջ�е�����
void initStack(pStack p) {
	p->base = (int *)malloc(STACK_SIZE * sizeof(int));
	if (p->base != NULL)
	{
		p->top = p->base;
		p->stackSize = STACK_SIZE;
	}
	else
	{
		printf("�����ڴ�ʧ��");
	}

}

//����2�������ж�ջ�Ƿ�Ϊ��
bool isEmpty(pStack p) {
	return p->top == p->base ? true : false;
}
//����3�������ж�ջ�Ƿ�Ϊ��
bool isFull(pStack p) {
	return (p->top - p->base) >= STACK_SIZE ? true : false;
}


//����4����ջ���������Ԫ�ص�����
void push(pStack p, int topElement) {
	int *q = NULL;
	if (isFull(p))
	{
		q = (int *)realloc(p->base, STACK_INCREMENT * sizeof(int));  // ���µ����ڴ��Ĵ�С

		p->base = q;
		p->stackSize = p->stackSize + STACK_INCREMENT;
	}
	*(p->top)++ = topElement;
}
//����5����ջ���������Ԫ�صĵ�ַ
void pop(pStack p, int *topElement) {
	if (isEmpty(p))
	{
		printf("��ջ");

	}

	p->top--;
	*topElement = *p->top;
}

//����6����ǰ�ĳ���
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
//����7����ջ��Ԫ��
int getStackTop(SqStack s) {
	int topElement;
	if (isEmpty(&s))
	{
		printf("ջ��");
	}
	topElement = *(s.top - 1);
	return topElement;

}
//�����������ջ
void clearStack(SqStack s) {
	while (!isEmpty(&s))
	{
		int tmp;
		pop(&s, &tmp);
	}

}


//������������ʹ�ýṹ�������ʵ��˳��ջ
#define STATCK_MAX_SIZE 20

typedef struct {
	int data[STATCK_MAX_SIZE];
	int top;
}ArrayStack;
//����һ����ջ
bool intiStack(ArrayStack *s) {
	s->top = -1;//��ʾջΪ��
	return true;
}





//�ġ�ʹ�õ�����ʵ��ջ
//��һ���ļ����ڶ�ջ���в���



//�㷨3.1 ʹ��ջʵ�����Ƶ�ת��,��10����ת��Ϊ2����
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

//ʹ��ջʵ������ƥ���У��
void check_symbol() {
	char s[50] = { 0 };
	printf("������һ������");
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
		printf("����ƥ��");
	}
	else
	{
		printf("���Ų�ƥ��");
	}

}
//ʹ��ջʵ���б༭���򣬲���EOFʹ���������  ��EOF��������ϵͳ������windows����ctrl+z,linux/unix����ctrl+d
void lineEdit() {
	//���ȳ�ʼ��ջ
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

	//���ڽ��洢��ջ�е��������
	if (ch == EOF) {
		while (!isEmpty(&stack))
		{
			int tmp;
			pop(&stack, &tmp);
			printf("%c", tmp);
		}
	}
}
//ʹ��ջ���Թ��������
void mazePath() {

}

//int main() {
//	//����˳��ջ�Ĳ��Է���һ
//	int tmp = 0;;
//	SqStack stack;
//	initStack(&stack);
//	//push(&stack, 'a');
//	//push(&stack, 'a');
//	//pop(&stack, &tmp);
//	//printf("\n%d", getStackTop(stack));
//
//
//	//���ڽ���ת������
//	conversion(255);
//	//���ڽ�������ƥ��
//	check_symbol();
//	//�����б༭���ı��
//	lineEdit();
//
//	return 0;
//}