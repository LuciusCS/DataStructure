#include "stdio.h"
#include "stdlib.h"



//直接插入排序 Straight Inserttion Sort;将数组由小至大排序
//对Array进行排序后结果还是在Array中
void StrightInsertSort(int array[], int length) {

	int tmp;     //用于保存将要插入的array[1]

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

//采用折半查找的插入排序
void BInsertSort(int array[], int length) {
	int tmp;
	int start, end, mid;


	for (int i = 1; i < length; i++)
	{
		tmp = array[i];
		start = 0; end = i - 1; mid = (end + start) / 2;

		//判断将要插入的元素是否大于已经排好序的元素的最大值，或者已经排好序的最小值
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
		//进行折半查找排序
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


//采用Shell's sort希尔排序
//整体思想，相减整个待排记录序列分成若干个子序列分别进行直接插入排序
//希尔排序是对插入排序的改进，每次排序的步长变为原来的1/2

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
