#include "stdio.h"
#include <stdarg.h>  //�ṩ��va_start��va_arg��va_end;
#include "stdlib.h"

//���������˳��洢


#define MAX_ARRAY_DIM 8   //���������ά�������Ϊ8


//����Ľṹ��
typedef struct array{
	int *base;  //����Ԫ�صĻ�ַ
	int dim;     //����Ԫ�ص�ά��
	int *bounds;   //������ַ
}array,*pArray;


//����dimΪά��������Ĳ���Ϊ��ά�ĳ���
void initArray(array &A, int dim, ... ) {
	if (dim<1||dim>MAX_ARRAY_DIM)
	{
		printf("��������ȷ������ά��");
	}
	A.dim = dim;
	A.bounds = (int *)malloc(dim*sizeof(int));
	A.bounds[1] = 0;
}

/*����ɱ���������ĺ����������� �����˳��洢*/
int num(int num_args,...){   //num_args��ʾ�����ж��ٸ������
	int val = 0;
	va_list ap;
	


	va_start(ap, num_args);
	for (int i = 0; i < num_args; i++)
	{
		val += va_arg(ap, int);
	}
	va_end(ap);

	return val;

}




//int main() {
//	printf("�������");
//
//	system("pause");
//	return 0;
//
//}