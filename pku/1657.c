#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define SIZE 8
#define MAX(a,b) ((a) > (b)?(a):(b))

int change(char tmp)
{
	if (isdigit(tmp))
		return tmp - '0' - 1;
	else
		return SIZE - (tmp - 'a') - 1;
}

int main()
{
	int N;
	char a,b,c,d;
	scanf("%d\n",&N);

	for (int i = 0;i < N;i++)
	{
		int pos[4];
		//scanf("%c%c %c%c\n",&a,&b,&c,&d);
		a = getchar();b = getchar();getchar();
		c = getchar();d = getchar();getchar();
		pos[0] = change(b);pos[1] = change(a);
		pos[2] = change(d);pos[3] = change(c);
		printf("%d ",MAX(abs(pos[2] - pos[0]),abs(pos[3] - pos[1])));

		if (pos[0] == pos[2] && pos[1] == pos[3])
			printf("%d ",0);
		else if (pos[0] == pos[2]||pos[1] == pos[3] ||abs(pos[0] - pos[2])==abs(pos[1] - pos[3]))
			printf("%d ",1);
		else
			printf("%d ",2);

		if (pos[0] == pos[2] && pos[1] == pos[3])
			printf("%d ",0);
		else if (pos[0] == pos[2]||pos[1] == pos[3]) 
			printf("%d ",1);
		else
			printf("%d ",2);

		if (pos[0] == pos[2] && pos[1] == pos[3])
			printf("%d\n",0);
		else if (abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))
			printf("%d\n",1);
		else if (((pos[0] + pos[1]) % 2 == 0&&(pos[2] + pos[3]) % 2 == 0)||
			  ((pos[0] + pos[1]) % 2 != 0&&(pos[2] + pos[3]) % 2 != 0))
			printf("%d\n",2);
		else
			printf("Inf\n");
	}
}
