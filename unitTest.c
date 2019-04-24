// filter ²âÊÔº¯Êý
#include "unitTest.h"
#include "gpssim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void testFilter()
{
	double x[5] = { 0.2, 0.3, 1.2, 12, 13 };
	double y[5] = { 0 };
	double b[5] = { 0.2, 0.3, 1.2, 12, 13 };
	filter(b, 5, x, y);
	for (int i = 0; i < 5; i++)
	{
		printf("%f ", y[i]);
	}
	printf("\n");
}

void testFarrowCoe()
{
	for (int i = 0; i < FARROW_N; i++)
	{
		for (int j = 0; j < FARROW_P; j++)
		{
			printf("%.10f ", farrowCoefficients[i][j]);
		}
		printf("\n ");
	}
}


void testFarrowFilter()
{
	double x[1000] = { 0 };
	double y[50] = { 0 };

	for (int i = 0; i < 1000; i++)
	{
		x[i] = i;// (i % 2) * 2 - 1;
	}

	for (int i = 5; i < 50; i++)
	{
		memset(y, 0, 50 * sizeof(double));
		if (i == 49)
		{
			farrowFilter(1, 50, &x[i * 20 - 30], y);
		}
		

		for (int j = 0; j < 20; j++)
		{
			printf("%f ", x[i * 20 + j - 30]);
		}
		printf("\n ");
		if (i == 1)
		{
			for (int j = 0; j < 15; j++)
			{
				printf("%f ", y[j + 10 + 5]);
			}
		}
		else
		{
			for (int j = 0; j < 20; j++)
			{
				/*if (j == 5)
				{
					printf("\n ");
				}*/
					
				printf("%f ", y[j+10]);
			}
			printf("\n ");
		}
		
		
	}
	
	printf("\n ");

}
#if UNITTEST == 1
void main(int argc, char *argv[])
{
	//testFarrowFilter();
	double a;
	a = cos(PI/2*24);
	printf("%f ", a);
	a = cos(PI);
	printf("%f ", a);


}
#endif