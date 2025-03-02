#include "sorting.h"

void MergeSort(int arr[], size_t length)
{
	MergeSortRecursion(arr, 0, length - 1);
}

void MergeSortRecursion(int arr[], int left_index, int right_index)
{
	if(left_index < right_index) {
		int middle_index = left_index + (right_index - left_index) / 2;

		MergeSortRecursion(arr, left_index, middle_index);
		MergeSortRecursion(arr, middle_index + 1, right_index);

		MergeSortedArrays(arr, left_index, middle_index, right_index);
	}
}

void MergeSortedArrays(int arr[], int left_index, int middle_index, int right_index)
{
	int left_length = middle_index - left_index + 1;
	int right_length = right_index - middle_index;

	int tmp_arr_left[left_length];
	int tmp_arr_right[right_length];

	for(int i = 0; i < left_length; ++i) {
		tmp_arr_left[i] = arr[left_index + i];
	}

	for(int i = 0; i < right_length; ++i) {
		tmp_arr_right[i] = arr[middle_index + 1 + i];
	}

	int i, j, k;
	for(i = 0, j = 0, k = left_index; k <= right_index; k++) {
		if((i < left_length) && (j >= right_length || tmp_arr_left[i] <= tmp_arr_right[j])) {
			arr[k] = tmp_arr_left[i];

			i++;
		} else {
			arr[k] = tmp_arr_right[j];

			j++;
		}
	}
}

void _QuickSort(int arr[], int left, int right)
{
	if(left > right) {
		return;
	}

	int middle_element = arr[(left + right) / 2];

	int i = left;
	int j = right;

	while(i <= j) {
		while(arr[i] < middle_element) {
			++i;
		}

		while(arr[j] > middle_element) {
			--j;
		}

		if(i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			++i;
			--j;
		}
	}

	_QuickSort(arr, left, j);
	_QuickSort(arr, i, right);
}

void QuickSort(int arr[], size_t length)
{
	int left = 0;
	int right = length - 1;

	_QuickSort(arr, left, right);
}

void BubbleSort(int arr[], size_t length)
{
	for(int i = 0; i < length - 1; i++) {
		for(int j = 0; j < length - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = tmp;
			}
		}
	}
}

void OptimizeBubbleSort(int arr[], size_t length)
{
	int swap = 0;

	for(int i = 0; i < length - 1; i++) {
		swap = 0;

		for(int j = 0; j < length - 1 - i; j++) {
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

void InsertSort(int arr[], size_t length)
{
	for(int i = 1; i < length; ++i) {
		int tmp = arr[i];
		int j = i - 1;

		while(tmp >= 0 && arr[j] > tmp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = tmp;
	}
}

void SelectionSort(int arr[], size_t length)
{
	for(int i = 0; i < length - 1; ++i) {
		int min_i = i;

		for(int j = i + 1; j < length; ++j) {
			if(arr[j] < arr[min_i]) {
				min_i = j;
			}
		}

		int tmp = arr[i];
		arr[i] = arr[min_i];
		arr[min_i] = tmp;
	}
}
