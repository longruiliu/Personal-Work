#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFINITY 100000    
#define MAX_VERTEX_NUM 100   //The max of the numbers of VEX.
typedef struct ArcCell
{
	int adj;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;

int mul(int a,int b,int n)
{
	static int c = 1;
	c = 1;
	while (b != 0)
	{
		while (b % 2 == 0)
		{
			b = b / 2;
			a = a * a % n;
		}
		b = b - 1;
		c = c * a % n;
	}
	return c;
}

void CreateDN(MGraph &G)
{
	scanf("%d %d",&G.vexnum,&G.arcnum);
	for (int i = 0;i < G.vexnum;i++)
		for (int j = 0;j < G.vexnum;j++)
			G.arcs[i][j].adj = INFINITY;
	for (int k = 0;k < G.arcnum;k++)
	{
		int i,j,tmp;
		scanf("%d %d",&i,&j);
		tmp = mul(2,k,INFINITY);
		G.arcs[i][j].adj = tmp;
		printf("%d %d %d\n",i,j,tmp);
	}
}

void ShortestPath_FLOYD(MGraph &G,AdjMatrix &D)
{
	int v,w,u;
	for (v = 0;v < G.vexnum;v++)//Initiate the distance of the VEXes.
		for (w = 0;w < G.vexnum;w++)
		{
			if (v == w)
				D[v][w].adj = 0;
			else
				D[v][w].adj = G.arcs[v][w].adj;
		}
	for (u = 0;u < G.vexnum;u++)//Find the shortest path of the VEXes.
		for (v = 0;v < G.vexnum;v++)
			for (w = 0;w < G.vexnum;w++)
				if ((D[v][u].adj + D[u][w].adj) < D[v][w].adj)
					D[v][w].adj = D[v][u].adj + D[u][w].adj;
}

int main()
{
	while (1)
	{
		MGraph G;
		AdjMatrix D;
		CreateDN(G);
		ShortestPath_FLOYD(G,D);
		for (int i = 1;i < G.vexnum;i++)
		{
			if (D[0][i].adj == INFINITY)
				printf("-1\n");
			else
				printf("%d\n",D[0][i]);
		}
	}
	return 0;
}
