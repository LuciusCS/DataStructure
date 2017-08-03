#include "stdio.h"
#include "stdlib.h"

//—°‘Ò≈≈–Ú


//ºÚµ•—°‘Ò≈≈–Ú

void SimpleSelectionSort(int arr[],int length) {
	int tmp;

	for (int i = 0; i < length; i++)
	{
		tmp = arr[i];
		for (int j = i+1; j < length; j++)
		{
			if (tmp>arr[j])
			{
				arr[i] = arr[j];
				arr[j] = tmp;
				tmp = arr[i];
			}
		}
	}
}

// ˜–Œ—°‘Ò≈≈–Ú

//
//
//int main() {
//	int arr[5] = { 5,4,3,2,1 };
//
//	SimpleSelectionSort(arr,5);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d",arr[i]);
//	}
//	system("pause");
//	return 0;
//}