#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int main()
{
	int length = 0;
	char str[MAX];

	while (gets(str) != NULL)
	{
		int tmp1 = 0,tmp2 = 0;
		int i,j,k,res = 0;
		length = strlen(str) + 1;
		str[length - 1] = '\0';
		int *opr = (int *) malloc(length * sizeof(int));
		char *opt = (char *)malloc(length * sizeof(char));
		for (j = 0,k = 0,i = 0;i < length - 1;i++)
		{
			if (isdigit(str[i]))
			{
				tmp1 = tmp1 * 10 + (str[i] - '0');
			}
			else if (str[i] == '+'||str[i] == '-')
			{
				opr[j] = tmp1;
				opt[k] = str[i];
				tmp1 = 0;
				j++;
				k++;
			}
			else
			{
				tmp2 = tmp1;
				tmp1 = 0;
				int mark = i++;
				while ((i < length - 1)&&isdigit(str[i]))
				{
					tmp1 = tmp1 * 10 + (str[i] - '0');
					i++;
				}
				if (str[mark] == '/')
					tmp1 = tmp2 / tmp1;
				else
					tmp1 *= tmp2;
				i--;
			}
		}
		opr[j] = tmp1;
		res = opr[0];
		for (int i = 0;i < k;i++)
		{
			if (opt[i] == '+')
				res += opr[i + 1];
			else
				res -= opr[i + 1];
		}
		printf("%d\n",res);

		free(opr);
		free(opt);
	}
}
