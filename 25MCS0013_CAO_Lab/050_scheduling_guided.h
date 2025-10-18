#include"stdio.h"
#include<omp.h>
void fn_default_guided_scheduling()
{
	int i;
	int n = 16;
	omp_set_num_threads(4);
	printf("Guided scheduling example without chunk size\n\n");
#pragma omp parallel for schedule(guided)
	for (i = 0; i < n; i++)
	{
		//int tid = omp_get_thread_num();
		printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
	}
}
void fn_guided_01()
{
	int i;
	int n = 16;
	omp_set_num_threads(4);
	printf("\nGuided scheduling example with chunk size=1\n\n");
#pragma omp parallel for schedule(guided,1)
	for (i = 0; i < n; i++)
	{
		//int tid = omp_get_thread_num();
		printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
	}
}
void fn_guided_uneven()
{
	int i;
	int n = 18;
	// Set number of threads to 4
	omp_set_num_threads(4);
	printf("Guided Scheduling Example:\n");
#pragma omp parallel for schedule(guided)
	for (i = 0; i < n; i++) {
		int tid = omp_get_thread_num();
		printf("Iteration %d handled by thread %d\n", i, tid);
	}
}

void fn_guided_02()
{
	int i;
	int n = 16;
	omp_set_num_threads(4);
	printf("\nGuided scheduling example with chunk size=2\n\n");
#pragma omp parallel for schedule(guided,2)
	for (i = 0; i < n; i++)
	{
		//int tid = omp_get_thread_num();
		printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
	}
}

