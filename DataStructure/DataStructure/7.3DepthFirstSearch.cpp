#include "stdio.h"
#include "stdlib.h"

//#include "7.2AdjacencyList.cpp"

//���������������ʹ�õı����ڽ�����


////�Ӷ���λ��v��������������ȵĴ���������пɶ������δ���ʹ��Ķ���
////��������visited���ڶԷ��ʹ��Ķ�����б�ǣ�
//
//void DFS(ALGraph &G,int v,int visited[]) {
//	                                  //���ʶ���v
//	visited[v] = 1;                   //����v�����ʱ��
//	int w = FirstNeighbor(G, v);      //�Ҷ���v�ĵ�һ���ڽӶ���
//	while (w!=-1)                     //���ڽӶ���w����
//	{
//		if (visited[w] == 0)
//			DFS(G, w, visited);        //��wδ���ʹ����ݹ���ʶ���w
//		w = NextNeighbor(G, v, w);
//
//	}
//
//}
//
//
////�Ҷ���ĵ�һ���ڽӶ���w
//int FirstNeighbor(ALGraph G,int v) {
//
//}
//
////ȡv����w�����һ���ڽӶ���
//int NextNeighbor(ALGraph G,int v,int w) {
//
//}
//
////�Ӷ���v��������ͼG����������ȱ�����������
//void DFS_TraversalOfVertices(ALGraph &G, int v) {
//	int i;
//	int n = G.numVertices;    //ȡͼ�ж���ĸ���
//	int *visited = new int[n];  //������������
//	for (int i = 0; i < n; i++)
//	{
//		visited[i] = 0;          //���������ʼ��
//	}
//	DFS(G, v, visited);           //�Ӷ���v���������������
//	delete[]visited;              //�ͷ�visited
//
//}
//

//int main() {
//
//
//	system("pause");
//	return 0;
//}