// Дана строка символов. Слова в строке отделяются одним пробелом. 
//Поменять местами самое длинное и самое короткое слово.
//


#include <stdio.h>
#include <stdlib.h>

void revers(char* st, int i1, int i2)
{
	char c;
	while (i1 < i2)
	{
		c = *(st + i1); *(st + i1) = *(st + i2); *(st + i2) = c;
		i1++; i2--;
	}
}

int main()
{
	char* str;
	int* l;
	char** words;
	int i, j = 0, n, m = 0, k = 0, d = 0;

	printf("Line length: ");
	scanf_s("%d\n", &n);
	n++;

	str = (char*)malloc(n * sizeof(char));	// Выделение памяти.

	fgets(str, n, stdin);

	puts(str);

	k = 0;
	for (i = 0; i < n; i++) { // Подсчёт количества пробелов.
		if (str[i] == ' ') {
			m++;
			k++;
		}
	}
	++m;

	printf("Words number: %d\n", m);

	while ((str[d] != ' ') &(str[d + 1] != ' ')) {
		d++;
	}

	l = (int*)calloc(m, sizeof(int));

	k = 0;
	for (i = 0; i < m; i++) {  //Подсчёт кол-ва символов в словах.
		while ((str[k] != ' ') & (str[k] != '\0') & (str[k] != '\n')) {
			l[i]++;
			k++;
		}
		k++;
	}

	int lmax = l[0]; //Нахождение длины самого длинного слова.
	int nmax = 0;
	int kmax = 0;
	for (i = 0; i < m; i++) {
		if (l[i] > lmax) {
			lmax = l[i];
		}
	}

	int lmin = l[0]; //Нахождение длины самого короткого слова.
	int nmin = 0;
	int kmin = 0;
	for (i = 0; i < m; i++) {
		if (l[i] < lmin) {
			lmin = l[i];
		}
	}
	
	int* space;
	space = (int*)malloc((m) * sizeof(int));
	space[0] = -1;
	k = 1;
	for (i = 0; i < n; i++) { // Нахождение позиций пробелов.
		if (str[i] == ' ') {
			space[k] = i;
			k++;
		}
	}

	for (i = 0; i < m; i++) { // Нахождение позиций первого и последнего символа наибольшего слова в строке.
		if (l[i] = lmax) {
			nmax = space[i] + 1;
			kmax = space[i] + lmax;
		}
	}
	for (i = 0; i < m; i++) {
		if (l[i] = lmin) { // Нахождение позиций первого и последнего символа наименьшего слова в строке.
			nmin = space[i] + 1;
			kmin = space[i] + lmin;
		}
	}
	printf("lmax %d   lmin %d ", lmax, lmin);
	printf("\n");
	printf("nmax %d   nmin %d ", nmax, nmin);
	printf("\n");
	printf("kmax %d   kmin %d ", kmax, kmin);
	printf("\n");
	for (i = 0; i < m; i++) {
		printf("%d  ", space[i]);
	}


	free(l);
	free(str);
	free(space);

	return 0;
}
