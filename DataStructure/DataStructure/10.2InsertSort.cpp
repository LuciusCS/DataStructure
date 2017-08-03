#include "stdio.h"
#include "stdlib.h"



//ֱ�Ӳ������� Straight Inserttion Sort;��������С��������
//��Array�����������������Array��
void StrightInsertSort(int array[], int length) {

	int tmp;     //���ڱ��潫Ҫ�����array[1]

	for (int i = 1; i < length; i++) {
		tmp = array[i];
		for (int j = i; j >= 0; j--)
		{
			if (tmp >= array[j - 1] || j == 0)
			{
				array[j] = tmp;
				break;
			}
			else {
				array[j] = array[j - 1];
			}
		}
	}
}

//�����۰���ҵĲ�������
void BInsertSort(int array[], int length) {
	int tmp;
	int start, end, mid;


	for (int i = 1; i < length; i++)
	{
		tmp = array[i];
		start = 0; end = i - 1; mid = (end + start) / 2;

		//�жϽ�Ҫ�����Ԫ���Ƿ�����Ѿ��ź����Ԫ�ص����ֵ�������Ѿ��ź������Сֵ
		if (tmp >= array[i - 1])
		{
			array[i] = tmp;
		}
		else if (tmp <= array[0]) {
			for (int j = i; j > 0; j--)
			{
				array[j] = array[j - 1];
			}
			array[0] = tmp;
		}
		//�����۰��������
		else
		{
			while (start < end)
			{
				if (tmp > array[mid])
				{
					start = mid + 1;
					mid = (start + end) / 2;
				}
				else if (tmp < array[mid])
				{
					end = mid - 1;
					mid = (start + end) / 2;
				}
			}

			for (int j = i; j > start; j--)
			{
				array[j] = array[j - 1];
			}
			array[start] = tmp;

		}
	}

}


//����Shell's sortϣ������
//����˼�룬����������ż�¼���зֳ����ɸ������зֱ����ֱ�Ӳ�������
//ϣ�������ǶԲ�������ĸĽ���ÿ������Ĳ�����Ϊԭ����1/2

void shell_sort(int arr[], int length) {
	int gap, i, j;
	int tmp;
	for (gap = length / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < length; i++)
		{
			tmp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > tmp; j-=gap)
			{
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = tmp;
		}
	}

}





//int main() {
//	int array[5] = { 5,4,7,4,6 };
//	int length = 5;
//
//	shell_sort(array, 5);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", array[i]);
//	}
//
//
//	system("pause");
//	return 0;
//}
