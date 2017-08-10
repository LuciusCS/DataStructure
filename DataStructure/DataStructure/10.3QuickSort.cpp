#include "stdio.h"
#include "stdlib.h"

//快速排序=挖坑填数+分治算法
//分治算法是基于递归的



void quickSort(int arr[],int left,int right) {

	if (left<right)
	{
		int i = left, j = right, tmp = arr[left];   //将最左边的数选为基准数字
		//先从右向左搜索比tmp小的数
		while (i<j)
		{
			while (i<j&&tmp <= arr[j])
			{
				j--;
			}
			if (i<j)
			{
				arr[i++] = arr[j];
			}
		
			//从左至右搜索比tmp大的数
			while (i<j&&tmp >arr[i])
			{
				i++;
			}
			if (i<j)
			{
				arr[j--] = arr[i];
			}
		}
		arr[i] = tmp;
		quickSort(arr, left, i - 1);   //递归调用
		quickSort(arr, i + 1, right);  //递归调用
	}

}


//int main() {
//	int a[5] = { 5,4,3,2,1 };
//
//	quickSort(a, 0, 4);
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d",a[i]);
//	}
//		
//
//	system("pause");
//	return 0;
//
//}