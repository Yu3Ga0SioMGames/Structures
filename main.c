#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sorting.h>

int main()
{
	int count = 10000;
	char filename[25];

	sprintf(filename, "%d_data_%d.txt", count, count);

	FILE *file = fopen(filename, "r");

	int arr[count];

	for(int i = 0; i < count; ++i) {
		if(fscanf(file, "%d", &arr[i]) != 1) {
			fclose(file);
			return 1;
		}
	}

	fclose(file);

	QuickSort(arr, count);

	file = fopen("result.txt", "w+");
	if(file == NULL) {
		return 1;
	}

	for(int i = 0; i < count; ++i) {
		if(fprintf(file, "%d ", arr[i]) < 0) {
			fclose(file);
			return 1;
		}
	}

	fclose(file);

	for(int i = 0; i < count; ++i) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}
