#include "stdio.h"
#include "stdlib.h"


//B树节点结构定义

#define maxValue ;   //关键码集合中不可能有的最大值
#define m 3          //B树的阶数

//B数结点结构定义
typedef struct BTreeNode {
	int keynum;
	BTreeNode *parent;   //父节点指针
	int key[m + 1];     //key[m]为监视哨兼工作单元，key[0]未用
	BTreeNode *ptr[m + 1]; //子树节点指针数组，ptr[m]在插入溢出时用
	int *recptr[m + 1];     //每个索引项中指向数据区响应记录起始地址的指针
}*BTree;

//查找结果三元组定义
typedef struct Triple {
	BTreeNode *r;        //结点地址指针
	int i;               //结点中关键码序号i
	int tag;
};                       //tag=0，搜索成功；tag=1,搜索不成功



int main() {

	system("pause");
	return 0;
}