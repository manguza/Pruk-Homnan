#include<stdio.h>

main(void) {
	
	int number[5] = { 1, 2, 3, 4, 5 };
	int numSeat;
	int numMenu;
	//int again;
	
		do {
			printf("\n========================= WAWA HOUSE =============================\n");
			printf("----------------------Please choose menu--------------------------\n");
			printf("[1] At here\n");
			printf("[2] Go home\n");
			printf("Enter the number [1-2] : ");
			scanf("%d", &numMenu);


			switch (numMenu) {
			case 1:
				do {
					printf("\n");
					printf("At here\n");
					printf("Which seat [1-5] : ");
					scanf("%d", &numSeat);

					switch (numSeat) {
					case 1:
						printf("\nSeat number %d\n", number[0]);
						Menu();
						break;

					case 2:
						printf("\nSeat number %d\n", number[1]);
						Menu();
						break;

					case 3:
						printf("\nSeat number %d\n", number[2]);
						Menu();
						break;

					case 4:
						printf("\nSeat number %d\n", number[3]);
						Menu();
						break;

					case 5:
						printf("\nSeat number %d\n", number[4]);
						Menu();
						break;

					default:
						printf("\nYou enter wrong number, Please try again\n");
						break;
					}


				} while (numSeat <= 0 || numSeat >= 6);


				break;

			case 2:
				printf("\n");
				printf("Go home\n");
				Menu();
				break;

			default:
				printf("\nYou enter wrong number, Please try again\n");
				break;
			}

		} while (numMenu <= 0 || numMenu >= 3);
	
}

Menu() {

	int AllMenu;

	do {
		printf("\nWhat do you want [1]Beverage, [2]Desert, [3]Appetizers[C] : ");
		scanf("%d", &AllMenu);

		switch (AllMenu) {
		case 1:
			printf("\nYou choose Beverage, It's menu have\n");
			beverage();
			break;

		case 2:
			printf("\nYou choose Desert, It's menu have\n");
			desert();
			break;

		case 3:
			printf("\nYou choose Appetizers, It's menu have\n");
			appetizer();
			break;

		default:
			printf("\nYou enter wrong number, Please try again\n");
			break;
		}
	} while (AllMenu <= 0 || AllMenu >= 4);

}

beverage() {
	char* MenuBev[] = { "Water","Orange Juice","Coffee","Blue Hawaii Soda","Strawberry Soda" };
	int price[] = { 10, 40, 50, 45 };
	int choose;
	int amount;

	do {
		printf("\nI have a [1]%s [2]%s [3]%s [4]%s [5]%s\n", MenuBev[0], MenuBev[1], MenuBev[2], MenuBev[3], MenuBev[4]);
		printf("\nWhat do you want a Beverage ? : ");
		scanf("%d", &choose);

		switch (choose) {
		case 1:
			printf("\nYou choose %s, price %d Baht\n", MenuBev[0], price[0]);
			printf("How many do you want : ");
			scanf("%d",&amount);
			calculator(price[0], amount);
			break;

		case 2:
			printf("\nYou choose %s, price %d Baht\n", MenuBev[1], price[1]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[1], amount);
			break;

		case 3:
			printf("\nYou choose %s, price %d Baht\n", MenuBev[2], price[2]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[2], amount);
			break;

		case 4:
			printf("\nYou choose %s, price %d Baht\n", MenuBev[3], price[3]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[3], amount);
			break;

		case 5:
			printf("\nYou choose %s, price %d Baht\n", MenuBev[4], price[3]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[3], amount);
			break;

		default:
			printf("\nYou enter wrong number, Please try again\n");
			break;
		}
	} while (choose <= 0 || choose >= 6);

}

desert() {
	char* MenuDes[] = { "Coconut Pie","Cheese Cake","Bingsu Strawberry","Honey Toast","Strawberry Toast" };
	int price[] = { 39, 99, 89 };
	int choose;
	int amount;

	do {
		printf("\nI have a [1]%s [2]%s [3]%s [4]%s [5]%s\n", MenuDes[0], MenuDes[1], MenuDes[2], MenuDes[3], MenuDes[4]);
		printf("\nWhat do you want a Beverage ? : ");
		scanf("%d", &choose);

		switch (choose) {
		case 1:
			printf("\nYou choose %s, price %d Baht\n", MenuDes[0], price[0]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[0], amount);
			break;

		case 2:
			printf("\nYou choose %s, price %d Baht\n", MenuDes[1], price[0]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[0], amount);
			break;

		case 3:
			printf("\nYou choose %s, price %d Baht\n", MenuDes[2], price[1]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[1], amount);
			break;

		case 4:
			printf("\nYou choose %s, price %d Baht\n", MenuDes[3], price[2]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[2], amount);
			break;

		case 5:
			printf("\nYou choose %s, price %d Baht\n", MenuDes[4], price[2]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[2], amount);
			break;

		default:
			printf("\nYou enter wrong number, Please try again\n");
			break;
		}
	} while (choose <= 0 || choose >= 6);

}

appetizer() {
	char* MenuApp[] = { "Pork Steak","Beef Steak","Chicken Steak","Carbonara Spaghetti","Spicy Stir Fried Spaghetti" };
	int price[] = { 119, 129, 99 };
	int choose;
	int amount;

	do {
		printf("\nI have a [1]%s [2]%s [3]%s [4]%s [5]%s\n", MenuApp[0], MenuApp[1], MenuApp[2], MenuApp[3], MenuApp[4]);
		printf("\nWhat do you want a Beverage ? : ");
		scanf("%d", &choose);

		switch (choose) {
		case 1:
			printf("\nYou choose %s, price %d Baht\n", MenuApp[0], price[0]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[0], amount);
			break;

		case 2:
			printf("\nYou choose %s, price %d Baht\n", MenuApp[1], price[1]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[1], amount);
			break;

		case 3:
			printf("\nYou choose %s, price %d Baht\n", MenuApp[2], price[0]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[0], amount);
			break;

		case 4:
			printf("\nYou choose %s, price %d Baht\n", MenuApp[3], price[2]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[2], amount);
			break;

		case 5:
			printf("\nYou choose %s, price %d Baht\n", MenuApp[4], price[2]);
			printf("How many do you want : ");
			scanf("%d", &amount);
			calculator(price[2], amount);
			break;

		default:
			printf("\nYou enter wrong number, Please try again\n");
			break;
		}
	} while (choose <= 0 || choose >= 6);

}

calculator(int price, int amount) {
	
	int received, change, total;

	total = price * amount;
	do {
		printf("\nTotal price %d baht", total);
		printf("\nReceived money : ");
		scanf("%d", &received);

		change = received - total;

		if (received < total) {
			printf("\n##############################\n");
			printf("  Received too little money\n");
			printf(" Please input received again");
			printf("\n##############################\n");
		}else {
			printf("\nChange %d baht\n", change);
			printf("\n#########################################################\n");
			printf("####################### Thank you #######################");
			printf("\n#########################################################\n");
		}
	} while (received < total);

}
