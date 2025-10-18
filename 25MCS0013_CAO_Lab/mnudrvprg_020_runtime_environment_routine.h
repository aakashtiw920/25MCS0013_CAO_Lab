#include<stdio.h>
#include<cstdlib>
#include"ret_et_helloworld.h"
#include"ret_tid_helloworld.h"

int fn_mnudrvprg_020_parallel_construct()
{

	int choice;
	while (1)
	{
		printf("##############################################\n");
		printf("List of choices\n");

		printf("0: Exit \t 1.Hello World runtime routine Exection time serial program output\t 2.Hello World runtime routine Exection time  parallel program output 3.Hello World runtime routine serial program threadId output\t 4.Hello World runtime routine parallel program threadId output\n\n");

		printf("##############################################\n");

		printf("Enter you choice \t: ");
		printf("\n\n");
		/*scanf("%d", &choice);*/
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0:
		{
			printf("You opted to exit program\n");
			exit(0);
		}
		case 1: {
			printf("This is output of runtime routine hello world serial program\n");
			fn_ret_et_helloworld_srl();
			break;
		}
		case 2: {
			printf("This is output of runtime routine hello world parallel program\n");
			fn_ret_et_helloworld_prl();
			break;
		}
		case 3: {
			printf("This is output of hello world serial threadid program\n");
			fn_ret_tid_helloworld_srl();
			break;
		}
		case 4: {
			printf("This is output of hello world parallel threadid program\n");
			fn_ret_tid_helloworld_prl();
			break;
		}
		default:
		{
			printf("Opted wrong choice\n");
			break;
		}

		}
	}
	return 0;
}
