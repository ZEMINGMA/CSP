#define _CRT_SECURE_NO_DEPRECATE
#include"stdio.h"
#include "stdlib.h"
#include "string.h"

//����
typedef struct VNode
{
	int num;//��ǰ������·��
	float dist ;//��ǰ���ĵ�ǰһ�����ľ���
	char NodeName[30];
	struct VNode* prenode ;//ָ��ǰһ������ָ��
	struct VNode* nextnode;//ָ����һ������ָ��
}VNode, AdjList[20];

int vexnum;//����ڽӱ�ǰ������

void CreateG(AdjList G);
void printG(AdjList G);
//��λ����
int LocateVex(AdjList G, char* v)
{
	for (int i = 0; i < vexnum; i++)
	{
		if ( strcmp(G[i].NodeName,v) == 1 )
			return i;
	}
}

//����
void CreateG(AdjList G)
{
	int i, j;
	//printf("��������·����\n");
	scanf("%d", &vexnum);//��������·��
	getchar();
	//printf("�ֱ��������·����·�š�վ�����ơ�վ�����룺\n");
	for (i = 0; i < vexnum; i++)
	{
		VNode* p0 = (VNode*)malloc(sizeof(VNode));
		p0 = &G[i];
		scanf("%d", &G[i].num);//������·��
		if (G[i].num == -1) break;
		for (int j = 0; j < 1000; j++)
		{
			VNode* p = (VNode*)malloc(sizeof(VNode));
			scanf("%s", p->NodeName); getchar();
			scanf("%f", &p->dist); getchar();
			
			p0->nextnode = p;
			p->prenode = p0;//����˫������
			p0 = p;
			if (p->dist == 0) break;//һ����·����������ж�
		}
	}
	
}
//�����
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