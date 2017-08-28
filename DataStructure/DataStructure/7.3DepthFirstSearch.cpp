#include "stdio.h"
#include "stdlib.h"

//#include "7.2AdjacencyList.cpp"

//进行深度优先搜索使用的表是邻接链表


////从顶点位置v出发，以深度优先的次序访问所有可读入的尚未访问过的顶点
////辅助数组visited用于对访问过的顶点进行标记；
//
//void DFS(ALGraph &G,int v,int visited[]) {
//	                                  //访问顶点v
//	visited[v] = 1;                   //顶点v作访问标记
//	int w = FirstNeighbor(G, v);      //找顶点v的第一个邻接顶点
//	while (w!=-1)                     //若邻接顶点w存在
//	{
//		if (visited[w] == 0)
//			DFS(G, w, visited);        //若w未访问过，递归访问顶点w
//		w = NextNeighbor(G, v, w);
//
//	}
//
//}
//
//
////找顶点的第一个邻接顶点w
//int FirstNeighbor(ALGraph G,int v) {
//
//}
//
////取v排在w后的下一个邻接顶点
//int NextNeighbor(ALGraph G,int v,int w) {
//
//}
//
////从顶点v出发，对图G进行深度优先遍历的主过程
//void DFS_TraversalOfVertices(ALGraph &G, int v) {
//	int i;
//	int n = G.numVertices;    //取图中顶点的个数
//	int *visited = new int[n];  //创建辅助数组
//	for (int i = 0; i < n; i++)
//	{
//		visited[i] = 0;          //辅助数组初始化
//	}
//	DFS(G, v, visited);           //从顶点v进行深度优先搜索
//	delete[]visited;              //释放visited
//
//}
//

//int main() {
//
//
//	system("pause");
//	return 0;
//}