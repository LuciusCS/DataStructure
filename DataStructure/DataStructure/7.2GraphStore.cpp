
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//使用邻接矩阵表示表

#define maxVertices 20  //默认顶点个数
#define maxWeight FLT_MAX //默认权重最大值

typedef struct MGraph {
	int numVertices, numEdges;//图中实际顶点的个数和边的条数
	char VerticesList[maxVertices]; //顶点表，一维数组用简单指针定义
	int Edge[maxVertices][maxVertices];                 //邻接矩阵，二维数组用双*表示
};


void InitGraph(MGraph &G) {
	G.numVertices = 0;
	G.numEdges = 0;


	for (int i = 0; i < maxVertices; i++)    //邻接矩阵初始化
	{
		G.VerticesList[i] = '0';
		for (int j = 0; j < maxVertices; j++)   //若为非带权图，全部赋值为0
		{
			G.Edge[i][j] =( (i == j) ? 0 : maxVertices);   //maxWeight代表无穷大
		}
	}
}

//从顶点数据中找出顶点号
int GetVertexPos(MGraph G, char x) {
	for (int i = 0; i < G.numVertices; i++)
	{
		if (G.VerticesList[i]==x)
		{
			return i;
		}
	}

	return -1;
}

//从输入序列创建用邻接矩阵存储的带权无向图
void CreateGraph(MGraph &G,int n,int m) {
	//从键盘输入n个定点和m条边的信息，建立一个带权的无向图
	int i, j, k;
	char e1, e2;
	int weight;

	printf("请输入顶点\n");

	for (i = 0; i < n; i++)
	{
		scanf("%c",&e1);
		G.VerticesList[i] = e1;
	}
	i = 0;
	//建立邻接矩阵，已初始化过
	printf("\n请输入顶点和权重\n");

	while (i<m)
	{
		scanf("%c%c%d",&e1,&e2,&weight);
		//查顶点号
		j = GetVertexPos(G,e1);
		k = GetVertexPos(G,e2);
		if (j!=-1&&k!=-1)
		{
			G.Edge[j][k] = weight;
			i++;
		}

	}
}
//
//int main(){
//
//	MGraph G;
//	InitGraph(G);
//
//	CreateGraph(G, 4, 4);
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d",G.Edge[i][j]);
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//
//}