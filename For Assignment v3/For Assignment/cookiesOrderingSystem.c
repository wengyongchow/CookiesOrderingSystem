/*
written by = chow weng yong
program    = assignment 2019
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#pragma warning(disable:4996)
#define LOVE_LETTER 25.00
#define NUT_COOKIES 20.00
#define ASSORTED_COOKIES 15.00

//-->Love letter= item1 , nutcookies= item2 , assortedcookies= item3
int customerno = 0;
int sumitem1, sumitem2, sumitem3;
int quantityitem1, quantityitem2, quantityitem3;

double item1sub, item2sub, item3sub;

double totalitem1, totalitem2, totalitem3;
double totaldiscount;
double discount;
double deposit;
double total;
double amountpay;
double balance;
double deliveryfee;

//sum is for summary part
double sumtotalitem1 = 0, sumtotalitem2 = 0, sumtotalitem3 = 0;
double sumdiscount = 0;
double sumsale = 0;
double sumdeliveryfee = 0;
double sumbalance = 0;
double sumdeposit = 0;
double sumNetsale = 0;


void menu();
void ordernote();
void delivery();
void resit();
void summary();

void main()
{
	menu();
	ordernote();
	resit();
	summary();
	system("pause");
}

void menu()
{
	char start;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("#######    #    ######  #     #  #####     #######                                         #####                                           #####                   ######                   \n");
	printf("   #      # #   #     # #     # #     #    #       ######  ####  ##### # #    # ######    #     #  ####   ####  #    # # ######  ####     #     # #####  #    #    #     # #    # #####     \n");
	printf("   #     #   #  #     # #     # #          #       #      #        #   # #    # #         #       #    # #    # #   #  # #      #         #       #    # ##   #    #     # #    # #    #    \n");
	printf("   #    #     # ######  #     # #          #####   #####   ####    #   # #    # #####     #       #    # #    # ####   # #####   ####      #####  #    # # #  #    ######  ###### #    #    \n");
	printf("   #    ####### #   #   #     # #          #       #           #   #   # #    # #         #       #    # #    # #  #   # #           #          # #    # #  # #    #     # #    # #    #    \n");
	printf("   #    #     # #    #  #     # #     #    #       #      #    #   #   #  #  #  #         #     # #    # #    # #   #  # #      #    #    #     # #    # #   ##    #     # #    # #    #    \n");
	printf("   #    #     # #     #  #####   #####     #       ######  ####    #   #   ##   ######     #####   ####   ####  #    # # ######  ####      #####  #####  #    #    ######  #    # #####     \n");
	printf("\n\n*******************************************************************************************************************************************************************************************\n");
	printf("________________________________________________________________________\n");
	printf("[\t\tDATE : %d-%d-%d                                       ]\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("[\t\tTIME : %d:%d:%d                                        ]\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("[----------------------------------------------------------------------]\n");
	printf("[\tLOVE LETTER     = RM25.00                                      ]\n");
	printf("[\tNUT COOKIES     = RM20.00                                      ]\n");
	printf("[\tASSORTED COOKIES= RM15.00                                      ]\n");
	printf("[\t5%%  off if purchase total between RM500-RM1000                 ]\n");
	printf("[\t10%% off if purchase total more than RM1000                     ]\n");
	printf("[----------------------------------------------------------------------]\n");
	printf("\tstart ordering ? Y/N ");
	scanf(" %c", &start);
	if (start != 'y' || start != 'Y')
	{
		printf("OKAY \n ");
	}
	else
	{
		ordernote();
	}
}
void ordernote()
{
	char comfirmOrder;

	do
	{


		system("cls");
		rewind(stdin);
		customerno++;
		printf("Order No:%d\n", customerno);
		printf("Item Quantity required\n ");

		printf("LOVE LETTER @ RM25.00 PER TIN      : ");
		scanf("%d", &quantityitem1);
		totalitem1 = quantityitem1 * LOVE_LETTER;
		printf("\aLOVE LETTER ORDER                  = RM%5.2lf \n", totalitem1);
		item1sub = totalitem1;
		printf("Order SubTotal                     = RM%5.2lf \n\n", item1sub);

		printf("NUT COOKIES @ RM20.00 PER JAR      : ");
		scanf("%d", &quantityitem2);
		totalitem2 = quantityitem2 * NUT_COOKIES;
		printf("\aNut cookies Order                  = RM%5.2lf \n", totalitem2);
		item2sub = totalitem1 + totalitem2;
		printf("Order Subtotal                     = RM%5.2lf \n\n", item2sub);

		printf("ASSORTED COOKIES @ RM15.00 PER JAR : ");
		scanf("%d", &quantityitem3);
		totalitem3 = quantityitem3 * ASSORTED_COOKIES;
		printf("\aAssorted cookies Order             = RM%5.2lf \n", totalitem3);
		item3sub = totalitem1 + totalitem2 + totalitem3;
		printf("Order SubTotal                     = RM%5.2lf \n\n", item3sub);

		printf("comfirm / cancel order(Y=comfirm)> ");
		scanf(" %c", &comfirmOrder);


		if (comfirmOrder != 'y' && comfirmOrder != 'Y')
		{
			customerno--;
		}
		else
		{
			delivery();
		}
	} while (comfirmOrder != 'y' && comfirmOrder != 'Y');

	if (item3sub >= 500 && item3sub < 1000)
	{
		discount = 0.05;
	}
	else if (item3sub >= 1000)
	{
		discount = 0.1;
	}
	else
	{
		discount = 0;
	}

	totaldiscount = item3sub * discount;

	printf("DISCOUNT(%.2lf)    : RM %10.2lf \n", discount, totaldiscount);
	printf("AMOUNT TO PAY     : RM %10.2lf \n", item3sub);
	printf("DEPOSIT           = RM ");
	scanf("%lf", &deposit);

	total = item3sub + deliveryfee - deposit - totaldiscount;
	sumitem1 = sumitem1 + quantityitem1;
	sumitem2 = sumitem2 + quantityitem2;
	sumitem3 = sumitem3 + quantityitem3;
	sumtotalitem1 = sumtotalitem1 + totalitem1;
	sumtotalitem2 = sumtotalitem2 + totalitem2;
	sumtotalitem3 = sumtotalitem3 + totalitem3;
	sumdiscount = sumdiscount + totaldiscount;
	sumdeposit = sumdeposit + deposit;
	sumdeliveryfee = sumdeliveryfee + deliveryfee;

	resit();
}
//-->EXTRA FEATURES
void delivery()
{
	char delivery;
	char side;

	printf("Need delivery ? [Y/N] ");
	scanf(" %c", &delivery);

	if (delivery == 'y' || delivery == 'Y')
	{
		printf("Enter the side of your location (E=east)&(W=west) :");
		scanf(" %c", &side);
		if (side == 'w' || side == 'W')
		{
			deliveryfee = 20.0;
			printf("The delivery fee is RM %10.2lf\n", deliveryfee);
		}
		else
		{
			deliveryfee = 50.0;
			printf("The delivery fee is RM %10.2lf\n", deliveryfee);
		}
	}
	else
	{
		deliveryfee = 0;
		printf("The delivery fee is RM %10.2lf\n", deliveryfee);
	}
}

void resit()
{
	char nextorder;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	system("cls");
	printf("\a=================================================================================================================================================================================\n");
	printf("TARUC FESTIVE COOKIES SDN BHD                                     Phone : 0123456789  \n");
	printf("ORDER NOTE Order Date:  %d-%d-%d \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("your order number is %d \n", customerno);
	printf("*-------------------------------------------------------------*\n");
	printf("| %d\t LOVE LETTER       @RM %.2lf PER TIN  : RM %10.2lf |\n", quantityitem1, LOVE_LETTER, totalitem1);
	printf("| %d\t NUT COOKIES       @RM %.2lf PER JAR  : RM %10.2lf |\n", quantityitem2, NUT_COOKIES, totalitem2);
	printf("| %d\t ASSORTED COOKIES  @RM %.2lf PER JAR  : RM %10.2lf |\n", quantityitem3, ASSORTED_COOKIES, totalitem3);
	printf("|                                        -----------------    |\n");
	printf("|                       ORDER TOTAL        : RM  %10.2lf   |\n", item3sub);
	printf("|                       DISCOUNT (%.2lf)    : RM  %10.2lf   |\n", discount, totaldiscount);
	printf("|                       DELIVERY FEE       : RM  %10.2lf   |\n", deliveryfee);
	printf("|                                        -----------------    |\n");
	amountpay = item3sub - totaldiscount + deliveryfee;
	printf("|                       AMOUNT TO PAY      : RM  %10.2lf   |\n", amountpay);
	printf("|                       DEPOSIT PAID       : RM  %10.2lf   |\n", deposit);
	printf("|                                        -----------------    |\n");
	balance = amountpay - deposit;
	printf("|                       BALANCE            : RM  %10.2lf   |\n", balance);
	printf("*-------------------------------------------------------------*\n");
	printf("\n");
	printf("Thank You For Your Order. \n");
	printf("Please bring this Order Note when collecting your cookies. :-)");
	printf("========================================================================================================================\n\n");
	printf("\n\n");
	printf("Next Order? [Y/N] ");
	scanf(" %c", &nextorder);
	if (nextorder == 'y' || nextorder == 'Y')
	{
		ordernote();
	}
	else
	{
		summary();
	}
}
void summary()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	system("cls");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\tORDER SUMMARY FOR TODAY (%d-%d-%d)\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("\t\t==================================\n");
	printf("Total number of customer Order : %d \n", customerno);
	printf("Total Order unit price amount \n ");
	printf("%d\t LOVE LETTER       @RM %.2lf PER TIN  : RM   %10.2lf \n", sumitem1, LOVE_LETTER, sumtotalitem1);
	printf("%d\t NUT COOKIES       @RM %.2lf PER JAR  : RM   %10.2lf \n", sumitem2, NUT_COOKIES, sumtotalitem2);
	printf("%d\t ASSORTED COOKIES  @RM %.2lf PER JAR  : RM   %10.2lf \n", sumitem3, ASSORTED_COOKIES, sumtotalitem3);
	printf("\t                                          ----------------\n");
	sumsale = sumtotalitem1 + sumtotalitem2 + sumtotalitem3;
	printf("\t                   Total sales        : RM   %10.2lf \n", sumsale);
	printf("\t                   Total discount     : RM   %10.2lf \n", sumdiscount);
	printf("\t                                          ================\n");
	sumNetsale = sumsale - sumdiscount;
	printf("\t                   Total Net sale     : RM   %10.2lf \n", sumNetsale);
	printf("\t                   Total deposit      : RM   %10.2lf \n", sumdeposit);
	printf("\t                   Total Delivery fee : RM   %10.2lf \n", sumdeliveryfee);
	printf("\t                                          ================\n");
	sumbalance = sumNetsale - sumdeposit + sumdeliveryfee;
	printf("\t                   Total balance      : RM   %10.2lf \n", sumbalance);
	printf("\t                                          ================\n");
}

