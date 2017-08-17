#include <stdio.h>
#include <stdlib.h>

//�������������Ϊ�������մ�С�����˳��������С���������ƣ�

#define HeapSize 128
//����ѵ����ݽṹ
typedef struct MaxHeapSort {
	int heap[HeapSize];
	int n;

}MaxHeapSort;

//�������϶��µĵ�������,M��ǵ��������ĸ�,������ڹ������Ѷ�һ������n��Ϊ�˱��ÿ�ε�������ĩβԪ��
void shiftHeapSort(MaxHeapSort &H, int m,int n) {
	int tmp = H.heap[m];
	for (int i = 2 * m + 1; i <= n - 1; i = i * 2 + 1)
	{
		if (i<n - 1 && H.heap[i]<H.heap[i + 1])
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


void createHeapSort(MaxHeapSort &H, int arr[], int n) {
	//����������ݸ�ֵ�����е�Ԫ��
	for (int i = 0; i < n; i++)
	{
		H.heap[i] = arr[i];
	}
	H.n = n;

	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftHeapSort(H, i,H.n);
	}


}


//int main(){
//	 
//	int a[7] = {7,6,5,4,3,2,1};
//	//���ȹ�������
//	MaxHeapSort H;
//	createHeapSort(H, a, 7);
//	//���������ǽ�ÿ�ν��Ѷ���Ԫ���������һ��Ԫ�ؽ��н�����Ȼ���ٽ��ѵ���Ϊ����
//	int tmp;//��Ϊ��ʱ��
//
//	for (int i = H.n-1; i >=0; i--)
//	{
//		tmp = H.heap[0];
//		H.heap[0] = H.heap[i];
//		H.heap[i] = tmp;
//		//�����ٴε���Ϊ����
//		for (int j = i/2; j >=0; j--)
//		{
//			shiftHeapSort(H,j,i);
//		}
//	}
//
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d\n",H.heap[i]);
//	}
//	system("pause");
//	return 0;
//}