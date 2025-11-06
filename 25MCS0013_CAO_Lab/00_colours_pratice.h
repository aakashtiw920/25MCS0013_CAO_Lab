
#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#include"00_colours.h"


int fn_main_page() {
	int i;
	while (1) {

		printf("\n");
		fn_red();
		printf("**************************************************************************************************************\n");
		fn_reset();
		fn_blue();
		printf("\t\t\t\t\t\tMCSE503L-COMPUTER ARCHITECTURE AND ORGANISATION LAB PROGRAMS\n");
		printf("\t\t\t\t\t\t\t\t\tBY\n");
		fn_reset();
		fn_yellow();
		printf("\n");
		printf("\t\t\t\t\t\t\tReg.No:25MCS0013  Name:Aakash Tiwari\n");
		printf("\n");
		fn_reset();
		fn_blue();
		printf("\t\t\t\t\t\t\tSubmitted as part of Lab assessment to\n");
		fn_magenta();
		printf("\t\t\t\t\t\t\t\tDr.M.RAJASEKHARA BABU\n");
		fn_reset();
		fn_blue();
		printf("\t\t\t\t\t\t\tSCHOOL OF COMPUTER SCIENCE AND ENGINEERING \n");
		printf("\t\t\t\t\t\t    VELLORE INSTITUTE OF TECHNOLOGY(VIT),VELLORE-632014\n");
		printf("\t\t\t\t\t\t\t\t    JUNE 2025\n");
		fn_reset();
		fn_red();
		printf("*****************************************************************************************************************\n");
		fn_reset();
		fn_green();
		printf("0-Exit  1-Parallel Construct Program \t 2-Run-Time Environment Routines Program \t 3-Work Sharing Construct-For\n");
		printf("\n");
		printf("4-Work Sharing Construct-Section \t 5-Powermat Program \t 6-Prime Number Program \t 7-Pi Program\n");
		fn_reset();
		fn_yellow();
		printf("------------------------------------------------------------------------------------------------------------------\n");
		fn_reset();
		printf("Enter your choice \n");
		scanf_s("%d", &i);
		switch (i) {
		case 0: {
			printf("Thank you for opting exit \n");
			return 0;
		}
		case 1: {
			printf("\nThank you for selecting Parallel Construct Program, now check the below list\n");
			//fn_mnudrvprg_parallel_construct();
			break;
		}
		case 2: {
			printf("\nThank you for selecting Run-Time Environment Routines Program, now check the below list\n");
			//fn_mnudrvprg_runtime_routines();
			break;
		}
		case 3: {
			printf("\nThank you for selecting Work Sharing Construct-For, now check the below list\n");
			//fn_mnudrvprg_worksharing_constructs();
			break;
		}
		case 4: {
			printf("\nThank you for selecting Work Sharing Construct-Section, now check the below list\n");
			//fn_wsc_sections_basic_calculator_srl();
			//fn_wsc_sections_basic_calculator_prl();
			break;
		}
		case 5: {
			printf("\nThank you for selecting Powermat Program, now check the below list\n");
			//fn_mnudrvprg_LA2_22MAI0079();    
			break;
		}
		case 6: {
			printf("\nThank you for selecting Prime Number Program, now check the below list\n");
			//fn_mndrvprog_prime_22MAI0079();
			break;
		}
		case 7: {
			printf("\nThank you for selecting Pi Program, now check the below list\n");
			//fn_mnudrvprg_LA4_22MAI0079();
			break;
		}
		default: {
			printf("Opted wrong choice \n");
			exit(0);
		}
		}
	}
	return 0;
}


