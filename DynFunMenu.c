#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

#define row 4
#define col 15
//#define EmpNum 2

struct emp
{
	int code;
	char name [10];
	float salary;
	float deduct;
	float overTime;
   int enabled;
};

struct emp addEmp()
{
	struct emp e;

   e.enabled = 1;

   gotoxy (5,5);
	printf("Code: ");

	gotoxy (5,7);
	printf("Name: ");

	gotoxy (5,9);
	printf("Salary: ");

	gotoxy (25,5);
	printf("Deduct: ");

	gotoxy (25,7);
	printf("OverTime: ");

	gotoxy (13,5);
	scanf("%d",&e.code);
	gotoxy (13,7);
	scanf("%s",e.name);
	gotoxy (13,9);
	scanf("%f",&e.salary);
	gotoxy (35,5);
	scanf("%f",&e.deduct);
	gotoxy (35,7);
	scanf("%f",&e.overTime);

   return e;
}	//end addEmp

void displayEmp(struct emp e)
{
	if(e.enabled == 1)
   {
   	gotoxy (5,5);
		printf("Code: ");
      gotoxy (13,5);
      printf("%d", e.code);

		gotoxy (5,7);
		printf("Name: ");
      gotoxy (13,7);
      printf("%s", e.name);

		gotoxy (5,9);
		printf("Salary: ");
      gotoxy (13,9);
      printf("%.2f", e.salary);

		gotoxy (25,5);
		printf("Deduct: ");
      gotoxy (35,5);
      printf("%.2f", e.deduct);

		gotoxy (25,7);
		printf("OverTime: ");
      gotoxy (35,7);
      printf("%.2f", e.overTime);
   }
   else
   {
   	printf("This index is empty");
   }
}	//End displayEmp

void displayEmpIndex(struct emp x[], int size)
{
	int i;

	clrscr();

	   			printf("Enter the index: ");
	   			scanf("%d", &i);

               clrscr();

               if(i >= 0 && i < size)
					{
   					displayEmp(x[i]);
               }
               else
               {
   					printf("Incorrect Index.\n Please enter index between 0 and %d.", size-1);
         			printf("\n\n\tPress any key to continue...");
                 	getch();
   				}
      			getch();
} //end displayEmpArr

void displayAll(struct emp x[], int size)
{
	int i;
	for(i = 0; i < size; i++)
   {
   	clrscr();
   	if(x[i].enabled == 1)
      {
      	displayEmp(x[i]);
      }
      getch();
   }
}	//end displayAll

void main()
{
	int i, current = 0, flag = 1, EmpNum;
	char ch, menu[row][col] = {"New", "Display", "Display All", "Exit"};
   //struct emp x[EmpNum];
   struct emp *x;

   
   clrscr();
   printf("Enter Number of employees: ");
   scanf("%d", &EmpNum);

   x = (struct emp*)malloc(EmpNum * sizeof(struct emp));

	do
	{
		clrscr();

		for(i = 0; i < row; i++)
		{
			gotoxy(15, (i*3)+5);

			if(i == current)
				textattr(0xf0);
			//else
				//textattr(0x07);

			cprintf("%s", menu[i]);
         textattr(0x07);
		}

		gotoxy(1,1);
			printf("%d", current);

		ch = getch();

		switch(ch)
		{
			case 0:		//extended characters
			ch = getch();

			switch(ch)
			{
				case 72:	//up
				if(--current < 0)
					current = 0;
				break;

				case 80:	//down
				if(++current >= row)
					current = row-1;
				break;

				case 71:	//home
				current = 0;
				break;

				case 79:	//end
				current = row-1;
				break;
			}
			break;

			case 13:	//enter

			switch(current)
			{
				case 0:	  //New

            	clrscr();

	   			printf("Enter the index: ");
	   			scanf("%d", &i);

               if(i >= 0 && i < EmpNum)
					{
      				x[i] = addEmp();
					}
   				else
   				{
   					printf("Incorrect Index.\n Please enter index between 0 and %d.", EmpNum-1);
         			printf("\n\n\tPress any key to continue...");
                  getch();
   				}

				break;

				case 1:   //Display

            	displayEmpIndex(x, EmpNum);

				break;

            case 2:	//Display All
            	displayAll(x, EmpNum);
            break;

				case 3:	  //Exit
				flag = 0;

            clrscr();
   			gotoxy(20, 15);
   			printf("Good Bye!");
   			getch();

				break;
			}

			break;

			case 9:		//tab
			if(++current >= row)
				current = 0;
			break;

			case 27:	//esc
				flag = 0;
			break;
		}


	}
	while(flag);

   free(x);
}