
#include<stdio.h>
#include<omp.h>
void fn_default_dynamic_scheduling()
{
	int i;
	int n = 16;
	omp_set_num_threads(4);
	printf("Dynamic scheduling example\n\n");
#pragma omp parallel for schedule(dynamic)
	for (i = 0; i < n; i++)
	{
		printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
	}

}
void fn_dynamic_01()
{
	int i;
	int n = 16;
	omp_set_num_threads(4);
	printf("Dynamic scheduling example with chunk size=1\n\n");
#pragma omp parallel for schedule(dynamic,1)
	for (i = 0; i < n; i++)
	{
		//int tid = omp_get_thread_num();
		printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
	}
}
void fn_dynamic_02()
{
	int i;
	int n = 16;
	omp_set_num_threads(4);
	printf("Dynamic scheduling example with chunk size=2\n\n");
#pragma omp parallel for schedule(dynamic,2)
	for (i = 0; i < n; i++)
	{
		//int tid = omp_get_thread_num();
		printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
	}
}