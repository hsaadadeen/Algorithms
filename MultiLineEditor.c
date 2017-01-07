#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

#define size 21
#define Xpos 10
#define Ypos 5

void main()
{
	//char ch, *str, *pfirst, *pcurrent, *plast;
   char **str, **pfirst, *pcurrent, **plast, ch;
   int flag, i, j, firstcol, currentcol, lastcol, *linesize;
   int firstrow, currentrow, lastrow, linenum;

   clrscr();
   printf("Enter Number of Lines: ");
   scanf("%d", &linenum);

   str = (char**)malloc(linenum * sizeof(char*));
   pfirst = (char**)malloc(linenum * sizeof(char*));
   //pcurrent = (char*)malloc(linenum * sizeof(char*));
   plast = (char**)malloc(linenum * sizeof(char*));
   linesize = (int*)malloc(linenum * sizeof(int));

   clrscr();
   for(i = 0; i < linenum; i++)
   {
   	printf("Enter Line %d Size: ", i);
   	scanf("%d", &linesize[i]);
   }

   for(i = 0; i < linenum; i++)
   {
   	str[i] = (char*)malloc((linesize[i]+1) * sizeof(char));
   }

   clrscr();
   gotoxy(Xpos, Ypos);
   textattr(0xf0);
   for(j = 0; j < linenum; j++)
   {
   	gotoxy(Xpos, Ypos + j*2);
		for(i = 0; i < linesize[j]; i++)
   	{
   		cprintf(" ");
   	}
   }


   firstcol = currentcol = lastcol = 0;
   firstrow = currentrow = 0; lastrow = linenum;
   //pfirst = pcurrent = plast = str[0];
   pcurrent = str[0];
   for(i = 0; i < linenum; i++)
   {
   	pfirst[i] = plast[i] = str[i];
   }
   gotoxy(Xpos+currentcol, Ypos);

   flag = 1;
   do
   {
   	ch = getch();

      switch(ch)
      {
      	case 0:	//extended characters

         ch = getch();
         switch(ch)
         {
         	case 77:	//right
            	if(currentcol < lastcol)
               {
      	         currentcol++;
                  pcurrent++;
               }
            break;

            case 75:	//left
            	if(currentcol > firstcol)
               {
      	      	currentcol--;
                  pcurrent--;
               }
            break;

            case 71:	//home
            	currentcol = firstcol;
               pcurrent = pfirst[currentrow];
            break;

            case 79:	//end
            	currentcol = lastcol;
               pcurrent = plast[currentrow];
            break;

            case 82:	//insert
            break;
         }

         break;

         case 13:	//Enter
         	for(i = 0; i < linenum; i++)
            {
            
            	if(lastcol == linesize-1)
         			plast[i]++;
         		*plast[i] = '\0';
            }
         	flag = 0;

            textattr(0x0f);
            clrscr();
            for(i = 0; i < linenum; i++)
            {
            	puts(str[i]);
               printf("\n");
            }
            getch();
         break;

         case 27:	//esc
         	for(i = 0; i < linenum; i++)
            {
         		*pfirst[i] = '\0';
            }
            flag = 0;
         break;

         case 9:	//tab
         	currentrow++;
         	if(currentrow == linenum)
            {
            	currentrow = firstrow;
            }
            currentcol = firstcol;
            lastcol = 0;
            pcurrent = pfirst[currentrow];
         break;

         case 8:	//backspace
         break;

         case 46:	//delete
         break;

         default:	//character

         	//textattr(0xf0);
            if(isprint(ch))
            {
            	*pcurrent = ch;
            	putch(ch);

               if(currentcol < linesize[currentrow]-1)
               {
	            	if(currentcol == lastcol)
                  {
   	            	lastcol++;
                  }
                  if(pcurrent == plast[currentrow])
                  {
                     plast[currentrow]++;
                  }
      	         currentcol++;
                  pcurrent++;
               }

            }

         break;
      }

		gotoxy(Xpos+currentcol, Ypos+(currentrow*2));
   }
   while(flag);

   free(str);
}