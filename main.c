#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count = 100;
	char filename[25];

	sprintf(filename, "%d_data_%d.txt", count, count);

	FILE *file_read = fopen(filename, "r");
	if(file_read == NULL) {
		return 1;
	}

	int arr[count];

	size_t readed_elements = fread(arr, sizeof(int), count, file_read);
	fclose(file_read);
	if(readed_elements != count) {
		return 1;
	} else {
		for(int i = 0; i < count; ++i) {
			printf("%d ", arr[i]);
		}
	}

	// ArraySort(arr);

	FILE *file_write = fopen("result.txt", "w+");
	if(file_write == NULL) {
		return 1;
	}

	size_t writer_elements = fwrite(arr, sizeof(int), count, file_write);
	fclose(file_write);
	if(writer_elements != count) {
		return 1;
	}

	return 0;
}
