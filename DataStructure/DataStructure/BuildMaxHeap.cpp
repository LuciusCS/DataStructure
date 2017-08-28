#include "stdio.h"
#include "stdlib.h"

#define HeapSize 128
//大根堆的数据结构
typedef struct MaxHeap {
	int heap[HeapSize];
	int n;

}MaxHeap;

//采用自上而下的调整方法,M标记的是子树的根
void shiftHeap(MaxHeap &H,int m) {
	int tmp = H.heap[m];
	for (int i = 2*m+1; i <=H.n-1 ; i=i*2+1)
	{
		if (i<H.n-1&&H.heap[i]<H.heap[i+1])
		{
			i++;
		}
		if (tmp>H.heap[i])
		{
			break;
		}
		else
		{
			H.heap[m] = H.heap[i];
			H.heap[i] = tmp;
			m = i;
		}
	}
}


void createHeap(MaxHeap &H, int arr[],int n) {
	//将数组的内容赋值给堆中的元素
	for (int i = 0; i < n; i++)
	{
		H.heap[i] = arr[i];
	}
	H.n = n;

	for (int i = (n-2)/2; i >=0; i--)
	{
		shiftHeap(H, i);
	}
}



//int main() {
//	int arr[8] = {1,2,3,4,5,6,7,8};
//	MaxHeap H;
//	createHeap(H, arr,8);
//	printf("大根堆的创建结果\n");
//	for (int  i = 0; i < 8; i++)
//	{
//		printf(" %d ",H.heap[i]);
//	}
//	system("pause");
//	return 0;
//}