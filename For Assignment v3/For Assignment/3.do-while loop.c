#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

void main()
{

	int answer = 0;
	int response;

	do {

		//**********************************
		printf("\nQuestion :  2 + 2 = ? \n");
		printf("Your answer is :  ");
		scanf("%d", &answer);

		if (answer == 4)
		{
			printf("\nYes! You are correct! The answer is 4 \n\n");
		}
		else {
			printf("\nIncorrect!\n\n");
		}
		//**********************************

		printf("Press 1 to continue:  ");
		scanf("%d", &response);

	}while(response == 1);




	system("pause");
}