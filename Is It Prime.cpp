/*
This program reads an intiger from the user and define if it is a prime or not
By: HUSSAM A.DEEN		15 apr 2010
*/

#include<stdio.h>

int main()
{
	int x, y = 2; //(x) is the number from user, (y) is the divisor
	scanf("%d", &x);

	while (y < x && (x%y) != 0){
		x % y;
		y++;
	} //end while

	if ((x%y) != 0){
			printf("number is prime\n");
		} //end if
		else{
			printf("number is not prime\n");
		} //end else

	return 0;
} //en main