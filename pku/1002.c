#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define N 20
#define LEN 7

typedef struct data
{
	char tele[N];
	int count;
}DATA;

void del_dash(char first[],int length)
{
	char tmp[N];
	int j = 0;
	for (int i = 0;i < length;i++)
		if (first[i] != '-')
		{
			tmp[j] = first[i];
			j++;
		}
	for (int i = 0;i < j;i++)
		first[i] = tmp[i];
}

int match(char tmp)
{
	if (isdigit(tmp))
		return tmp - '0';
	if (tmp >= 'A'&&tmp <= 'C')
		return 2;
	else if (tmp >= 'D'&&tmp <= 'F')
		return 3;
	else if (tmp >= 'G'&&tmp <= 'I')
		return 4;
	else if (tmp >= 'J'&&tmp <= 'L')
		return 5;
	else if (tmp >= 'M'&&tmp <= 'O')
		return 6;
	else if (tmp == 'P'||(tmp >= 'R'&&tmp <= 'S'))
		return 7;
	else if (tmp >= 'T'&&tmp <= 'V')
		return 8;
	else if (tmp >= 'W'&&tmp <= 'Y')
		return 9;
}

int is_form(char tmp[])
{
	for (int i = 0;i < LEN;i++)
		if (!isdigit(tmp[i]))
			return 0;
	return 1;
}

int all_match(char one[],char two[])
{
	for (int i = 0;i < LEN;i++)
	{
		if (match(one[i]) != match(two[i]))
			return 0;
	}
	return 1;
}

int only(DATA *p ,char tmp[],int length)
{
	for (int i = 0;i < length;i++)
		if (all_match(p[i].tele,tmp))
			return 0;
	return 1;
}

void my_copy(char new[],char old[])
{
	for (int i = 0;i < LEN;i++)
		new[i] = old[i];
}

int main()
{
	int size,res = 0;
	scanf("%d",&size);

	DATA *p = (DATA*)malloc(size * sizeof(DATA));
	DATA *q = (DATA*)malloc(size * sizeof(DATA));
	for (int i = 0;i < size;i++)
	{
		scanf("%s",p[i].tele);
		del_dash(p[i].tele,strlen(p[i].tele) + 1);
		p[i].count = 1;
	}
	for (int i = 0;i < size;i++)
	{
		if (!is_form(p[i].tele))
			continue;
		for (int j = 0;j < size;j++)
		{
			if (all_match(p[i].tele,p[j].tele))
			       p[i].count++;	
		}
	}
	for (int  i = 0,j = 0;i < size;i++)
	{
		if (p[i].count > 2&&only(q,p[i].tele,j))
		{
			my_copy(q[j].tele,p[i].tele);
			q[j].count = p[i].count;
			j++;
		}
		res = j;
	}
	for (int i = 0;i < res;i++)
	{
		int min;
		for (int j = 0;j < res;j++)
			if (q[j].tele[7] != '$')
			{
				min = j;
				break;
			}
		for (int j = 0;q[j].tele[7] != '$'&&j < res;j++)
		{
			if (strcmp(q[min].tele,q[j].tele) > 0)
				min = j;
		}
		printf("%c%c%c-%c%c%c%c %d\n",q[min].tele[0],q[min].tele[1],q[min].tele[2],q[min].tele[3],q[min].tele[4],q[min].tele[5],q[min].tele[6],q[min].count - 1);
		q[min].tele[7] = '$';
	}

	free(p);
	free(q);
}
