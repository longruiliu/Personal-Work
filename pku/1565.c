#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char str[100];

	while (scanf("%s",str)&&str[0] != '0')
	{
		int k = strlen(str);
		if (k > 32)
		{
			printf("2147483647\n");
			continue;
		}
		unsigned int sum = 0;
		int mark = 0;
		unsigned int tmp = 0;
		for (int i = 0;k >= 0;k--,i++)
		{
			tmp = (str[i] - '0') * ((int)pow(2.0,k * 1.0) - 1);
			if (tmp > (2147483647 - sum))
			{
				printf("2147483647\n");
				mark = 1;
				break;
			}
			sum += tmp;
		}
		if (mark == 1)
			continue;
		printf("%d\n",sum);
	}
	return 0;
}
