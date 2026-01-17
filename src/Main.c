/* Include guard: */
#ifndef ECOSYSTEM_C
#define ECOSYSTEM_C

/* Importations: */
#include "C-Utils/cutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* Ecosystem version variables:  */
#define ECOSYSTEM_C_FULL_VERSION  20260116 /* Ecosystem full version variable (2026/01/16). */
#define ECOSYSTEM_C_MAJOR_VERSION 2026     /* Ecosystem major version variable (2026).      */
#define ECOSYSTEM_C_MINOR_VERSION 01       /* Ecosystem minor version variable (01).        */
#define ECOSYSTEM_C_PATCH_VERSION 16       /* Ecosystem patch version variable (16).        */

/* Main code: */
int main(void)
{
	/* Local variables: */
	char loop = 1;                     /* Loop variable.                                */
	int number[4] = {10, 10, 10, 10};  /* Number variable.                              */
	int number_chance[2] = {0, 0};     /* Number survival chance.                       */
	char option[8192] = "";            /* Option variable.                              */
	char s_number[2][8192] = {"", ""}; /* String number variable.                       */

	/* Start random seed: */
	srand((unsigned) time(NULL));

	/* Compatibility commands: */
	enable_vt_and_utf8();

	/* First loop: */
	while(loop == 1)
	{
		clear_terminal();
		puts("=================================");
		puts("========== ECOSYSTEM C ==========");
		puts("=================================");
		printf("    %s[ 0 ] Options...%s\n", RED_COLOR, BASE_TERMINAL);
		printf("    %s[ 1 ] Start ecosystem%s\n", GREEN_COLOR, BASE_TERMINAL);
		fputs("\t  Your answer: ", stdout);
		scanf("%8191s", option);
		clear_terminal();

		if(strcmp(option, "0") == 0)
		{
			++loop;

			while(loop == 2)
			{
				puts("=========================================");
				puts("================ OPTIONS ================");
				puts("=========================================");
				printf("    %s[ 0 ] Go back%s\n", BOLD, BASE_TERMINAL);
				printf("    %s[ 1 ] Exit...%s\n", RED_COLOR, BASE_TERMINAL);
				printf("    %s[ 2 ] Read \"READ-ME\"%s\n", CYAN_COLOR, BASE_TERMINAL);
				printf("    %s[ 3 ] Read \"LICENSE\"%s\n", YELLOW_COLOR, BASE_TERMINAL);
				printf("    %s[ 4 ] Change the numbers%s\n", GREEN_COLOR, BASE_TERMINAL);
				fputs("\t  Your answer: ", stdout);
				scanf("%8191s", option);

				if(strcmp(option, "0") == 0)
				{
					--loop;
				}

				else if(strcmp(option, "1") == 0)
				{
					clear_terminal();
					loop = 0;
				}

				else if(strcmp(option, "2") == 0)
				{
					clear_terminal();
					rrmf();
					clear_terminal();
				}

				else if(strcmp(option, "3") == 0)
				{
					clear_terminal();
					rlf();
					clear_terminal();
				}

				else if(strcmp(option, "4") == 0)
				{
					clear_terminal();
					fputs("Type the X number and the Y number both with a space between them: ", stdout);
					scanf("%8191s%8191s", s_number[0], s_number[1]);
					number[0] = atoi(s_number[0]);
					number[1] = atoi(s_number[1]);
					number[2] = number[0];
					number[3] = number[1];
					clear_terminal();
				}

				else
				{
					clear_terminal();
				}
			}
		}

		else if(strcmp(option, "1") == 0)
		{
			puts("When you enter press \"Ctrl + C\" to stop and exit program, or wait until one of them extinct.");
			petc();

			++loop;

			while(loop == 2)
			{
				number_chance[0] = rand() % 3;
				number_chance[1] = rand() % 3;

				if(number_chance[0] == 0)
				{
					--number[0];
				}

				else if(number_chance[0] == 2)
				{
					++number[0];
				}

				if(number_chance[1] == 0)
				{
					--number[1];
				}

				else if(number_chance[1] == 2)
				{
					++number[1];
				}

				printf("X number: %d\n", number[0]);
				printf("Y number: %d\n", number[1]);

				if(number[0] == 0)
				{
					petc();
					--loop;
					number[0] = number[2];
				}

				else if(number[1] == 0)
				{
					petc();
					--loop;
					number[1] = number[3];
				}

				clear_terminal();
			}
		}
	}

	return 0;
}

/* End code: */
#endif
