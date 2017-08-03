#include "stdio.h"
#include "stdlib.h"

//�鲢����

//������A����������������ֽ��кϲ����� A[first...mid]��A[mid...last],��������A�������������Ѿ��������״̬

//tmp�ǳ���Ϊ last-first��������������ʱ�洢����ʱ������

void mergeArray(int a[],int first,int mid,int last,int tmp[]) {
	int i = first;
	int j = mid+1;
	int k = 0;    //K����tmp������

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
		mergeSort(a,first,mid,tmp);  //�������
		mergeSort(a, mid+1, last, tmp);//�ұ�����
		mergeArray(a,first,mid,last,tmp);  //����������ϲ�
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