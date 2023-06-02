#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#pragma warning (disable: 4996)

void main()
{
 
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("\n");
	printf("Date: %d-%d-%d\n\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("Time: %d:%d:%d\n\n", tm.tm_hour - 12, tm.tm_min, tm.tm_sec);

	system("pause");


}