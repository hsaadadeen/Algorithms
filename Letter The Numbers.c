/*
This program reads an integer from user and prints it letters
By: HUSSAM A.DEEN HASSAN	Sec: 4		14 may 2010
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int num;
	int x, y, z, l, m;
	char *units[]={"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
				   "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens[]={"", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *htm[]={"", "hundred", "thousand", "million"};

	scanf("%d", &num);
	
	
		m = num % 100;
		x = num % 10;
		l = num / 10;
		y = l % 10;
		z = l / 10;
	
		printf("%s ", units[z]);
		if (num > 99){
			printf("%s ", htm[1]);
			if( m != 0){
				printf("and ");
			}
		}

	if (m < 19){
		printf("%s\n", units[m]);
	}
	else{
		printf("%s ",tens[y-1]);
		printf("%s\n", units[x]);
	}

	return 0;
}