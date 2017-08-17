
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//ʹ���ڽӾ����ʾ��

#define maxVertices 20  //Ĭ�϶������
#define maxWeight FLT_MAX //Ĭ��Ȩ�����ֵ

typedef struct MGraph {
	int numVertices, numEdges;//ͼ��ʵ�ʶ���ĸ����ͱߵ�����
	char VerticesList[maxVertices]; //�����һά�����ü�ָ�붨��
	int Edge[maxVertices][maxVertices];                 //�ڽӾ��󣬶�ά������˫*��ʾ
};


void InitGraph(MGraph &G) {
	G.numVertices = 0;
	G.numEdges = 0;


	for (int i = 0; i < maxVertices; i++)    //�ڽӾ����ʼ��
	{
		G.VerticesList[i] = '0';
		for (int j = 0; j < maxVertices; j++)   //��Ϊ�Ǵ�Ȩͼ��ȫ����ֵΪ0
		{
			G.Edge[i][j] =( (i == j) ? 0 : maxVertices);   //maxWeight���������
		}
	}
}

//�Ӷ����������ҳ������
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

//���������д������ڽӾ���洢�Ĵ�Ȩ����ͼ
void CreateGraph(MGraph &G,int n,int m) {
	//�Ӽ�������n�������m���ߵ���Ϣ������һ����Ȩ������ͼ
	int i, j, k;
	char e1, e2;
	int weight;

	printf("�����붥��\n");

	for (i = 0; i < n; i++)
	{
		scanf("%c",&e1);
		G.VerticesList[i] = e1;
	}
	i = 0;
	//�����ڽӾ����ѳ�ʼ����
	printf("\n�����붥���Ȩ��\n");

	while (i<m)
	{
		scanf("%c%c%d",&e1,&e2,&weight);
		//�鶥���
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