#include "time.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h" 
#pragma warning(disable: 4996)


int main(void)
{
	srand(time(NULL));
	int bcount, ccount, r, min, max, n;
	min = 1000;
	max = 9999;
	n = 0;
	ccount = 0;
	bcount = 0;
	r = (double)rand() / RAND_MAX * (max - min); //Генератор случайных чисел.
	printf("\n%d ", r);

	//Ввод пользователем четырехзначного числа.
	printf("Input four-signs number: ");
	scanf("\n%d", &n);

	//Проверка на коров(elementary).
	if ((r % 10) == (n % 10)) {
		ccount++;
	}
	if ((r / 10) % 10 == (n / 10) % 10) {
		ccount++;
	}
	if ((r / 100) % 10 == (n / 100) % 10) {
		ccount++;
	}
	if ((r / 1000) == (n / 1000)) {
		ccount++;
	}

	//Проверка на быков.

	int A[4] = { 0, 0, 0, 0 };
	int B[4] = { 0, 0, 0, 0 };

	// Закидываем значения цифр в массив для случайного числа.
	for (int i = 0, c = 1000; i <= 3; i++, c = c / 10) {
		A[i] = (r / c) % 10;
	}
	printf("%d%d%d%d \n", A[0], A[1], A[2], A[3]);

	// Закидываем значения цифр в массив для числа, введенного юзером.
	for (int i = 0, c = 1000; i <= 3; i++, c = c / 10) {
		B[i] = (n / c) % 10;
	}
	printf("%d%d%d%d \n\n", B[0], B[1], B[2], B[3]);

	// Тут организовываем вложенный цикл на перебор всех чисел между массивами, соответсвенно, исключая комбинации, дающие нам коров(ибо будет двойной подсчет).

	//Но сначала микро проверка на повторяющиеся числа при последующем переборе.
	int x = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (A[i] == A[j] && i != j) {
				x++;
			}
		}
	}

	int y = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (B[i] == B[j] && i != j) {
				y++;
			}
		}
	}


	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (A[i] == B[j] && i != j) {
				bcount++;
			}
		}
	}

	bcount = bcount - (x / 2) - (y / 2);

	//Результат.
	printf("Random number: %d \n", r);
	printf("User's number: %d \n", n);
	printf("Bulls: %d \nCows: %d", bcount, ccount);

	return 0;
}
