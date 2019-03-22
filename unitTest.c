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
	double x[20] = { 0.2, 0.3, 1.2, 12, 13, 123, 1.21, 234, 21, 2, 1, 34, 123, 44, 12, 41, 55, 23, 135, 125};
	double y[20] = { 0 };

	farrowFilter(-1, 20, x, y);
	for (int i = 0; i < 20; i++)
	{
		printf("%f ", y[i]);
	}

}
#if UNITTEST == 1
void main(int argc, char *argv[])
{
	testFarrowFilter();

}
#endif