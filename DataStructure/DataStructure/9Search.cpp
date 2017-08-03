#include "stdlib.h"
#include "stdio.h"

//���ļ����ڸ��ֲ��ҷ�����ʵ��


//�����۰���Ҽ����ֲ��ҵ�ʵ��,data������һ�����մ�С����˳�����е�����,��Ҫ
int BinarySearch(int data[], int search,int length) {
	int end = length-1 ;
	int start = 0;
	int mid = (start + end) / 2;

	while (start<=end)
	{
		if (data[mid] == search)
		{
			return mid;
		}
		else if (data[mid] > search)
		{
			end = mid-1;
			mid = (start + end) / 2;
		}
		else
		{
			start = mid+1;
			mid = (start + end) / 2;
		}

	}
	return -1;

}

//

//int main() {
//
//	int i[7] = { 1,2,3,4,5,6,7};
//	//BinarySearch(i, 5);
//
//	printf("�۰����%d", BinarySearch(i,7,sizeof(i)/sizeof(int)));
//	return 0;
//
//}