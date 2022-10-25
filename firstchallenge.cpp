#define _CRT_SECURE_NO_DEPRECATE
#include"stdio.h"
#include "stdlib.h"
#include "string.h"

//顶点
typedef struct VNode
{
	int num;//当前结点的线路号
	float dist ;//当前结点的到前一个结点的距离
	char NodeName[30];
	struct VNode* prenode ;//指向前一个结点的指针
	struct VNode* nextnode;//指向下一个结点的指针
}VNode, AdjList[20];

int vexnum;//存放邻接表当前顶点数

void CreateG(AdjList G);
void printG(AdjList G);
//定位函数
int LocateVex(AdjList G, char* v)
{
	for (int i = 0; i < vexnum; i++)
	{
		if ( strcmp(G[i].NodeName,v) == 1 )
			return i;
	}
}

//创建
void CreateG(AdjList G)
{
	int i, j;
	//printf("输入总线路数：\n");
	scanf("%d", &vexnum);//输入总线路数
	getchar();
	//printf("分别输入各线路的线路号、站点名称、站点间距离：\n");
	for (i = 0; i < vexnum; i++)
	{
		VNode* p0 = (VNode*)malloc(sizeof(VNode));
		p0 = &G[i];
		scanf("%d", &G[i].num);//输入线路号
		if (G[i].num == -1) break;
		for (int j = 0; j < 1000; j++)
		{
			VNode* p = (VNode*)malloc(sizeof(VNode));
			scanf("%s", p->NodeName); getchar();
			scanf("%f", &p->dist); getchar();
			
			p0->nextnode = p;
			p->prenode = p0;//构建双向链表
			p0 = p;
			if (p->dist == 0) break;//一条线路输入结束的判断
		}
	}
	
}
//输出表
void printG(AdjList G)
{
	VNode* p1 = (VNode*)malloc(sizeof(VNode));
	VNode* p2 = (VNode*)malloc(sizeof(VNode));
	for (int i = 0; i < vexnum; i++)
	{
		printf("%d ",G[i].num );
		p1 = &G[i];
		do {
			p2 = p1->nextnode;
			p1 = p2;
			if (p2->dist != 0) {
				printf("%s %0.2f ", p2->NodeName,p2->dist);
			}
			else printf("%s", p2->NodeName);



		} while (p2->dist != 0);
		printf(" ");
	}
}
int main()
{
	AdjList G;
	CreateG(G);
	printG(G);
	system("pause");
	return 0;
}