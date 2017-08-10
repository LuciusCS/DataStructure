#include "stdio.h"
#include <stdarg.h>  //提供宏va_start、va_arg、va_end;
#include "stdlib.h"

//用于数组的顺序存储


#define MAX_ARRAY_DIM 8   //定义数组的维数，最大为8


//数组的结构体
typedef struct array{
	int *base;  //数组元素的基址
	int dim;     //数组元素的维数
	int *bounds;   //数组界基址
}array,*pArray;


//参数dim为维数，后面的参数为各维的长度
void initArray(array &A, int dim, ... ) {
	if (dim<1||dim>MAX_ARRAY_DIM)
	{
		printf("请输入正确的数组维数");
	}
	A.dim = dim;
	A.bounds = (int *)malloc(dim*sizeof(int));
	A.bounds[1] = 0;
}

/*构造可变参数参数的函数，不属于 数组的顺序存储*/
int num(int num_args,...){   //num_args表示的是有多少个数相加
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
//	printf("数组测试");
//
//	system("pause");
//	return 0;
//
//}