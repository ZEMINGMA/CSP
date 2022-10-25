#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//顶点
typedef struct VNode
{
	int num;//当前结点的线路号
	float dist;//当前结点的到前一个结点的距离
	char NodeName[30];
	struct VNode* prenode = NULL;//指向前一个结点的指针
	struct VNode* nextnode = NULL;//指向下一个结点的指针
}VNode, AdjList[20];

int vexnum;//存放邻接表当前顶点数
char N[30] ;


void CreateG(AdjList G);
void printG(AdjList G);
//定位函数
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
			p->num =  G[i].num;
			p0->nextnode = p;
			p->prenode = p0;//构建双向链表
			p0 = p;
			if (p->dist == 0)//一条线路输入结束的判断
			{
				
				break;
			}
			
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
	VNode* p2 = (VNode*)malloc(sizeof(VNode));//p1、p2是用来遍历图的指针
	VNode* p3 = (VNode*)malloc(sizeof(VNode));//p3是用来暂存信息的指针
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
			printf("增加失败，已有同名站点\n");
			return;
		}

		strcpy(p3->NodeName , OpVnode);
		p3->nextnode = G[i].nextnode;
		G[i].nextnode = p3;
		G[i].nextnode->prenode = p3;  //双向链表的插入
		G[i].nextnode->num = i;                  //配置结点信息：线路号、距离
		G[i].nextnode->dist = nextd;
		printG_1(G,i);
		return;
	}
	else {
		scanf("%s %s", preVnode, OpVnode);
		strcpy(p3->NodeName, OpVnode);

		if (SearchNode(G, OpVnode, i) == 1) {
			printf("增加失败，已有同名站点\n");
			return;
		}

		p3->dist = nextd;
		p3->num = num;
		//找到操作位置
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
	
	printf("增加失败，没有与输入的增加位置前一站点同名的站点\n");
	return;
}

void DeleteOP(AdjList G) {
	VNode* p1 = (VNode*)malloc(sizeof(VNode));
	VNode* p2 = (VNode*)malloc(sizeof(VNode));//p1、p2是用来遍历图的指针
	
	int i, num;
	float pred, nextd;
	char OpVnode[20];
	char preVnode[20];
	scanf("%d", &num);
	i = findline(G, num);
	getchar();
	
		scanf("%s", OpVnode);

		if (SearchNode(G, OpVnode, i) == 0) {
			printf("删除失败，没有同名站点\n");
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
	//printf("增加站点请输入add，删除站点请输入delete\n");
		scanf("%s", op);
		if (strcmp(op, a) == 0) { AddOP(G); }
		else DeleteOP(G);
	}
	system("pause");
	return 0;
}