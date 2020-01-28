#include <stdio.h>
#include <time.h>
#define SIZE 10

int Show(int numberproduct, char *product[], int price[], int Currency[],int productlist[]);

int main()
{
	int number = 0;
	int list = 0;
	int productlist[SIZE];

	char *product[] = { "Pen","Ballpoint pen","Mechanical pencil","Chalk","Paint brush","Rubber","Marker","Glue stick","Staple","Paper clip" };
	int price[] = { 20,40,50,20,15,8,23,52,85,18 };
	char Currency[] = "BAHT";
	int numberproduct = (sizeof(product)) / 4;
	srand(time(NULL));
	for (int i = 0; i < numberproduct; i++) productlist[i] = 0;

	while (list != -1)
	{
		Show(numberproduct, product, price, Currency, productlist);
		list = 0;
		number = 0;
		printf("Sclect product    : ");
		scanf_s("%d", &list);
		getchar();

		if (list == -1) goto end;

		if (list > 0 && list <= numberproduct )
		{
			printf("Number of product : ");
			scanf_s("%d", &number);
			getchar();

			if ((productlist[list - 1] + number) >= 0)
			{
				productlist[list - 1] += number;
			}
			else
			{
				printf("Please do the transaction again.\n");
			}
		}
		else if (list == numberproduct + 1)
		{
			printf("Enter amount : ");
			scanf_s("%d", &number);
			getchar();
			int ranD = 0;
			for(int adm = 0; adm <= 1000; adm++)
			{
				ranD = (rand() % numberproduct);
				while ((number - price[ranD]) >= 0)
				{
					number -= price[ranD];
					productlist[ranD]++;
					ranD = (rand() % numberproduct);
				}
			}
		}
		else if (list == numberproduct + 2)
		{

		}
		else printf("\n\nERROR\n\n");
	}
end:;
	getchar();
	return 0;
}

int Show(int numberproduct, char *product[], int price[], int Currency[], int productlist[])
{
	system("cls");
	int count = 0;
	int total = 0;
	printf("+----------------------------------+");
	printf("\n|\tPRODUCT LIST    PRICE      |\n");
	printf("+----------------------------------+");

	for (int i = 0; i < numberproduct; i++)
	{
		printf("\n| %2d. %-20s %2d %s |", i + 1, product[i], price[i], Currency);
	}
	printf("\n| %2d. Random                       |", numberproduct + 1);
	printf("\n| %2d. Random                       |", numberproduct + 2);
	printf("\n+----------------------------------+");

	printf("\n  -1. Pay money\n\n");
	for (int i = 0; i < numberproduct; i++) count += productlist[i];
	if (count > 0)
	{
		printf("List of products you selected\n\n");
		for (int i = 0; i < numberproduct; i++)
		{
			if (productlist[i] > 0)
			{
				printf("%-20s %3d Items %6d %s\n", product[i], productlist[i], price[i] * productlist[i], Currency);
				total += (price[i] * productlist[i]);
			}
		}
		printf("Total%32d %s\n", total, Currency);
		printf("\nIf deleting the product, put a sign (-) before the item.\n");
	}
}