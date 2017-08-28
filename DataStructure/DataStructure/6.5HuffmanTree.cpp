#include "stdio.h"
#include "stdlib.h"

//Huffman�����㷨ʵ��

//Huffman���Ľṹ����

#define leafNumber 20    
#define totalNumber 39    //���Ľ��ĸ���=2*leafNumber-1

//���Ľ��Ķ���

typedef struct HuffmanNode {
	//char data;              //����
	int weight;             //Ȩ��
	int lChild, rChild, parent; //ָ��
};

//���Ľṹ����
typedef struct HuffmanTree {
	HuffmanNode elem[totalNumber];  //���Ĵ洢����
	int n;                          //��ǰ����ĸ���
};

//����Huffman�����㷨

void createHuffmanTree(HuffmanTree &HT,int weight[],int n) {
	//����n��Ȩ�ص����飬����Huffman��HT
	int p1,p2, min1, min2;                   //p1����С��λ�ã�p2�Ǵ�С��λ�ã�min1����С��ֵ��min2�Ǵ�С��ֵ
	for (int i = 0; i < n; i++)
		HT.elem[i].weight = weight[i];        //Ȩ�ش�������
	for (int i = 0; i < 2*n-1; i++)            //Ԫ�س�ʼ��
		HT.elem[i].parent = HT.elem[i].lChild = HT.elem[i].rChild = -1;
	p1 = p2 = 0;
	for ( int i = n; i <2*n-1; i++)          //�����Ҷ�ڵ㹹��
	{
		min1 = min2 = 100;
		for ( int j = 0; j < i; j++)          //Ѱ�Ҿ�����С����Сֵ�ĸ�����
		{
			if (HT.elem[j].parent== -1) {    //��ָ��Ϊ-1�����ʱ�ýڵ�û�и���
				if (HT.elem[j].weight<min1)   //��ԭ����С�Ļ�ҪС
				{
					p2 = p1;                   
					min2 = min1;               //ԭ����С�ı�Ϊ��С
					p1 = j;
					min1 = HT.elem[j].weight;   //�����µ���Сֵ
				}
				else if (HT.elem[j].weight<min2) //��ԭ���Ĵ�С��ҪС
				{
					p2 = j;
					min2 = HT.elem[j].weight;    //�����µĴ�Сֵ
				}
			}
		}
		HT.elem[i].lChild = p1;
		HT.elem[i].rChild = p2;        //����С���Ҵ�С����
		HT.elem[i].weight = HT.elem[p1].weight + HT.elem[p2].weight;
		HT.elem[p1].parent = HT.elem[p2].parent =i ;          //���Ӹ��ڵ�
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