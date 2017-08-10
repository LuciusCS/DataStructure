
#include <stdlib.h>
#include <stdio.h>


//此文件用于二叉树构建遍历以及其他的操作

//二叉树的结构体
typedef struct binaryTree {
	char item;
	struct binaryTree *lChild;
	struct binaryTree *rChild;

}binaryTree, *pBinaryTree;

//二叉树初始化时需要使用递归，按照先序遍历的方式，将对应的满二叉树输入，其中缺失的叶子结点用#填满
pBinaryTree createBinaryTree() {

	char tmp = '0';
	pBinaryTree treeNode = NULL;
	scanf("%c", &tmp);

	//构建测试用例abd###c#e##
	if (tmp == '#')
	{
		treeNode = NULL;
	}
	else
	{
		//为加入的节点分配新的内存空间
		treeNode = (binaryTree*)malloc(sizeof(binaryTree));
		treeNode->item = tmp;

		//递归调用产生二叉树
		treeNode->lChild = createBinaryTree();
		treeNode->rChild = createBinaryTree();

	}
	return treeNode;

}

//先序遍历二叉树，采用递归的方式
void preVisitBiTree(pBinaryTree root) {
	if (root)
	{
		//先遍历根节点
		printf("%c", root->item);
		//遍历左子树
		preVisitBiTree(root->lChild);
		//遍历右子树
		preVisitBiTree(root->rChild);

	}
}


//中序遍历二叉树，采用递归的方式
void inVisitBiTree(pBinaryTree inRoot) {

	if (inRoot)
	{
		//先遍历左子树
		inVisitBiTree(inRoot->lChild);
		//遍历根节点
		printf("%c", inRoot->item);
		//遍历右子树
		inVisitBiTree(inRoot->rChild);
	}

}

void lastVisitBiTree(pBinaryTree lastRoot) {

	if (lastRoot)
	{
		//遍历左子树
		inVisitBiTree(lastRoot->lChild);

		//遍历右子树
		inVisitBiTree(lastRoot->rChild);
		//遍历根节点
		printf("%c", lastRoot->item);
	}
}


//后序遍历二叉树，采用递归的方式


//int main() {
//
//	//构建一颗二叉树
//	pBinaryTree binaryTree = createBinaryTree();
//	//采用先序遍历的方式遍历输出二叉树
//	preVisitBiTree(binaryTree);
//	printf("\n");
//	//采用中序遍历的方式输出二叉树
//	inVisitBiTree(binaryTree);
//	printf("\n");
//	lastVisitBiTree(binaryTree);
//	printf("测试二叉树");
//	system("pause");
//	return 0;
//}