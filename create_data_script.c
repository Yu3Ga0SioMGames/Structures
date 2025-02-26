#include "create_data_script.h"

void create_data()
{
	int j = 1000000;
	int mass[j];

	FILE *file = fopen("data.txt", "w+");
	if(file == NULL) {
		return;
	}

	srand(time(0));

	for(int i = 0; i < j; ++i) {
		mass[i] = rand() % (INT_MAX + 1);

		printf("%d ", mass[i]);
		fprintf(file, "%d ", mass[i]);
	}

	fclose(file);
}
