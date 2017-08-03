#include "stdio.h"
#include "stdlib.h"

//归并排序

//将数组A的左右有序的两部分进行合并，即 A[first...mid]和A[mid...last],假设数组A的左右两部分已经是有序的状态

//tmp是长度为 last-first的数数组用于临时存储排序时的数据

void mergeArray(int a[],int first,int mid,int last,int tmp[]) {
	int i = first;
	int j = mid+1;
	int k = 0;    //K用作tmp的索引

	while (i<=mid&&j<=last)
		a[i] < a[j] ? tmp[k++] = a[i++] : tmp[k++] = a[j++];
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= last)
		tmp[k++] = a[j++];
	while (k > 0)
		a[--j] = tmp[--k];

}


void mergeSort(int a[],int first,int last,int tmp[]) {
	if (first<last)
	{
		int mid = (first + last) / 2;
		mergeSort(a,first,mid,tmp);  //左边有序
		mergeSort(a, mid+1, last, tmp);//右边有序
		mergeArray(a,first,mid,last,tmp);  //将两个数组合并
	}


}

//int main() {
//
//	int a[7] = {7,8,9,10,1,2,3};
//	int tmp[7];
//	//mergeArray(a, 1, 3, 5, tmp);
//	mergeSort(a,0,6,tmp);
//
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//	return 0;
//}