#include<stdio.h>

int count(int a)
{
	int m;

	for (m = 0; a != 1; m++){
		if (a % 2 != 0)
			a = (3*a) + 1;
		else
			a /= 2;
	}
	return m;
}

int main()
{
	int i, j;

	scanf("%d%d", &i, &j);
	printf("%d %d ", i, j);

	if (count(i) > count (j))
		printf("%d", count(i));
	else
		printf("%d", count(j));

	return 0;
}