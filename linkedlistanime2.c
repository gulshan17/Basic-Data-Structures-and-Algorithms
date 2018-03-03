#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
int count = 0;
void insrt(void);
void delet(void);
void display(int count);
void clrscr();
void delay(unsigned int m);

int main(void)
{
	int ch = 1;
	printf("************Welcome to Linked List Implementation***********\n");
	clrscr();
	display(count);
	delay(1000);
	do
	{
		printf("Please Press:\n1.for insertion\n2.for deletion\nAny other number(don't press any alphabet or special character) to exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insrt();
			break;

		case 2:
			delet();
			break;

		default:
			exit(0);
		}
	} while ((ch == 1) || (ch == 2));
	return 0;
}

void insrt(void)
{
	int position;
label1:
	printf("Enter the position at which you want to insert the data\n");
	scanf("%d", &position);
	while ((position>count + 1) || (position<1))
	{
		printf("Please Enter a valid postion as there are only %d nodes present\n", count);
		scanf("%d", &position);
	}

	struct node *temp, *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Please enter the data you want to insert\n");
	scanf("%d", &ptr->data);
	if (position == 1)
	{
		if (count == 0)
		{
			head = ptr;
			ptr->next = NULL;
			count++;
		}

		else
		{
			ptr->next = head;
			head = ptr;
			count++;
		}
	}

	else if (position>1 && position <= count)
	{
		temp = head;
		int i;
		for (i = 0; i<position - 2; i++)
		{
			temp = temp->next;
		}
		ptr->next = temp->next;
		temp->next = ptr;
		count++;
	}

	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = NULL;
		count++;
	}
	clrscr();
	display(count);
	delay(1000);
}

void display(int n)
{
	struct node *temp = head;
	int j = 1;
	if (n == 0)
	{
		printf("                                                         _______\n");
		delay(17);
		printf("                                                        |       |\n");
		delay(170);
		printf("                                                        | Head  |\n");
		delay(170);
		printf("                                                        |_______|\n");
		delay(170);
		printf("                                                            |\n");
		delay(170);
		printf("                                                            |\n");
		delay(17);
		printf("                                                            V\n");
		delay(17);
		printf("                                                           NULL");
	}
	else
	{
		printf("                                                         _______\n");
		delay(17);
		printf("                                                        |       |\n");
		delay(17);
		printf("                                                        | Head  |\n");
		delay(50);
		printf("                                                        |_______|\n");
		delay(50);
		printf("                                                            |\n");
		delay(17);
		printf("                                                            |\n");
		delay(17);
		printf("                                                         ___V___\n");
		delay(17);
		for (j = 1; j < n; j++, temp = temp->next)
		{
			printf("                                                        |       |\n");
			delay(17);
			printf("                                                        | %5d |\n", temp->data);
			delay(17);
			printf("                                                        |_______|\n");
			delay(17);
			printf("                                                        |       |\n");
			delay(17);
			printf("                                                        | Next  |\n");
			delay(17);
			printf("                                                        |_______|\n");
			delay(17);
			printf("                                                            |\n");
			delay(17);
			printf("                                                            |\n");
			delay(17);
			printf("                                                         ___V___\n");
		}
			printf("                                                        |       |\n");
			delay(17);
			printf("                                                        | %5d |\n", temp->data);
			delay(17);
			printf("                                                        |_______|\n");
			delay(17);
			printf("                                                        |       |\n");
			delay(17);
			printf("                                                        | Next  |\n");
			delay(17);
			printf("                                                        |_______|\n");
			delay(17);
			printf("                                                            |\n");
			delay(17);
			printf("                                                            |\n");
			delay(17);
			printf("                                                            V\n");
			delay(17);
			printf("                                                           NULL");
	}
	printf("\n");
	delay(17);
	printf("There ");
	delay(17);
	printf("are ");
	delay(17);
	printf("total ");
	delay(17);
	printf("%d ", count);
	delay(170);
	printf("nodes ");
	delay(17);
	printf("present");
	delay(1000);
	printf("\n\n");
}

void delet(void)
{
	int position;
	if (count == 0)
	{
		printf("No Nodes are pressent to be deleted\n\n\n");
	}
	else
	{
		printf("Enter the node position which you want to delete\n");
		scanf("%d", &position);
		while ((position<1) || (position>count))
		{
			printf("Please enter a valid position starting from 1 to %d\n", count);
			scanf("%d", &position);
		}

		struct node *temp;
		if (position == 1)
		{
			temp = head;
			head = head->next;
			free(temp);
			count--;
		}
		else if ((position>1) && (position<count))
		{
			int i;
			struct node *temp1;
			temp = head;
			for (i = 0; i<position - 2; i++)
			{
				temp = temp->next;
			}
			temp1 = temp->next;
			temp->next = temp->next->next;
			free(temp1);
			count--;
		}
		else if (position == count)
		{
			temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
			count--;
		}
	}
	clrscr();
	display(count);
	delay(1000);
}

void clrscr()
{
	system("@cls||clear");
}

void delay(unsigned int m)
{
	clock_t goal = m + clock();
	while (goal>clock());
}







