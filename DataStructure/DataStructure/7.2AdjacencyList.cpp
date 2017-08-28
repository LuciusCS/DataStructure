#include "stdlib.h"
#include "stdio.h"


/*ʹ���ڽӱ�����ʾͼ*/
#define maxVertices 30          //ͼ�ж�����Ŀ�����ֵ
#define maxWeight -1      //Ȩ�ص����׷��ʹ��-1����ʾ�����

typedef struct EdgeNode {       //�߽��Ķ���
	int dest;                   //�ߵ���һ�������λ��
	int cost;                   //���ϵ�Ȩ��
	struct EdgeNode *link;      //��һ������ָ��
};

typedef struct VertexNode {       //����Ķ���
	char data;              
	struct  EdgeNode *first;     //�������ͷָ��
};
typedef struct ALGraph {          //ͼ�Ķ���
	VertexNode VerticesList[maxVertices];     //��������������ͷ��㣩
	int numVertices, numEdge;      //ͼ��ʵ�ʶ���ĸ����ͱߵ�����
};

//��ʼ��ʹ���ڽӱ��ʾ��ͼ
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

//����һ����Ȩ������ͼ
void createGraph(ALGraph &G, int numVertices, int numEdge) {
	//�Ӽ�������n�������m���ߵ���Ϣ
	G.numVertices = numVertices;
	G.numEdge = numEdge;
	printf("�����붥��\n");
	for ( int i = 0; i < numVertices; i++)
	{
		scanf("%c",&G.VerticesList[i].data);
	}
	printf("�����붥���Ȩ��\n");
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
		  printf("���������������������\n");
	}
}

//
//int main() {
//	ALGraph G;
//	initGraph(G);
//	createGraph(G, 4, 6);
//
//	printf("������\n");
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