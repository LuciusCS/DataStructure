#include "stdio.h"
#include "stdlib.h"

//Huffman树的算法实现

//Huffman树的结构定义

#define leafNumber 20    
#define totalNumber 39    //树的结点的个数=2*leafNumber-1

//树的结点的定义

typedef struct HuffmanNode {
	//char data;              //数据
	int weight;             //权重
	int lChild, rChild, parent; //指针
};

//树的结构定义
typedef struct HuffmanTree {
	HuffmanNode elem[totalNumber];  //树的存储数组
	int n;                          //当前外结点的个数
};

//构建Huffman树的算法

void createHuffmanTree(HuffmanTree &HT,int weight[],int n) {
	//给出n个权重的数组，构造Huffman树HT
	int p1,p2, min1, min2;                   //p1记最小的位置，p2记次小的位置，min1是最小的值，min2是次小的值
	for (int i = 0; i < n; i++)
		HT.elem[i].weight = weight[i];        //权重传到树中
	for (int i = 0; i < 2*n-1; i++)            //元素初始化
		HT.elem[i].parent = HT.elem[i].lChild = HT.elem[i].rChild = -1;
	p1 = p2 = 0;
	for ( int i = n; i <2*n-1; i++)          //逐个非叶节点构造
	{
		min1 = min2 = 100;
		for ( int j = 0; j < i; j++)          //寻找具有最小、次小值的根建树
		{
			if (HT.elem[j].parent== -1) {    //父指针为-1，则此时该节点没有父亲
				if (HT.elem[j].weight<min1)   //比原来最小的还要小
				{
					p2 = p1;                   
					min2 = min1;               //原来最小的变为最小
					p1 = j;
					min1 = HT.elem[j].weight;   //记下新的最小值
				}
				else if (HT.elem[j].weight<min2) //比原来的次小还要小
				{
					p2 = j;
					min2 = HT.elem[j].weight;    //记下新的次小值
				}
			}
		}
		HT.elem[i].lChild = p1;
		HT.elem[i].rChild = p2;        //左最小，右次小链接
		HT.elem[i].weight = HT.elem[p1].weight + HT.elem[p2].weight;
		HT.elem[p1].parent = HT.elem[p2].parent =i ;          //链接父节点
	}
	HT.n = 2 * n - 1;
}


//int main() {
//	int weight[5] = {7,5,2,4,6};
//	HuffmanTree ht;
//    createHuffmanTree(ht,weight,5);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d %d %d %d\n", ht.elem[i].weight,ht.elem[i].parent, ht.elem[i].lChild, ht.elem[i].rChild);
//	}
//	system("pause");
//	return 0;
//}