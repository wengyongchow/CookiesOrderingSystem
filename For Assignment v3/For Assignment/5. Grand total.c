#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int grand_total = 0;

void main()
{

	int num1;
	int num2;

	int total = 0;
	int reponse;

	do {

		printf("\nCurrent Grand Total --> %d \n\n", grand_total);

		printf("Num 1: ");
		scanf("%d", &num1);

		printf("Num 2: ");
		scanf("%d", &num2);

		total = num1 + num2;

		printf("Total --> %d \n\n", total);


		printf("Press 1 to continue: ");
		scanf("%d", &reponse);

		grand_total = grand_total + total;

	} while (reponse == 1);

	printf("\n\n*** Final Grand Total --> %d ***\n\n", grand_total);


	system("pause");
}