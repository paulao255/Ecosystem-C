/* Include guard: */
#ifndef GG_ECOSYSTEM_C
#define GG_ECOSYSTEM_C

/* Importations: */
#include <cutils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* Main code: */
int main()
{
	/* GG Ecosystem version variables:  */
	#define GG_ECOSYSTEM_FULL_VERSION  200.0L /* GG Ecosystem full version variable (2.0.0). */
	#define GG_ECOSYSTEM_MAJOR_VERSION   2.0L /* GG Ecosystem major version variable (2).    */
	#define GG_ECOSYSTEM_MINOR_VERSION   0.0L /* GG Ecosystem minor version variable (0).    */
	#define GG_ECOSYSTEM_PATCH_VERSION   0.0L /* GG Ecosystem patch version variable (0).    */

	/* Start random seed: */
	srand((unsigned) time(NULL));

	/* Local variables: */
	char loop1 = 1;                           /* First loop variable.                        */
	signed int x_number = 0;                  /* X variable.                                 */
	unsigned int x_chance = 0u;               /* X survive chance.                           */
	signed int y_number = 0;                  /* Y variable.                                 */
	unsigned int y_chance = 0u;               /* Y survive chance.                           */
	char option1[8192] = "";                  /* First option variable.                      */
	char sx_number[8192] = "";                /* String X variable.                          */
	char sy_number[8192] = "";                /* String Y variable.                          */

	/* Compatibility commands: */
	enable_vt_and_utf8();
	CLEAR_TERMINAL();

	/* Commands before the first loop: */
	fputs("Type the X number and the Y number both with a space between them: ", stdout);
	scanf("%8191s%8191s", sx_number, sy_number);
	x_number = atoi(sx_number);
	y_number = atoi(sy_number);

	/* First loop: */
	while(loop1 == 1)
	{
		CLEAR_TERMINAL();
		puts("==================================");
		puts("========== GG ECOSYSTEM ==========");
		puts("==================================");
		printf("    %s[ 0 ] Options...%s\n", RED_COLOR, BASE_TERMINAL);
		printf("    %s[ 1 ] Start ecosystem%s\n", GREEN_COLOR, BASE_TERMINAL);
		fputs("\t  Your answer: ", stdout);
		scanf("%8191s", option1);
		CLEAR_TERMINAL();

		if(strcmp(option1, "0") == 0)
		{
			++loop1;

			while(loop1 == 2)
			{
				puts("=================================");
				puts("============ OPTIONS ============");
				puts("=================================");
				printf("    %s[ 0 ] Go back%s\n", BOLD, BASE_TERMINAL);
				printf("    %s[ 1 ] Exit...%s\n", RED_COLOR, BASE_TERMINAL);
				printf("    %s[ 2 ] Read \"READ-ME\"%s\n", YELLOW_COLOR, BASE_TERMINAL);
				fputs("\t  Your answer: ", stdout);
				scanf("%8191s", option1);

				if(strcmp(option1, "0") == 0)
				{
					--loop1;
				}

				else if(strcmp(option1, "1") == 0)
				{
					CLEAR_TERMINAL();
					loop1 = 0;
				}

				else if(strcmp(option1, "2") == 0)
				{
					CLEAR_TERMINAL();
					rrmf();
					CLEAR_TERMINAL();
				}
			}
		}

		else if(strcmp(option1, "1") == 0)
		{
			puts("When you enter press \"Ctrl + C\" to stop and exit program, or wait until one of them extinct.");
			petc();
			++loop1;

			while(loop1 == 2)
			{
				x_chance = rand() % 3;
				y_chance = rand() % 3;

				if(x_chance == 0u)
				{
					--x_number;
				}

				else if(x_chance == 2u)
				{
					++x_number;
				}

				if(y_chance == 0u)
				{
					--y_number;
				}

				else if(y_chance == 2u)
				{
					++y_number;
				}

				printf("X number: %d\n", x_number);
				printf("Y number: %d\n", y_number);
				mssleep(25u);
				CLEAR_TERMINAL();

				if(x_number == 0)
				{
					loop1 = 0;
				}

				else if(y_number == 0)
				{
					loop1 = 0;
				}
			}
		}
	}

	return 0;
}

/* End code: */
#endif
