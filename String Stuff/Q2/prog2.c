#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN 101

int str_match(char pattern[], char text[]);

int str_match(char ptn[], char txt[])
{
	int value = 0,maxvalue = LEN, place,ptn_len = strlen(ptn), txt_len = strlen(txt);

	for(int i = 0; i <= txt_len; i++)
	{
		if((i+ptn_len) <= txt_len && txt[i] != '\0')
		{
			for(int j = 0; j < ptn_len; j++)
			{
				if(txt[i+j] != ptn[j])
					value++;		
			}
	

			if(value < maxvalue)
			{
				maxvalue = value;
				place = i;
			}

			value = 0;
		}
	}

	return place;
}


int main()
{
	char str[LEN], inpt[LEN];
	while(getchar() != EOF)
	{
		printf("\nInput Pattern : ");
		gets(str);
		printf("Input Text : ");
		gets(inpt);
		printf("Text is: %s  \n",inpt);
		printf("Pattern is: %s  \n",str);
		printf("\nplace in string: %d\n",str_match(str,inpt));
	}
	return 0;
}
