#include <stdio.h>
#include <stdlib.h>

char** read_file(char* nome_ficheiro, char** data, int* linha) { //reads the file

	FILE *f = fopen(nome_ficheiro, "r");
	if (f == NULL) {
		printf("Erro ao abrir ficheiro\n");
		return NULL;
	}

	char buffer[200];
	*linha = 0;

	data = malloc(sizeof(char*));
	if (data == NULL) {
		printf("Erro ao allocar memoria\n");
		return NULL;
	}

	while (fgets(buffer, 200, f) != NULL) {
		*linha = *linha + 1;
		data = realloc(data, *linha * sizeof(char*));
		data[*linha - 1] = malloc(strlen(buffer) * sizeof(char));
		if (data == NULL || data[*linha - 1] == NULL) {
			printf("Erro ao allocar memoria");
			return NULL;
		}
		strcpy(data[*linha - 1], buffer);
	}
	fclose(f);
	return data;
}

void quicksort(int *array, int size)     //sorting function for the array
{
	int a, b, temp;

	for (a = 0; a < (size - 1); a++) {
		for (b = a + 1; b < size; b++) {
			if (array[a] > array[b]) {
				temp = array[b];
				array[b] = array[a];
				array[a] = temp;
			}
		}
	}
	return array;
}

int* converter(char** file_data, int lines) {
	int array[200];
	int i = 0;

	for (i = 0; i < lines; i++) {
		array[i] = atoi(file_data[i]);
	}
	return array;
}


int main(int argc, char *argv[]) {
	char sl = 178;
	int dummy;

	char c;
	int n;
	int t;

	char **file_data = NULL;
	char *file_name = "Numbers.txt";
	int lines = NULL;
	int* array = converter(file_data, lines);
	char data = NULL;

	printf("Menu: \n%c1%c Ver tabela original\n%c2%c Ver tabela ordenada\n%c3%c Escrever a tabela ordenada para o ficheiro\n\n", sl, sl, sl, sl, sl, sl);
	scanf("%i", &dummy);
	printf("\n");

	if (dummy == 1) { //Prints numbers of the file
		read_file(file_name, file_data, &lines);
		for (n = 0; n < lines; n++) {
			printf("%s", file_data[n]);
		}
		printf("\n\n");
		system("pause");
	}
	if (dummy == 2) { //Prints numbers sorted of the file

		file_data = read_file(file_name, file_data, &lines);
		quicksort(array, lines);        //sort the numbers

		for (t = 0; t < lines; t++) {
			printf("%i\n", array);
		}

		printf("\n\n");
		system("pause");

	}

	if (dummy == 3) { //Puts the numbers back into a new file

		FILE *quick = fopen("sorted.txt", "w");

		while (array != NULL) {
			for (n = 0; n < lines; n++) {
				fputc(array[n], quick);
			}
		}

		fclose(quick);

		system("PAUSE");
		return 0;
	}
}