#include "stdio.h"
#include "stdlib.h"


//基数排序，基数排序可以被看成是多次桶式排序

//基于数组的基数排序

//从个位开始，最低位优先（Least Significant Digital first）
void radixSort(int num[], int length) {

	int *radix[10];
	for (int i = 0; i < 10; i++)
	{
		radix[i] = (int *)malloc(length * sizeof(int));
		radix[i][0] = 0;
	}
	int index = 1;

	for (int i = 1; i < 5; i++)
	{

		//将num数组中的数据放入数组radix中
		//第一次分配
		for (int i = 0; i < length; i++)
		{
			radix[(num[i]/index)% 10][0]++;
			radix[(num[i]/index) % 10][radix[(num[i]/index )% 10][0]] = num[i];
		}
		//第一次回收
		int length = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 1; j < radix[i][0] + 1; j++)
			{
				num[length++] = radix[i][j];
			}
		}
		for (int i = 0; i < 10; i++)
		{
			radix[i][0] = 0;
		}
		index = index * 10;
	}

	for (int i = 0; i < length; i++)
	{
		printf("%d\n",num[i]);
	}

}


//
//从最高位开始，最高位优先（Most Significant Digit first）
void radixSortMSD(int num[], int length) {

	int *radix[10];
	for (int i = 0; i < 10; i++)
	{
		radix[i] = (int *)malloc(length * sizeof(int));
		radix[i][0] = 0;
	}
	int index = 10000;

	for (int i = 1; i < 5; i++)
	{

		//将num数组中的数据放入数组radix中
		//第一次分配
		for (int i = 0; i < length; i++)
		{
			radix[(num[i] / index) % 10][0]++;
			radix[(num[i] / index) % 10][radix[(num[i] / index) % 10][0]] = num[i];
		}
		//第一次回收
		int length = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 1; j < radix[i][0] + 1; j++)
			{
				num[length++] = radix[i][j];
			}
		}
		for (int i = 0; i < 10; i++)
		{
			radix[i][0] = 0;
		}
		index = index /10;
	}

	for (int i = 0; i < length; i++)
	{
		printf("%d\n", num[i]);
	}

}

//
//int main() {
//
//	int num[10] = {0,10,12,5665,285,125,554,26,7895,12};
//	radixSortMSD(num, 10);
//
//	system("pause");
//	return 0;
//}
