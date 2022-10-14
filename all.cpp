#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<windows.h>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char ElemType;   //元素类型 
typedef int Status;
typedef double ElemType_D;  //多项式元素类型 

typedef struct LNode{
	ElemType_D coe;  //系数 
	int expo;  //指数 
	ElemType data;  //基本数据 
	struct LNode* next;
}LNode;   //节点结构体 
struct ARRAY_S{
	double co;  //系数 
	int exp;  //指数 
}sz[100];   //多项式结构体数组 
typedef LNode* LinkList;  //节点指针类型 
int Length;   //长度 
int num;    //全局变量，用于指示当前操作的线性表的标号 
LinkList array[11]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};//多表管理数组，存储表头指针 

void menu(void);   //菜单函数 
void exp_print(int exp); //多项式输出中指数格式调整函数 
void coe_print(ElemType_D coe,int flag);//多项式输出中系数格式调整函数 
void setListnum(int n); //19 设置表编码 
void visit (ElemType x); //visit遍历函数 
double abs_D(double x);  //浮点数的abs函数 
Status Compare (ElemType a,ElemType b);  //compare函数 
Status InitList(LinkList L);  //1 初始化表 
void DestroyList(LinkList *L);  //2 销毁表 
Status ClearList(LinkList L);  //3 清空表 
Status ListEmpty(LinkList L);  //4 判断空表 
int ListLength(LinkList L);  //5 求表长 
Status GetElem(LinkList L,int i, ElemType *e);  //6 获取元素 
Status LocateElem(LinkList L, ElemType e, Status(Compare)());  //7 查找元素 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);  //8  获得前驱 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);  //9 获得后继 
Status ListInsert(LinkList L, int i, ElemType e);   //10 插入元素 
Status ListDelete(LinkList L, int i, ElemType *e);   //11 删除元素 
Status ListTraverse(LinkList L, void(visit)());    //12 遍历 
Status CreatList(int n);    //21 创建多项式线性表 
Status ShowList(int num);    //22 输出多项式 
Status AddList(int num1, int num2, int num3);   //23 多项式加法 
Status MinusList(int num1, int num2, int num3);  //24 多项式减法 

void exp_print(int exp ){   //输出多项式中的x^ 
	if (exp==1){
		printf("x");
	} 
	else if (exp!=0) cout<<"x^"<<exp; 
}
void coe_print(ElemType_D coe,int flag){  //输出多项式中的系数，主要调整前面的正负与特判系数为1和-1的情况  
	int flag2 = 0; //flag2 指示 1 为 - 0为+ 
	if (flag){  //flag=1 为第一个系数不为0的元素 
		if (coe<0) flag2= 1;
		coe = abs_D(coe);
		if (flag2) cout<<"-";
		if (coe !=1 ) cout<<coe;

	}
	else {
		if (coe <0) flag2 =1;
		coe =abs_D(coe);
		if (flag2) cout << "-"; else cout <<"+";
		if (coe !=1) cout  <<coe;	
	}
}
int cmp(const void *a, const void *b){   //sort函数的 cmp 
	return (*(ARRAY_S *)a).exp > (*(ARRAY_S *)b).exp ? 1 : -1;
}
double abs_D(double x){    //double类型的abs函数 
	if (x>=0) return x; else return (-x);
}
void setListnum(int n){  //设置表号 
	num = n;   //num为全局变量 
}
void visit (ElemType x){  //visit函数 
	printf("%c",x);  //访问输出 
}
Status Compare (ElemType a,ElemType b){   //compare函数，用于查找比较 
	if (a==b) return OK; else return ERROR;
}
Status InitList(LinkList L){   //初始化表 
	(L) = (LinkList)malloc(sizeof(LNode));  //动态开辟空间 
	if(!(L)) return OVERFLOW;   //判断溢出 
	(L)->next = NULL;  //指示NULL 
	array[num] = L;   //存入多表管理数组中 
	return OK;
}

void DestroyList(LinkList L){  //销毁表 
	LinkList p = L;    //表头 
	while (p){   //只要不为空 
		p = (L)->next;   //指向下一个节点 
		free(L);  //释放空间 
		(L) = p;    // 指向下一个 （p） 
	}
}

Status ClearList(LinkList L){  //清空表 
	LinkList ptemp, p;
	if(!L) return ERROR;   //表已经为空则返回ERROR 
	ptemp = L->next;   //指向第一个节点 
	while(ptemp){   //只要不为null 
		p = ptemp->next;   //指向下一个节点 
		free(ptemp);  //释放空间 
		ptemp = p;    
	}
	L->next = NULL;  //表头的next赋值为NULL 
	return OK;
}

