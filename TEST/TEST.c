#include <stdio.h>
#include <stdlib.h>

void handle_line(char *line) {
	printf("%s", line);
}

int read_file() { //reads the file
	int size = 1000, pos;
	int c;
	char *buffer = (char *)malloc(size);

	FILE *f = fopen("Numbers.txt", "r");
	if (f) {
		do {
			pos = 0;
			do {
				c = fgetc(f);
				if (c != EOF) buffer[pos++] = (char)c;
				if (pos >= size - 1) {
					size *= 2;
					buffer = (char*)realloc(buffer, size);
				}
			} while (c != EOF && c != '\n');
			buffer[pos] = 0;

			handle_line(buffer);
		} while (c != EOF);
		fclose(f);
	}
	free(buffer);
	return 0;
}

void quicksort(int *array, int size)     //sorting function for the array
{
	int a, b, temp;

	for (a = 0; a<(size - 1); a++) {
		for (b = a = 1; b<size; b++) {
			if (array[a] > array[b]) {
				temp = array[b];
				array[b] = array[a];
				array[a] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	char sl = 178;
	int dummy;
	
	char c;
	int n;
	int array[101];

	printf("Menu: \n%c1%c Ver tabela original\n%c2%c Ver tabela ordenada\n%c3%c Escrever a tabela ordenada para o ficheiro\n\n", sl, sl, sl, sl, sl, sl);
	scanf("%i", &dummy);
	printf("\n");

	if (dummy == 1) { //Prints numbers of the file
		read_file();
		printf("\n\n");
		system("pause");
	}
	if (dummy == 2) { //Prints numbers sorted of the file

		FILE *f = fopen("Numbers.txt", "r");
		FILE *quick = fopen("sorted.txt", "w");

		while ((c = fgetc(f)) != EOF) {   //gets the numbers, put them into an array
			for (n = 0; n < 1000; n++) {
				if (c != '\n') {
					array[n] = c;
				}
			}
		}

		quicksort(array, 101);        //sort the numbers

		printf("%s", array);

		if (dummy == 3) { //Puts the numbers back into a new file

			while (array != NULL) {
				for (n = 0; n < 101; n++) {
					fputc(array[n], quick);
				}
			}

			fclose(quick);

			system("PAUSE");
			return 0;
		}
	}
}
//TEST