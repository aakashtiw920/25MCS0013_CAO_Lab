#include"stdio.h"
#include"omp.h"
void fn_ret_et_helloworld_srl() {   //function for the runtime routine serial program
	double start, end;
	start = omp_get_wtime();
	printf("Hello world serial \n");
	end = omp_get_wtime();
	printf("Execution serial program: %f ms\n", end - start);
}
void fn_ret_et_helloworld_prl() {   //function for the runtime routine parallel program
	double start, end;
	start = omp_get_wtime();
	#pragma omp parallel
	{
		printf("Hello world parallel \n");
	}
	end = omp_get_wtime();
	printf("Execution parallel program: %f ms\n", end - start);

}