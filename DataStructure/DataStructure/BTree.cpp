#include "stdio.h"
#include "stdlib.h"


//B���ڵ�ṹ����

#define maxValue ;   //�ؼ��뼯���в������е����ֵ
#define m 3          //B���Ľ���

//B�����ṹ����
typedef struct BTreeNode {
	int keynum;
	BTreeNode *parent;   //���ڵ�ָ��
	int key[m + 1];     //key[m]Ϊ�����ڼ湤����Ԫ��key[0]δ��
	BTreeNode *ptr[m + 1]; //�����ڵ�ָ�����飬ptr[m]�ڲ������ʱ��
	int *recptr[m + 1];     //ÿ����������ָ����������Ӧ��¼��ʼ��ַ��ָ��
}*BTree;

//���ҽ����Ԫ�鶨��
typedef struct Triple {
	BTreeNode *r;        //����ַָ��
	int i;               //����йؼ������i
	int tag;
};                       //tag=0�������ɹ���tag=1,�������ɹ�



int main() {

	system("pause");
	return 0;
}