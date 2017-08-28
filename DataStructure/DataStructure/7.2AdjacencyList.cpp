#include "stdlib.h"
#include "stdio.h"


/*使用邻接表来表示图*/
#define maxVertices 30          //图中顶点数目的最大值
#define maxWeight -1      //权重的最大追（使用-1来表示无穷大）

typedef struct EdgeNode {       //边结点的定义
	int dest;                   //边的另一个定点的位置
	int cost;                   //边上的权重
	struct EdgeNode *link;      //下一条边链指针
};

typedef struct VertexNode {       //顶点的定义
	char data;              
	struct  EdgeNode *first;     //边链表的头指针
};
typedef struct ALGraph {          //图的定义
	VertexNode VerticesList[maxVertices];     //顶点表（各边链表的头结点）
	int numVertices, numEdge;      //图中实际顶点的个数和边的条数
};

//初始化使用邻接表表示的图
void initGraph(ALGraph &G) {
	G.numEdge = 0;
	G.numVertices = 0;
	for (int i = 0; i < maxVertices; i++)
	{
		G.VerticesList[i].first = NULL;
	}
}


int getVertices(ALGraph G,char x) {
	for (int i = 0; i < G.numVertices; i++)
	{
		if (G.VerticesList[i].data==x)
		{
			return i;
		}
	}
	return -1;
}

//创建一个带权的无向图
void createGraph(ALGraph &G, int numVertices, int numEdge) {
	//从键盘输入n个顶点和m条边的信息
	G.numVertices = numVertices;
	G.numEdge = numEdge;
	printf("请输入顶点\n");
	for ( int i = 0; i < numVertices; i++)
	{
		scanf("%c",&G.VerticesList[i].data);
	}
	printf("请输入顶点和权重\n");
	for (int i = 0; i < G.numEdge;)
	{
		char e1, e2;
		int weight;
		getchar();
		scanf("%c %c %d",&e1,&e2,&weight);
		if (getVertices(G,e1)!=-1&& getVertices(G, e2) != -1)
		{
			EdgeNode *p, *q;
			p = G.VerticesList[getVertices(G, e1)].first;
			q = (EdgeNode *)malloc(sizeof(EdgeNode));
			if (p==NULL)
			{
				G.VerticesList[getVertices(G, e1)].first = q;
				q->dest = getVertices(G, e2);
				q->cost = weight;
				q->link = NULL;
				i++;
			}
			else
			{
				while (p->link != NULL)
				{
					p = p->link;
				}
				p->link= q;
				q->dest = getVertices(G, e2);
				q->cost = weight;
				q->link = NULL;
				i++;
			}
		}
		else
		  printf("顶点输入错误，请重新输入\n");
	}
}

//
//int main() {
//	ALGraph G;
//	initGraph(G);
//	createGraph(G, 4, 6);
//
//	printf("结果输出\n");
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%c ",G.VerticesList[i]);
//		EdgeNode *p = G.VerticesList[i].first;
//		while (p!= NULL)
//		{
//			printf("%d ", p->dest);
//			printf("%d ",p->cost);
//			p = p->link;
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}