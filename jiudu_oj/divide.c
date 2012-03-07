#include<stdio.h>
#define LENG 10

int main()
{
	int n,a;
	int count = 0,sum = 0;
	int tmp1,min;

	while (scanf("%d %d",&n,&a) == 2)
	{
		int div[LENG] = {0},div_num[LENG] = {0};
		count = 0;
	        tmp1 = a;
		for (int i = 2;i <= tmp1;i++)
		{
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
			div_num[i] = sum / div_num[i];
			sum = 0;
		}
		min = div_num[0];
		for (int i = 1;i < count;i++)
		{
			if (div_num[i] < min)
				min = div_num[i];
		}
		printf("%d\n",min);
	}
	
	return 0;
}
