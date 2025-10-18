#include"stdio.h"
#include"omp.h"
float t_srl = 0, t_prl = 0;
void fn_rer_pratice_srl()
{
	//Write serial program to print hello world and find  their thread Id as well as execution time compute speeed up as well as efficency
	double start, end;
	start = omp_get_wtime();
	printf("Hello world serial \n");
	end = omp_get_wtime();
	t_srl = end - start;
	printf("Execution serial program: %f ms\n", t_srl);
	printf("Hello world serial printed by thread ID:%d\n", omp_get_thread_num());
}

void fn_rer_pratice_prl()
{
	double start, end;
	start = omp_get_wtime();
#pragma omp parallel
	{
		printf("Hello world parallel \n");
		printf("Hello world parallel printed by thread ID: %d\n", omp_get_thread_num());
	}
	end = omp_get_wtime();
	t_prl = end - start;
	printf("Execution parallel program: %f ms\n", t_prl);
}
void calculate()
{
	float speedup = t_srl / t_prl;
	printf("Speedup :%f \n", speedup);
	int core = omp_get_num_threads();
	float efficency = speedup / core;
	efficency = efficency * 100;
	printf("Efficency: %f\n", efficency);
}