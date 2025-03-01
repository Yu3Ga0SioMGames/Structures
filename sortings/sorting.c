#include "sorting.h"

void BubbleSort(int arr[], size_t count)
{
	for(int i = 0; i < count - 1; i++) {
		for(int j = 0; j < count - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = tmp;
			}
		}
	}
}

void OptimizeBubbleSort(int arr[], size_t count)
{
	int swap = 0;

	for(int i = 0; i < count - 1; i++) {
		swap = 0;

		for(int j = 0; j < count - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = tmp;

				swap = 1;
			}
		}

		if(swap == 0) {
			break;
		}
	}
}

void InsertSort(int arr[], size_t count)
{
	for(int i = 1; i < count; ++i) {
		int tmp = arr[i];
		int j = i - 1;

		while(tmp >= 0 && arr[j] > tmp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = tmp;
	}
}

void SelectionSort(int arr[], size_t count)
{
	for(int i = 0; i < count - 1; ++i) {
		int min_i = i;

		for(int j = i + 1; j < count; ++j) {
			if(arr[j] < arr[min_i]) {
				min_i = j;
			}
		}

		int tmp = arr[i];
		arr[i] = arr[min_i];
		arr[min_i] = tmp;
	}
}
