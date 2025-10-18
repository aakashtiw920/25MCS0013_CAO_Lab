#include<stdio.h>
#include<cstdlib>
#include"helloworld_srl.h"
#include"helloworld_prl.h"
int fn_mnudrvprg_010_parallel_construct()
{

	int choice;
	while (1)
	{
		printf("##############################################\n");
		printf("List of choices\n");

		printf("0: Exit \t 1.Hello World serial program output\t 2.Hello World parallel program output\n\n");

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
			printf("This is output of hello world serial program\n");
			fn_helloworld_srl();
			break;
		}
		case 2: {
			printf("This is output of hello world parallel program\n");
			fn_helloworld_prl();
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
