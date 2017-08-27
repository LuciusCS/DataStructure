
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//ʹ���ڽӾ����ʾͼ

#define maxVertices 20     //Ĭ�϶������
#define maxWeight -1   //Ĭ��Ȩ�����ֵ

typedef struct MGraph {
	int numVertices, numEdges;                          //ͼ��ʵ�ʶ���ĸ����ͱߵ�����
	char VerticesList[maxVertices];                     //��������
	int Edge[maxVertices][maxVertices];                 //�ڽӾ���ʹ�ö�ά�����ʾ
};


void InitGraph(MGraph &G) {
	G.numVertices = 0;
	G.numEdges = 0;
	for (int i = 0; i < maxVertices; i++)                //�ڽӾ����ʼ��
	{
		G.VerticesList[i] = '0'; 
		for (int j = 0; j < maxVertices; j++)            //��Ϊ�Ǵ�Ȩͼ��ȫ����ֵΪ0
			G.Edge[i][j] = ((i == j) ? 0 : maxWeight);   //maxWeight���������
	}
}

//�Ӷ����������ҳ������λ��
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

//���������д������ڽӾ���洢�Ĵ�Ȩ����ͼ
void CreateGraph(MGraph &G, int numVertex, int numEdge) {
	//�Ӽ�������n�������m���ߵ���Ϣ������һ����Ȩ������ͼ
	char e;
	G.numVertices = numVertex;
	G.numEdges = numEdge;
	printf("�����붥��\n");
	for (int i = 0; i < numVertex; i++)
	{
		scanf("%c", &e);
		G.VerticesList[i] = e;
	}
	printf("�����붥���Ȩ��\n");
	for (int i = 0; i < numEdge;)
	{
		char e1, e2;
		int weight;
		getchar();                  //�����ʹ��getchar(),�򻺳����ڻ����лس���
		scanf("%c %c %d", &e1, &e2, &weight);
		if (GetVertexPos(G, e1) !=-1&& GetVertexPos(G, e2) !=-1)
		{
			G.Edge[GetVertexPos(G, e1)][GetVertexPos(G, e2)] = weight;
			G.Edge[GetVertexPos(G, e2)][GetVertexPos(G, e1)] = weight;     
			i++;
		}
		else
		{
			printf("���붥���������������\n");
		}
	}
}

int main() {

	MGraph G;
	InitGraph(G);
	CreateGraph(G, 5, 7);
	printf("\n������\n");
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