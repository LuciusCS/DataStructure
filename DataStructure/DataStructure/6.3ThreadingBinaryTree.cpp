#include "stdio.h"
#include "stdlib.h"

//二叉树的构造以及线索化二叉树

//声明一个枚举类型来表示指针域的状态,Link=0表示指向左右孩子，Thread表示指向前驱或后继
typedef enum {
	Link = 0, Thread = 1
}PointerTag;
typedef struct BinaryTree {
	char item;
	BinaryTree *lChild;
	BinaryTree *rChild;
	PointerTag lTag, rTag;

}BinaryTree, *pBinaryTree;

//按照先序遍历的方式构建二叉树
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

//先序遍历二叉树
void preVisitBiTree(pBinaryTree biTree) {
	if (biTree)
	{
		printf("%c", biTree->item);
		preVisitBiTree(biTree->lChild);
		preVisitBiTree(biTree->rChild);
	}
}


//中序遍历二叉树

void inVisitBiTree(pBinaryTree biTree) {
	if (biTree)
	{
		inVisitBiTree(biTree->lChild);
		printf("%c", biTree->item);
		inVisitBiTree(biTree->rChild);
	}
}



//全局变量，用于指向Node
pBinaryTree pre;
//中序线索化
void InThreading(pBinaryTree &binaryTree) {
	if (binaryTree)
	{
		InThreading(binaryTree->lChild);
		//如果没有左孩子时前驱线索
		if (!binaryTree->lChild)
		{
			binaryTree->lTag = Thread;
			binaryTree->lChild = pre;
		}
		//当没有右孩子，后继线索
		if (!pre->rChild)
		{
			pre->rTag = Thread;
			pre->rChild = binaryTree;
		}
		pre = binaryTree;   //保持pre指向前驱；
		InThreading(binaryTree->rChild);
	}
}


void InOrderThreading(pBinaryTree &binarytree, pBinaryTree &head) {



	head = (pBinaryTree)malloc(sizeof(BinaryTree));

	//初始化头结点
	head->lTag = Link;
	head->rTag = Thread;
	head->rChild = head;  //头指针回指

	//对传入第二个参数进行合法性检测，并采取响应的处理，当T为空时
	if (!binarytree) {
		head->lChild = head;
	}
	else
	{
		head->lChild = binarytree;  //当binaryTree非空时，指向二叉树的根结点
		pre = head;

		InThreading(binarytree);

		//对最后一个节点线索化
		pre->rTag = Thread;
		pre->rChild = head;
		head->rChild = pre;   //头结点指向中序遍历的最后一个结点
	}
}


//中序遍历一棵二叉线索树binaryTree,(*Binarytree为头指针)
void InVisitThreadTree(pBinaryTree binarytree) {
	pBinaryTree pBTree;
	pBTree = binarytree->lChild;

	//当未遍历迭代完整棵二叉树继续循环；空树或者遍历结束时，pBTree=binaryTree
	while (pBTree != binarytree)
	{
		//找到最左元素
		while (pBTree->lTag == Link)
		{
			pBTree = pBTree->lChild;
		}
		printf("%c", pBTree->item);

		//如果右孩子是线索，则其指向的是下一个访问的结点
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
	printf("二叉树的先序遍历\n");
	preVisitBiTree(TbinaryTree);
	printf("\n二叉树的中序遍历\n");
	inVisitBiTree(TbinaryTree);
	InOrderThreading(TbinaryTree, Head);
	printf("\n中序线索二叉树的中序遍历\n");
	InVisitThreadTree(Head);
	printf("\n");
	system("pause");
	return 0;
}