/*
This progarm calculates PI aproxemated to four decimal spaces
By: HUSSAM A.DEEN		13 apr 2010
*/

#include<stdio.h>

int main()
{
	int x = 1, c = 1; // (x) is the dominator, (c) is the count
	float pi = 0;  // (pi) is PI

	while((int) pi * 10000 != 31415){

		if (c % 2 == 0){
			pi -= 4/x;
		}//end if
		else{
			pi += 4/x;
		}//end else

		x += 2;
		c++;
	}//end while
	printf("%1.4f", pi);

	return 0;
}