Status ListEmpty(LinkList L){  //判断表空 
	if(L != NULL && L->next != NULL)
		return FALSE;  //不为空返回FALSE 
	else return TRUE;  //为空返回TRUE 
}
int ListLength(LinkList L){ //求表长 
	LinkList p;
	int i = 0;  //使用i计数 
	if (L){
		i = 0;    //赋初值 0 
		p = L->next;  //指向第一个节点 
		while (p){  //直到 p为空，到表尾 
			i++;   //长度加1 
			p = p->next;
		}	
	}
	return i;  //返回表长 
}

Status GetElem(LinkList L,int i, ElemType *e){  //获得元素 
	int j = 1;  //使用j计数 
	LinkList p = L->next;  //指向第一个元素 
	if (i>ListLength(L)) return ERROR;  //判断i是否合法 
	while (p && j<i){   //循环条件为p不为空且j<i 
		j++;
		p = p->next;
	}
	*e =  p->data; //把获得的元素用e返回 
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType,ElemType)){  //查找元素 
	int i;
	int t;
	LinkList p;
	if (L){   //表不为空 
		i = 0;   //变量初值 
		p = L->next;  //指向第一个节点 
		while (p){  //只要当前节点不为null 
			i++;   //位置加1 
			if (!Compare(e,p->data)) p = p->next; else return i;  //查找到返回位置i ，当前 不是要查找的元素则指向下一个节点 
		}

	}
	else return ERROR; //到达表尾且没有查找到则返回ERROR 
	if(!p) return ERROR;
}
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e){//获得前驱 
	LinkList p, temp;
	p = L->next;  //第一个元素 
	if (p->data != cur_e){  //当前元素不是的第一个元素 ，如果是第一个元素不执行if，直接返回ERROR 
		while (p->next){
			temp = p->next; //使用temp获取 下一个元素 
			if (temp->data == cur_e){  //下一个元素是cur_e则当前元素即为cur_e的前驱 
				*pre_e = p->data;   //使用pre_e返回前驱 
				return OK;
			}
			p = temp;
		}
	}
	 return ERROR;  // 第一个元素的时候返回ERROR 
}
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e){  //获得后继 
	LinkList p, temp;
	if (L){   
		p = L->next;
		while (p && p->next){
			temp = p->next;  //使用temp获得下一个元素 
			if (p->data == cur_e){  // 当前元素是cur_e则下一个元素即为cur_e的后继 
				*next_e = temp->data;  //使用next_e返回后继 
				return OK;
			}
			p = temp;	
		}
	}
	return ERROR;  //最后一个元素的时候则返回ERROR 
}
Status ListInsert(LinkList L, int i, ElemType e){ //插入元素 
	LinkList p = L, temp;
	int j = 0;  //使用j找i的前一个位置 
	while (p && j < i-1){   //查找到i的前一个位置 
		p = p->next;
		j++;
	}

	temp = (LinkList)malloc(sizeof(LNode));  //开辟空间 
	if (!temp) return OVERFLOW;   //防止溢出 
	temp->data = e;  //赋值 
	temp->next = p->next;  //链接进表 
	p->next = temp;//链接进表 
	return OK;
}

