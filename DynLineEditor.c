#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

#define size 21
#define Xpos 10
#define Ypos 5

void main()
{
	char ch, *str, *pfirst, *pcurrent, *plast;
   int flag, i, firstcol, currentcol, lastcol, linesize;

   printf("Enter Line Size: ");
   scanf("%d", &linesize);

   clrscr();
   gotoxy(Xpos, Ypos);
   textattr(0xf0);
	for(i = 0; i < linesize; i++)
   {
   	cprintf(" ");
   }

   str = (char*)malloc((linesize+1) * sizeof(char));

   firstcol = currentcol = lastcol = 0;
   pfirst = pcurrent = plast = str;
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
               pcurrent = pfirst;
            break;

            case 79:	//end
            	currentcol = lastcol;
               pcurrent = plast;
            break;

            case 82:	//insert
            break;
         }

         break;

         case 13:	//Enter
         	if(lastcol == linesize-1)
         		plast++;
         	*plast = '\0';
         	flag = 0;

            textattr(0x0f);
            clrscr();
            puts(str);
            getch();
         break;

         case 27:	//esc
         	*pfirst = '\0';
            flag = 0;
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

               if(currentcol < linesize-1)
               {
	            	if(currentcol == lastcol)
                  {
   	            	lastcol++;
                     plast++;
                  }
      	         currentcol++;
                  pcurrent++;
               }

            }

         break;
      }

		gotoxy(Xpos+currentcol, Ypos);
   }
   while(flag);

   free(str);
}