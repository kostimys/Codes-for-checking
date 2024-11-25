#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#pragma warning(disable: 4996)

int main()
{
	int s, n, x, y, z;
	printf("Input sum of digits in number: ");
	scanf("%d", &s);

	while (s > 27) {
		printf("Wrong sum for three-signed number. \nTry again: ");
		s = 0;
		scanf("%d", &s);
	}

	if (1 <= s <= 27) {
		for (x = 1; x <= 9; x++) {
			for (y = 0; y <= 9; y++) {
				for (z = 0; z <= 9; z++) {
					if (x + y + z == s) {
						n = x * 100 + y * 10 + z;
						printf("%d  ", n);
					}
				}
			}
		}
	}

	else {
		printf("Wrong sum for three-signed number. \nTry again: ");
		s = 0;
		scanf("%d", &s);
	}

	return 0;
}
