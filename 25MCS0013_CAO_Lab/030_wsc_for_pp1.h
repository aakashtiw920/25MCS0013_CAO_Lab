#include"stdio.h"
#include"stdlib.h"
#include<omp.h>
void fn_wsc_for_2constructs()
{
	int i;
#pragma omp parallel
	{
		printf("Thread %d Work Sharing starts\n",omp_get_thread_num());
		#pragma omp for
		for (i = 0; i < 20; i++)
		{
			printf("Hello World in iteration :%d by thread ID : %d\n", i, omp_get_thread_num());
		}
	}
}
void fn_wsc_for_1constructs()
{
	int i;
#pragma omp parallel for
		for (i = 0; i < 20; i++)
			printf("Hello World in iteration :%d by thread ID : %d\n", i, omp_get_thread_num());
}