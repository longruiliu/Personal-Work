#include<stdio.h>
#include<stdlib.h>

int offset(int begin,int length,int *data)
{
	int sum,mark,i,j;
	for (sum = 0,i = begin;i < length;i++)
	{
		if (*(data + i) > 0)
			mark = i;
		sum += *(data + i);
		if (sum > 0)
			return mark;
	}
	return -1;
}

int main()
{
	int N,M;
	scanf("%d",&N);
	int *data = (int *)malloc(2 * N * sizeof(int));
	for (int i = 0;i < N;i++)
		scanf("%d",&data[i]);
	scanf("%d",&M);
	for (int i = 0;i < M;i++)
	{
		int max2 = 0;
		int max1 = 0;
		int in1,in2;
		int tmp;
		scanf("%d %d",&in1,&in2);
		tmp = data[in1 - 1];
		data[in1 - 1] = in2;
		for (int i = N,j = 0;i < 2 * N;i++,j++)
			data[i] = data[j];
#ifdef D
		for (int i = 0;i < 2 * N;i++)
					printf("%d ",data[i]);
		printf("\n");
#endif
		for (int j = 0,h = 0;h < N;j++,h++)
		{
			if (data[j] < 0)
				continue;
			for (int k = j;k < N + j;k++)
			{
				if (data[k] >= 0)
					max1 += data[k];
				else 
				{
					int index = offset(k,N + j,data);
#ifdef D
					printf("%d %d\n",k,index);
#endif
					if (index >= 0)
					{
						for (int i = k;i <= index;i++)
							max1 += data[i];
						k = index;
					}
					else 
						break;
				}
			}
#ifdef D
	printf("%d %d\n",max1,max2);
#endif
			if (max1 > max2)
				max2 = max1;
			max1 = 0;
		}
		printf("%d\n",max2);

		data[in1 - 1] = tmp;
	}
}
