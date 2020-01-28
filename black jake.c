#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int row;
int colum;
static int card;
static int Pcard;
static int Bcard;
int Bot = 0;
int Player = 0;
void shuffle(int wd[][13]);
void Bduel(const int wd[][13], const char* wf[], const char* ws[], int cost[]);
void Pduel(const int wd[][13], const char* wf[], const char* ws[], int cost[]);
void Bdraw(const int wd[][13], const char* wf[], const char* ws[], int cost[]);
void DeadsTinyDraw(const int wd[][13], const char* wf[], const char* ws[], int cost[]);
void check();

int main()
{

	const char* suit[4] = { "HEART","DIAMON","CLUBS","SPADES" };
	const char* face[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	int suitcost[13] = { 11,2,3,4,5,6,7,8,9,10,10,10,10 };
	int deck[4][13] = { 0 };
	int again;
	srand(time(NULL));
	shuffle(deck);
		printf("BOT\n");
		Bduel(deck, face, suit, suitcost);
		printf("\nPLAYER\n");
		Pduel(deck, face, suit, suitcost);
		Bdraw(deck, face, suit, suitcost);
		DeadsTinyDraw(deck, face, suit, suitcost);
		check();
		
		
	getchar();
	getchar();
	return 0;
}

void shuffle(int wd[][13])
{
	for (card = 0; card < 52; card++)
	{
		do
		{
			row = rand() % 4;
			colum = rand() % 13;
		} while (wd[row][colum] != 0);

		wd[row][colum] = card;
		Bcard = card;
		Pcard = card;

	}
}

void Bduel(const int wd[][13], const char* wf[], const char* ws[], int cost[])
{
	for (Bcard = 51; Bcard > 49; Bcard--)
	{
		for (row = 0; row < 4; row++)
		{
			for (colum = 0; colum < 13; colum++)
			{
				if (wd[row][colum] == Bcard)
				{
					printf("\n%5s of %-8s\n", wf[colum], ws[row]);
					if (Bot + cost[0] <= 21)
					{
						cost[0] = 11;
					}
					if (Bot + cost[0] > 21)
					{
						cost[0] = 1;
					}
					Bot += cost[colum];
				}
			}
		}
	}
	printf("\nBOT score is:%d\n", Bot);
	if (Bot == 21)
	{
		printf("\n*BLACK JACK*\n");
	}
}

void Pduel(const int wd[][13], const char* wf[], const char* ws[], int cost[])
{
	for (Pcard = 28; Pcard > 26; Pcard--)
	{
		for (row = 0; row < 4; row++)
		{
			for (colum = 0; colum < 13; colum++)
			{
				if (wd[row][colum] == Pcard)
				{
					printf("\n%5s of %-8s\n", wf[colum], ws[row]);
					if (Player + cost[0] <= 21)
					{
						cost[0] = 11;
					}
					if (Player + cost[0] > 21)
					{
						cost[0] = 1;
					}
					Player += cost[colum];
				}
			}
		}
	}
	printf("\nPlayer score is:%d\n", Player);
	if (Player == 21)
	{
		printf("\n*BLACK JACK*\n");
	}
}

void Bdraw(const int wd[][13], const char* wf[], const char* ws[], int cost[])
{
	for (; Bot < 16; Bcard--)
	{
		for (row = 0; row < 4; row++)
		{
			for (colum = 0; colum < 13; colum++)
			{
				if (wd[row][colum] == Bcard)
				{
					printf("\n%5s of %-8s\n", wf[colum], ws[row]);
					if (Bot + cost[0] > 21)
					{
						cost[0] = 1;
					}
					Bot += cost[colum];
					printf("\nBOT score is:%d\n", Bot);
					if (Bot == 21)
					{
						printf("\n*BLACK JACK*\n");
					}
				}
			}
		}
	}
}

void DeadsTinyDraw(const int wd[][13], const char* wf[], const char* ws[], int cost[])
{
	int value;
	do {
		if (Player < 16)
		{
			printf("\nEnter 1 to draw\n");
		}
		if (Player >= 16 && Player < 21)
		{
			printf("\nEnter 1 to draw or 0 to stop\n");
		}
		scanf("%d", &value);
		for (; value == 1; Pcard++)
		{
			for (row = 0; row < 4; row++)
			{
				for (colum = 0; colum < 13; colum++)
				{
					if (wd[row][colum] == Pcard && Player < 21)
					{
						printf("\n%5s of %-8s\n", wf[colum], ws[row]);
						if (Player + cost[0] <= 21)
						{
							cost[0] = 11;
						}
						if (Player + cost[0] > 21)
						{
							cost[0] = 1;
						}
						Player += cost[colum];
					}
				}
			}
			printf("\nPlayer score is:%d\n", Player);
			if (Player == 21)
				printf("\n*BLACK JACK*\n");
			if (Player > 21)
				check();
			scanf("%d", &value);

		}
	} while (value == 1);
}

void check()
{
	printf("\nBOT score:Player score is %d:%d\n", Bot, Player);

	if (Bot < Player && Bot < 22 && Player < 22)
	{
		printf("Player WIN");
	}
	if (Bot < 22 && Player>21)
	{
		printf("Bot WIN");
	}
	if (Bot > 21 && Player < 22)
	{
		printf("Player WIN");
	}
	if (Bot > Player&& Bot < 22 && Player < 22)
	{
		printf("Bot WIN");
	}
	if (Bot == Player && Bot < 22 && Player < 22)
	{
		printf("DUEL");
	}
	if (Bot > 21 && Player > 21)
	{
		printf("DUEL");
	}
}