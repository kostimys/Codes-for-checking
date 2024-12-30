#include "stdio.h"
#include "locale.h"
#include "math.h"
#include "stdlib.h"
#include "memory.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


//Вариант с книгами.


typedef struct Object {
	char* author;
	char* name;
	int year;
	int pagecount;
} object;



void create_library(char* userstr, object library[], int i) {

	char Del[] = " ";
	char* f;
	int a = strlen(userstr);
	int c = 0;
	char strt[1000];
	strcpy(strt, userstr, a);

	char** Words = (char**)malloc(sizeof(char*) * 100);
	for (int i = 0; i < 100; i++) {
		Words[i] = (char*)malloc(sizeof(char) * 100);
	}

	printf("%s ", strt);
	f = strt;
	char* p;
	p = strtok(strt, Del);
	while (p != NULL) {
		printf("cycle \n");
		if (isdigit(strt[*p])) {
			strcpy(Words[c], p);
			p = strtok(NULL, Del);
			printf("%s ", Words[c]);
			f = p + 1;
			c++;
		}
		if (isalpha(strt[*p])) {
			strcpy(Words[c], p);
			p = strtok(NULL, Del);
			printf("%s ", Words[c]);
			f = p + 1;
			c++;
		}
		if (strt[(int)p] == "<") {
			p = strtok(strt, ">");
			strcpy(Words[c], p - f);
			printf("%s ", Words[c]);
			f = p + 1;
			c++;
		}
	}

	for (int i = 0; i < c; i++) {
		if (strlen(Words[i]) == 4 && isdigit(Words[i][0])) {
			library[i].year = Words[i];
		}
		if ((2 <= strlen(Words[i]) <= 3) && isdigit(Words[i][0])) {
			library[i].pagecount = Words[i];
		}
		if (Words[i][0] == "<") {
			library[i].name = Words[i];
		}
		if (isalpha(Words[i][0])) {
			library[i].author = Words[i];
		}
	}

	printf("Объект успешно добавлен в картотеку!\n\n");

}






//Test book into library: 1965 V.Bykov <Sotnikov> 153

int main() 
{
	int c = 0, status = 0, count = 0;
	double;
	setlocale(LC_ALL, "Russian");

	//Создание массива-картотеки с базовым ограничением в 100 элементов.
	object** Library = (object**)malloc(sizeof(object*) * 100);
	for (int i = 0; i < 4; i++) {
		Library[i] = (object*)malloc(sizeof(object) * 4);
	}

	while (c < 10) {
		if (status == 0) {
			printf("Выберите действие, которое вы хотите сделать:\n1. Ввести новый объект в картотеку.\n2. Перейти к поиску по всей картотеке.\n\n");
			scanf("%d", &c);

			switch(c) {
			case 1: {
				getchar();
				char strtmp[1000];
				printf("Вводите ваш объект: \n");
				fgets(strtmp, 1000, stdin);
				create_library(strtmp, Library, count);
				count++;
			}

			case 2: {
				if (count == 0) {
					printf("Картотека пуста; невозможно запустить поиск! Пожалуйста, добавьте объекты в картотеку!\n\n");
				}
				else {
					status = 1;
				}
			}

			}
		}

		if (status == 2) {
			printf("Картотека успешно создана и заполнена!");
			printf("Выберите следующее действие: 1. Вывести всю картотеку.\n 2. Добавить еще элементов.\n 3. Завершить работу программы.\n");
			scanf("%d", c);

			switch (c) {
			case 1: {
				for (int i = 0; i < count; i++) {
					for (int j = 0; j < 4; j++) {
						printf("%s   %s   %d   %d", Library[i][j].author, Library[i][j].name, Library[i][j].year, Library[i][j].pagecount);
					}
					printf("\n");
				}
			}
			case 2: {
				status = 1;
			}
			case 3: {
				printf("Thanks for use! GD!");
				c = 11;
			}
			}
		}
	}



	for (int i = 0; i < 4; i++) {
		free(Library[i]);
	}
	free(Library);


	return 0;
}
