#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m,n;
	while (scanf("%d %d",&m,&n)&&m != 0)
	{
		int sum = 0;
		int **p = (int **)malloc(sizeof(int *) * m);
		for (int i = 0;i < m;i++)
			p[i] = (int *)malloc(sizeof(int) * n);
		for (int i = 0;i < m;i++)
			for (int j = 0;j < n;j++)
				scanf("%d",&p[i][j]);
		for (int i = 0;i < m;i++)
		{
			int k = 0;
			for (int j = 0;j < n;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				p[i][j] += tmp;
				if (p[i][j] == 0)
					k++;
			}
			if (k == n)
				sum++;
		}
		for (int i = 0;i < n;i++)
		{
			int j = 0;
			for (;j < m;j++)
			{
				if (p[j][i] != 0)
					break;
			}
			if (j == m)
				sum++;
		}
		printf("%d\n",sum);

		for (int i = 0;i < m;i++)
			free(p[i]);
		free(p);
	}
	return 0;
}
