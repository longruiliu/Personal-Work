#include<stdio.h>
#define LENG 500

int main()
{
	int n,a;
	int count = 0,sum = 0;
	int tmp1,min;
	unsigned long long M = 1;

	while (scanf("%d %d",&n,&a) == 2)
	{
		int div[LENG] = {0},div_num[LENG] = {0},res[LENG] = {0};
		count = 0;
		for (int i = 2;i < a;i++)
		{
			tmp1 = a;
			if ((tmp1 % i) == 0)
			{
				div[count] = i;
				while ((tmp1 % i) == 0)
				{
					div_num[count]++;
					tmp1 /= i;
				}
				count++;
			}
		}
#ifdef D
		for (int i = 0;i < count;i++)
			printf("%d %d\n",div[i],div_num[i]);
#endif
		for (int i = 0;i < count;i++)
		{
			for (int j = 2;j <= n;j++)
			{
				tmp1 = j;
				if ((tmp1 % div[i]) == 0)
				{
					while ((tmp1 % div[i]) == 0)
					{
						sum++;
						tmp1 /= div[i];
					}
				}
			}
			res[i] = sum / div_num[i];
			sum = 0;
		}
#ifdef D
		for(int i = 0;i < count;i++)
			printf("%d ",res[i]);
		printf("\n");
#endif
		min = res[0];
		for (int i = 1;i < count;i++)
		{
			if (res[i] < min)
				min = res[i];
		}
		printf("%d\n",min);
	}
	
	return 0;
}
