
#include <stdlib.h>
#include <stdio.h>

//采用数组表存储图

#define MAX_VERTEX_NUM 20
typedef struct ArcCell {
	int type;  //type是定点的关系类型，对于无权图用1或0表示；
				//表示相邻否，对带权图，则为权值类型
	int *info; //该弧相关信息的指针
};

typedef struct {
	int vexs[MAX_VERTEX_NUM];  // 顶点向量


};


//
//int main() {
//
//	printf("Graph测试");
//	return 0;
//
//}