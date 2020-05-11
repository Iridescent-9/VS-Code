#include <stdio.h>
void main()
{
	int a[3][3] = {1, 3, 6, 7, 9, 11, 14, 15, 17}, sum1 = 0, sum2 = 0, i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (i == j)
			{
				sum1 = sum1 + a[i][j];
			}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 2; j >= 0; j--)
			if ((i + j) == 2)
			{
				sum2 = sum2 + a[i][j];
			}
	}
	printf("sum1=%d,sum2=%d\n", sum1, sum2);
	getchar();
}