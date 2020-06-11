#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN 101
#define RUP 6
#define UP 5
#define DOWN 3
#define RDOWN 2

void f_sequence(char str[]);

void f_sequence(char inpt[])
{
	int ptype = UP,ctype = UP,i = 1,eq = 0; /*ptype and ctype are UP to begin so that aaa and zz are up seq*/

	while(inpt[i] != '\0')
	{
		if(isspace(inpt[i]) != 1)
		{

			/* if it is not constant: no reason to carry on checking*/

			if((ctype-ptype) >= 1 || (ctype-ptype) <= -1)
			{
				ctype = 0;
				break;
			}			
			
			/*check what seq the string currently has*/

			if(inpt[i] > inpt[i-1] && eq == 0)
				ctype = RUP;

			else if(inpt[i] < inpt[i-1] && eq == 0)
				ctype = RDOWN;
		
			else if(inpt[i] == inpt[i-1])
			{
				eq = 1;

				if(ctype == RUP)
					ctype = UP;

				else if(ctype == RDOWN)
					ctype = DOWN;
			}

			ptype = ctype;
		}
		
		i++;
	}

	/*check what type the string has and print message accordingly*/

	if(ctype == 0)
		printf("Not constant sequence\n");

	else if(ctype == DOWN)
		printf("Constant down-equals sequence\n");

	else if(ctype == RDOWN)	
		printf("Constant down sequence\n");

	else if(ctype == UP)
		printf("Constant up-equals sequence\n");

	else if(ctype == RUP)	
		printf("Constant up sequence\n");
}

int main()
{
	char str[LEN], inpt[LEN];
	int c = 0, d = 0;

	printf("\nInput String : ");
	gets(str);

	/*remove whitespace so can be analyzed*/

	while(str[c] != '\0')
	{
		if(!isspace(str[c]))
		{
			inpt[d] = str[c];
			d++;
		}
		c++;
	}

	inpt[d] = '\0';

	printf("Your string is : ");
	printf("%s\n",str);		
	printf("%s\n",inpt);
	f_sequence(inpt);

	return 0;
}

	 
		
