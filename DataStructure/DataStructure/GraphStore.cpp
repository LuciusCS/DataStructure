
#include <stdlib.h>
#include <stdio.h>

//���������洢ͼ

#define MAX_VERTEX_NUM 20
typedef struct ArcCell {
	int type;  //type�Ƕ���Ĺ�ϵ���ͣ�������Ȩͼ��1��0��ʾ��
				//��ʾ���ڷ񣬶Դ�Ȩͼ����ΪȨֵ����
	int *info; //�û������Ϣ��ָ��
};

typedef struct {
	int vexs[MAX_VERTEX_NUM];  // ��������


};


//
//int main() {
//
//	printf("Graph����");
//	return 0;
//
//}