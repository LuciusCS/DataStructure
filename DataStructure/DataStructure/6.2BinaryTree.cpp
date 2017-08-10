
#include <stdlib.h>
#include <stdio.h>


//���ļ����ڶ��������������Լ������Ĳ���

//�������Ľṹ��
typedef struct binaryTree {
	char item;
	struct binaryTree *lChild;
	struct binaryTree *rChild;

}binaryTree, *pBinaryTree;

//��������ʼ��ʱ��Ҫʹ�õݹ飬������������ķ�ʽ������Ӧ�������������룬����ȱʧ��Ҷ�ӽ����#����
pBinaryTree createBinaryTree() {

	char tmp = '0';
	pBinaryTree treeNode = NULL;
	scanf("%c", &tmp);

	//������������abd###c#e##
	if (tmp == '#')
	{
		treeNode = NULL;
	}
	else
	{
		//Ϊ����Ľڵ�����µ��ڴ�ռ�
		treeNode = (binaryTree*)malloc(sizeof(binaryTree));
		treeNode->item = tmp;

		//�ݹ���ò���������
		treeNode->lChild = createBinaryTree();
		treeNode->rChild = createBinaryTree();

	}
	return treeNode;

}

//������������������õݹ�ķ�ʽ
void preVisitBiTree(pBinaryTree root) {
	if (root)
	{
		//�ȱ������ڵ�
		printf("%c", root->item);
		//����������
		preVisitBiTree(root->lChild);
		//����������
		preVisitBiTree(root->rChild);

	}
}


//������������������õݹ�ķ�ʽ
void inVisitBiTree(pBinaryTree inRoot) {

	if (inRoot)
	{
		//�ȱ���������
		inVisitBiTree(inRoot->lChild);
		//�������ڵ�
		printf("%c", inRoot->item);
		//����������
		inVisitBiTree(inRoot->rChild);
	}

}

void lastVisitBiTree(pBinaryTree lastRoot) {

	if (lastRoot)
	{
		//����������
		inVisitBiTree(lastRoot->lChild);

		//����������
		inVisitBiTree(lastRoot->rChild);
		//�������ڵ�
		printf("%c", lastRoot->item);
	}
}


//������������������õݹ�ķ�ʽ


//int main() {
//
//	//����һ�Ŷ�����
//	pBinaryTree binaryTree = createBinaryTree();
//	//������������ķ�ʽ�������������
//	preVisitBiTree(binaryTree);
//	printf("\n");
//	//������������ķ�ʽ���������
//	inVisitBiTree(binaryTree);
//	printf("\n");
//	lastVisitBiTree(binaryTree);
//	printf("���Զ�����");
//	system("pause");
//	return 0;
//}