Status ListDelete(LinkList L, int i, ElemType *e){  //删除元素 
	LinkList temp, pre = L;
	int j = 1;  //j找i的前一个位置 
	while (pre->next && j<i){
		pre = pre ->next;
		j++;
	}
	if (!pre->next || j>i) return ERROR;
	temp = pre->next;   //重新链接表 
	pre->next = temp->next;  //重新链接表 
	*e = temp->data;  //使用e返回删除的元素 
	free(temp);  //释放空间 
	return OK;
}
Status ListTraverse(LinkList L, void(visit)(ElemType)){  //遍历表 
	LinkList p;
	if(!L) return ERROR;  //表为空则返回ERROR 
	else p = L->next;  //指向第一个元素 
	while (p){    //只要没到表尾 
		visit(p->data);  //输出元素 
		p = p->next;   //指向下一个 
	}
	printf("\n");
	return OK;
}
Status CreatList(int n,int numm){   //创建多项式表 

	LinkList p = array[numm], temp;
	int i=0,j=0;

	qsort(sz,100,sizeof(sz[0]),cmp);//先以指数为关键字进行升序排序 

	while(i<n){
		temp = (LinkList)malloc(sizeof(LNode));  //开辟空间 
		if (!temp) return OVERFLOW;  //防止溢出 
		while(sz[i].exp==sz[i+1].exp){  //进行合并同类项 
			sz[i+1].co+=sz[i].co;
			i++;
		}
		temp->coe = sz[i].co;//插入表中系数 
		temp->expo = sz[i].exp;//插入表中指数  
		temp->next = p->next; // 头插法插入 
		p->next = temp;	
		i++;
	}

	return OK;
}
Status ShowList(int num){  //输出多项式  
	LinkList p=array[num];
	printf("您要查看的多项式如下：\n"); 
	int flag_1=1, flag_2 = 0;
	if (!p->next){   //运算结果为0的输出 
		printf("0\n");
		return OK;
	}
	p=p->next;   
	while((p->coe ==0)&&p->next){  //如果系数为0，则该项直接跳过 
		p=p->next;
	}
	if (!p->next && p->coe ==0){  //如果第一项系数为0且没有后项，输出0退出 
		printf("0\n");
		return OK;
	}
	coe_print(p->coe,1);  //进入coe_print输出函数，进行系数输出，此时flag为1，指示这是第一项的输出 
	exp_print(p->expo);  //进入exp_print输出函数，进行指数输出 
	p=p->next;  //下一项 
	while (p){

		while ((p->coe==0)&& p->next){
			p=p->next;    //同样判断系数是否为0 
		}
		if (!p->next && p->coe ==0) break;  //同样判断是否系数为0且没有后项 
		coe_print(p->coe,0); //输出系数，flag=0，指示这不是第一项输出  
		exp_print(p->expo);   //输出指数 
		p=p->next;  //下一项 
	}
	printf("\n");
	return OK;
}
Status ListInsert_2(LinkList L,int i,ElemType_D co, int exp){ //进行指数和系数的插入算法，用于加减法运算中的结果插入  
	LinkList p=L,temp;
	int j = 0;
	while (p && j < i-1){
		p = p->next;
		j++;
	}
	temp = (LinkList)malloc(sizeof(LNode));
	if (!temp) return OVERFLOW;
	temp->coe =co;  //以上均与ListINsert函数相同，不同点在这两个数据域需要进行赋值 
	temp->expo = exp;
	temp->next = p->next;
	p->next = temp;
	return OK;
} 
Status AddList(int num1, int num2, int num3){  //多项式加法 
	LinkList L1=array[num1]->next,L2=array[num2]->next,L3=array[num3];
	int len_l3=0;  //指示结果多项式长度 
	ClearList(L3);  //清空L3 
	while ((L1) &&(L2)){   //如果L1和L2都不为空 
		
		if (L1->expo == L2->expo){   //如果当前L1和L2指示的指数相同，则对系数进行加法 
			ListInsert_2(array[num3],len_l3+1,L1->coe+L2->coe,L1->expo);  //运算后插入到L3中 
			len_l3++;//L3长度加1
			L1 = L1->next;  //L1和L2均指向下一个节点 
			L2 = L2->next;
		}
		else if (L1->expo > L2->expo){  //如果当前L1指向的大于L2指示的指数，则把L1指示的插入L3中，并L1后移 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;//L3长度加1
			L1= L1->next;  //L1指向下一个节点 
		}
		else if(L1->expo < L2->expo){//如果当前L2指向的大于L1指示的指数，则把L2指示的插入L3中，并L2后移 
			ListInsert_2(array[num3],len_l3+1,L2->coe,L2->expo);
			len_l3++;  //L3长度加1 
			L2= L2->next;			
		}
	}
	if (!L1){   //L1为空 
			while (L2){   //把L2中剩余的都插入到L3中 
				ListInsert_2(array[num3],len_l3+1,L2->coe,L2->expo);
				len_l3++;//L3长度加1
				L2 = L2->next;  //L2 指向下一个节点 

			}
		}
	if (!L2){  //L2为空 
		while (L1){  //把L1中剩余的都插入到L3中 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;
			L1 = L1->next;
		}

	} 
	return OK;
}
Status MinusList(int num1, int num2, int num3){  //多项式减法 
	LinkList L1=array[num1]->next,L2=array[num2]->next,L3=array[num3];
	int len_l3=0;
	ClearList(L3);
	while ((L1) &&(L2)){
	
		if (L1->expo == L2->expo){//如果当前L1和L2指示的指数相同，则对系数进行减法 
			ListInsert_2(array[num3],len_l3+1,(L1->coe)-(L2->coe),L1->expo);
			len_l3++;
			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->expo > L2->expo){ //如果当前L1指向的大于L2指示的指数，则把L1指示的插入L3中，并把L1后移 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;
			L1= L1->next;
		}
		else if(L1->expo < L2->expo){//如果当前L2指向的大于L1指示的指数，则把L2指示系数取反的插入L3中，并把L2后移 
			ListInsert_2(array[num3],len_l3+1,-L2->coe,L2->expo);
			len_l3++;
			L2= L2->next;			
		}
	}
	if (!L1){//L1为空 
		while (L2){ //把L2中剩余的都插入到L3中 
			ListInsert_2(array[num3],len_l3+1,-L2->coe,L2->expo);
			len_l3++;
			L2 = L2->next;

		}
	
	}
	if (!L2){ //L2为空 
		while (L1){//把L1中剩余的都插入到L3中 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;
			L1 = L1->next;
		}

	}
	return OK;
}

int main ()
{
	

}