#include "stdio.h"
#include "stdlib.h"

//�������Ĺ����Լ�������������

//����һ��ö����������ʾָ�����״̬,Link=0��ʾָ�����Һ��ӣ�Thread��ʾָ��ǰ������
typedef enum {
	Link = 0, Thread = 1
}PointerTag;
typedef struct BinaryTree {
	char item;
	BinaryTree *lChild;
	BinaryTree *rChild;
	PointerTag lTag, rTag;

}BinaryTree, *pBinaryTree;

//������������ķ�ʽ����������
pBinaryTree createBinaryTree() {

	pBinaryTree treeNode = NULL;
	char tmp = '0';
	scanf("%c", &tmp);

	if (tmp == '#')
	{
		treeNode = NULL;
	}
	else
	{
		treeNode = (BinaryTree *)malloc(sizeof(BinaryTree));
		treeNode->item = tmp;

		treeNode->lChild = createBinaryTree();
		if (treeNode->lChild)
			treeNode->lTag = Link;
		treeNode->rChild = createBinaryTree();
		if (treeNode->rChild)
			treeNode->rTag = Link;
	}
	return treeNode;
}

//�������������
void preVisitBiTree(pBinaryTree biTree) {
	if (biTree)
	{
		printf("%c", biTree->item);
		preVisitBiTree(biTree->lChild);
		preVisitBiTree(biTree->rChild);
	}
}


//�������������

void inVisitBiTree(pBinaryTree biTree) {
	if (biTree)
	{
		inVisitBiTree(biTree->lChild);
		printf("%c", biTree->item);
		inVisitBiTree(biTree->rChild);
	}
}



//ȫ�ֱ���������ָ��Node
pBinaryTree pre;
//����������
void InThreading(pBinaryTree &binaryTree) {
	if (binaryTree)
	{
		InThreading(binaryTree->lChild);
		//���û������ʱǰ������
		if (!binaryTree->lChild)
		{
			binaryTree->lTag = Thread;
			binaryTree->lChild = pre;
		}
		//��û���Һ��ӣ��������
		if (!pre->rChild)
		{
			pre->rTag = Thread;
			pre->rChild = binaryTree;
		}
		pre = binaryTree;   //����preָ��ǰ����
		InThreading(binaryTree->rChild);
	}
}


void InOrderThreading(pBinaryTree &binarytree, pBinaryTree &head) {



	head = (pBinaryTree)malloc(sizeof(BinaryTree));

	//��ʼ��ͷ���
	head->lTag = Link;
	head->rTag = Thread;
	head->rChild = head;  //ͷָ���ָ

	//�Դ���ڶ����������кϷ��Լ�⣬����ȡ��Ӧ�Ĵ�����TΪ��ʱ
	if (!binarytree) {
		head->lChild = head;
	}
	else
	{
		head->lChild = binarytree;  //��binaryTree�ǿ�ʱ��ָ��������ĸ����
		pre = head;

		InThreading(binarytree);

		//�����һ���ڵ�������
		pre->rTag = Thread;
		pre->rChild = head;
		head->rChild = pre;   //ͷ���ָ��������������һ�����
	}
}


//�������һ�ö���������binaryTree,(*BinarytreeΪͷָ��)
void InVisitThreadTree(pBinaryTree binarytree) {
	pBinaryTree pBTree;
	pBTree = binarytree->lChild;

	//��δ�������������ö���������ѭ�����������߱�������ʱ��pBTree=binaryTree
	while (pBTree != binarytree)
	{
		//�ҵ�����Ԫ��
		while (pBTree->lTag == Link)
		{
			pBTree = pBTree->lChild;
		}
		printf("%c", pBTree->item);

		//����Һ���������������ָ�������һ�����ʵĽ��
		while ((pBTree->rChild != binarytree) && (pBTree->rTag == Thread))
		{
			pBTree = pBTree->rChild;
			printf("%c", pBTree->item);
		}
		pBTree = pBTree->rChild;

	}
}


int main() {
	pBinaryTree TbinaryTree, Head;
	TbinaryTree = createBinaryTree();
	printf("���������������\n");
	preVisitBiTree(TbinaryTree);
	printf("\n���������������\n");
	inVisitBiTree(TbinaryTree);
	InOrderThreading(TbinaryTree, Head);
	printf("\n�����������������������\n");
	InVisitThreadTree(Head);
	printf("\n");
	system("pause");
	return 0;
}