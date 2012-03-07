#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENG 1000

void str_cpy(char *p1,char *p2,int begin,int length)
{
	int i,j;
	for (i = begin,j = 0;i < length;i++,j++)
	{
		*(p2 + j) = *(p1 + i);
	}
}

void sort(char **p,int length)
{
	char tmp[LENG];
	for (int i = 0;i < length - 1;i++)
		for (int j = 0;j < length - i - 1;j++)
			if (strcmp(p[j],p[j + 1]) < 0)
			{
				str_cpy(p[j],tmp,0,length);
				str_cpy(p[j + 1],p[j],0,length);
				str_cpy(tmp,p[j + 1],0,length);
			}
}

int main()
{
	char str[LENG];
	int length = 0;
	while (scanf("%s",str) == 1)
	{
		length = strlen(str) + 1;
		char **p =(char **)malloc(sizeof(char *) * (length));
		for (int i = 0;i < length;i++)
		       	p[i] = (char *)malloc(LENG * sizeof(char));

		for (int i = 0;i < length - 1;i++)
		{
			str_cpy(str,p[i],i,length);
		}

		sort(p,length);
		for (int i = length - 2;i >= 0;i--)
			printf("%s\n",p[i]);
		for (int i = 0;i < length;i++)
			free(p[i]);
		free(p);
	}
	return 0;
}
