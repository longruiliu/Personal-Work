#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 100

int c_to_n(char tmp)
{
	if (tmp >= '0'&&tmp <= '9')
		return tmp - '0';
	else if (tmp >= 'A'&&tmp <= 'Z')
		return tmp - 'A' + 10;
	else if (tmp >= 'a'&&tmp <= 'z')
		return tmp - 'a' + 36;
	else
		return -1;
}

char n_to_c(int tmp)
{
	if (tmp >= 0&&tmp <= 9)
		return tmp + '0';
	else if (tmp >= 10&&tmp <= 35)
		return tmp - 10 + 'A';
	else if (tmp >= 36&&tmp <= 61)
		return tmp - 36 + 'a';
	else
		return '#';
}

void res(unsigned long long tmp,int base)
{
	char data[SIZE];
	int i = 0;
	while (1)
	{
		data[i] = n_to_c(tmp % base);
		tmp /= base;
		i++;
		if (tmp == 0)
		       break;	
	}
	for (int j = i;j >= 0;j--)
		printf("%c",data[j]);
	printf("\n");
}

int main()
{
	int N;
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		int one,two,length;
		unsigned long long sum = 0;
		char str[SIZE];
		scanf("%d %d",&one,&two);
		scanf("%s",str);
		length = strlen(str);
		for (int j = 0,k = length;j < length;j++,k--)
		{
			sum += (c_to_n(str[j] * (long long)pow(one * 1.0,k - 1)));
#ifdef D
		printf("%d %lld %d\n",c_to_n(str[j]),sum,k);
#endif
		}
		res(sum,two);
	}

	return 0;
}
