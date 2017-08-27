
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//使用邻接矩阵表示图

#define maxVertices 20     //默认顶点个数
#define maxWeight -1   //默认权重最大值

typedef struct MGraph {
	int numVertices, numEdges;                          //图中实际顶点的个数和边的条数
	char VerticesList[maxVertices];                     //顶点数组
	int Edge[maxVertices][maxVertices];                 //邻接矩阵，使用二维数组表示
};


void InitGraph(MGraph &G) {
	G.numVertices = 0;
	G.numEdges = 0;
	for (int i = 0; i < maxVertices; i++)                //邻接矩阵初始化
	{
		G.VerticesList[i] = '0'; 
		for (int j = 0; j < maxVertices; j++)            //若为非带权图，全部赋值为0
			G.Edge[i][j] = ((i == j) ? 0 : maxWeight);   //maxWeight代表无穷大
	}
}

//从顶点数组中找出顶点的位置
int GetVertexPos(MGraph G, char x) {
	for (int i = 0; i < G.numVertices; i++)
	{
		if (G.VerticesList[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//从输入序列创建用邻接矩阵存储的带权无向图
void CreateGraph(MGraph &G, int numVertex, int numEdge) {
	//从键盘输入n个顶点和m条边的信息，建立一个带权的无向图
	char e;
	G.numVertices = numVertex;
	G.numEdges = numEdge;
	printf("请输入顶点\n");
	for (int i = 0; i < numVertex; i++)
	{
		scanf("%c", &e);
		G.VerticesList[i] = e;
	}
	printf("请输入顶点和权重\n");
	for (int i = 0; i < numEdge;)
	{
		char e1, e2;
		int weight;
		getchar();                  //如果不使用getchar(),则缓冲区内还会有回车键
		scanf("%c %c %d", &e1, &e2, &weight);
		if (GetVertexPos(G, e1) !=-1&& GetVertexPos(G, e2) !=-1)
		{
			G.Edge[GetVertexPos(G, e1)][GetVertexPos(G, e2)] = weight;
			G.Edge[GetVertexPos(G, e2)][GetVertexPos(G, e1)] = weight;     
			i++;
		}
		else
		{
			printf("输入顶点错误，请重新输入\n");
		}
	}
}

int main() {

	MGraph G;
	InitGraph(G);
	CreateGraph(G, 5, 7);
	printf("\n结果输出\n");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf("%d ",G.Edge[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}