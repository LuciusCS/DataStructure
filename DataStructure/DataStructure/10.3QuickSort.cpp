#include "stdio.h"
#include "stdlib.h"

//��������=�ڿ�����+�����㷨
//�����㷨�ǻ��ڵݹ��



void quickSort(int arr[],int left,int right) {

	if (left<right)
	{
		int i = left, j = right, tmp = arr[left];   //������ߵ���ѡΪ��׼����
		//�ȴ�������������tmpС����
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
		
			//��������������tmp�����
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
		quickSort(arr, left, i - 1);   //�ݹ����
		quickSort(arr, i + 1, right);  //�ݹ����
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