#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����
typedef struct VNode
{
	int num;//��ǰ������·��
	float dist;//��ǰ���ĵ�ǰһ�����ľ���
	char NodeName[30];
	struct VNode* prenode = NULL;//ָ��ǰһ������ָ��
	struct VNode* nextnode = NULL;//ָ����һ������ָ��
}VNode, AdjList[20];

int vexnum;//����ڽӱ�ǰ������
char N[30] ;


void CreateG(AdjList G);
void printG(AdjList G);
//��λ����
int SearchNode(AdjList G, char* v,int i)
{
	VNode* p1 = (VNode*)malloc(sizeof(VNode));
	VNode* p2 = (VNode*)malloc(sizeof(VNode));
	
	p1 = &G[i];

	do {
		p2 = p1->nextnode;
		p1 = p2;
		if (strcmp(p2->NodeName,v)==0) {
			return 1;
		}
		
	} while (p2->dist!=0);

	return 0;

}


int findline(AdjList G, int num) {
	int i;
	for (i = 0; i < vexnum; i++){
		if (G[i].num == num) return i;
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
			p->num =  G[i].num;
			p0->nextnode = p;
			p->prenode = p0;//����˫������
			p0 = p;
			if (p->dist == 0)//һ����·����������ж�
			{
				
				break;
			}
			
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
		printf("%d ", G[i].num);
		p1 = &G[i];
		do {
			p2 = p1->nextnode;
			p1 = p2;
			if (p2->dist != 0) {
				printf("%s %0.2f ", p2->NodeName, p2->dist);
			}
			else printf("%s", p2->NodeName);



		} while (p2->dist != 0);
		printf("\n");
	}
}

void printG_1(AdjList G, int i) {
	VNode* p1 = (VNode*)malloc(sizeof(VNode));
	VNode* p2 = (VNode*)malloc(sizeof(VNode));
	
		printf("%d ", G[i].num);
		p1 = &G[i];
		do {
			p2 = p1->nextnode;
			p1 = p2;
			if (p2->dist != 0) {
				printf("%s %0.2f ", p2->NodeName, p2->dist);
			}
			else printf("%s", p2->NodeName);



		} while (p2->dist != 0);
		return;
}


void AddOP(AdjList G) {
	VNode* p1 = (VNode*)malloc(sizeof(VNode));
	VNode* p2 = (VNode*)malloc(sizeof(VNode));//p1��p2����������ͼ��ָ��
	VNode* p3 = (VNode*)malloc(sizeof(VNode));//p3�������ݴ���Ϣ��ָ��
	int i,num;
	float pred, nextd;
	char OpVnode[20];
	char preVnode[20];
	scanf("%d %f %f", &num, &pred, &nextd);
	i = findline(G,num);
	getchar();
	if (pred == 0) {
		scanf("%s", OpVnode);

		if (SearchNode(G, OpVnode,i) == 1) {
			printf("����ʧ�ܣ�����ͬ��վ��\n");
			return;
		}

		strcpy(p3->NodeName , OpVnode);
		p3->nextnode = G[i].nextnode;
		G[i].nextnode = p3;
		G[i].nextnode->prenode = p3;  //˫������Ĳ���
		G[i].nextnode->num = i;                  //���ý����Ϣ����·�š�����
		G[i].nextnode->dist = nextd;
		printG_1(G,i);
		return;
	}
	else {
		scanf("%s %s", preVnode, OpVnode);
		strcpy(p3->NodeName, OpVnode);

		if (SearchNode(G, OpVnode, i) == 1) {
			printf("����ʧ�ܣ�����ͬ��վ��\n");
			return;
		}

		p3->dist = nextd;
		p3->num = num;
		//�ҵ�����λ��
		p1 = &G[i];
		do {
			p2 = p1->nextnode;
			p1 = p2;
			if ( strcmp(p2->NodeName,preVnode)==0 ) {
				p3->nextnode = p2->nextnode;
				p2->nextnode = p3;
				p3->prenode = p2;
				p2->dist = pred;
				p3->nextnode->prenode = p3;
				printG_1(G,i);
				return;
			}

		} while (p2->dist!= 0);
	
	
	}
	
	printf("����ʧ�ܣ�û�������������λ��ǰһվ��ͬ����վ��\n");
	return;
}

void DeleteOP(AdjList G) {
	VNode* p1 = (VNode*)malloc(sizeof(VNode));
	VNode* p2 = (VNode*)malloc(sizeof(VNode));//p1��p2����������ͼ��ָ��
	
	int i, num;
	float pred, nextd;
	char OpVnode[20];
	char preVnode[20];
	scanf("%d", &num);
	i = findline(G, num);
	getchar();
	
		scanf("%s", OpVnode);

		if (SearchNode(G, OpVnode, i) == 0) {
			printf("ɾ��ʧ�ܣ�û��ͬ��վ��\n");
			return;
		}

		p1 = &G[i];
		do {
			p2 = p1->nextnode;
			p1 = p2;
			if (strcmp(p2->NodeName, OpVnode) == 0) {
				p2->prenode->nextnode = p2->nextnode;
				p2->nextnode->prenode = p2->prenode;
				p2->prenode->dist = p2->prenode->dist + p2->dist;
				/*p3->nextnode = p2->nextnode;
				p2->nextnode = p3;
				p3->prenode = p2;
				p2->dist = pred;
				p3->nextnode->prenode = p3;*/
				printG_1(G,i);
				return;
			}

		} while (p2->dist != 0);
	

}

int main()
{
	char c;
	AdjList G;
	CreateG(G);
	printG(G);
	char op[20];
	char a[4] = "add";
	while ((c = getchar()) != EOF) {
	//printf("����վ��������add��ɾ��վ��������delete\n");
		scanf("%s", op);
		if (strcmp(op, a) == 0) { AddOP(G); }
		else DeleteOP(G);
	}
	system("pause");
	return 0;
}