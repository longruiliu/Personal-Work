#include"head.h"

int is_operator(char tmp)
{
	if (tmp == '*'||tmp == '/'||
	    tmp == '+'||tmp == '-'||
	    tmp == '('||tmp == ')')
		return 1;
	else
		return 0;
}

void lex()
{
	char str[S_LEN];
	TOKEN token[S_LEN];
	int i = 0,j = 0,k = 0;
	printf("Please input the expression:\n");
	scanf("%s",str);
	int length = strlen(str);
	for (i = 0;i < length;i++)
	{
		if (isdigit(str[i]))
		{
			token[j].flag = 'N';
			token[j].value[k] = str[i];
			k++;
			i++;
			while (isdigit(str[i]))
			{
				token[j].value[k] = str[i];
				i++;
				k++;
			}
			token[j].value[k] = '\0';
			i--;
			j++;
		}
		else if(is_operator(str[i]))
		{
			token[j].flag = 'O';
			token[j].value[k] = str[i];
			token[j].value[k + 1] = '\0';
			j++;
		}
		else
		{
			printf("Input data error!\n");
			exit(0);
		}
	}
	
	for (i = 0;i <= j;i++)
	{
		printf("%s\n",token[i].value);
	}
}

int main()
{
	lex();

	return 0;
}
