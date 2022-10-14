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

typedef char ElemType;   //Ԫ������ 
typedef int Status;
typedef double ElemType_D;  //����ʽԪ������ 

typedef struct LNode{
	ElemType_D coe;  //ϵ�� 
	int expo;  //ָ�� 
	ElemType data;  //�������� 
	struct LNode* next;
}LNode;   //�ڵ�ṹ�� 
struct ARRAY_S{
	double co;  //ϵ�� 
	int exp;  //ָ�� 
}sz[100];   //����ʽ�ṹ������ 
typedef LNode* LinkList;  //�ڵ�ָ������ 
int Length;   //���� 
int num;    //ȫ�ֱ���������ָʾ��ǰ���������Ա�ı�� 
LinkList array[11]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};//���������飬�洢��ͷָ�� 

void menu(void);   //�˵����� 
void exp_print(int exp); //����ʽ�����ָ����ʽ�������� 
void coe_print(ElemType_D coe,int flag);//����ʽ�����ϵ����ʽ�������� 
void setListnum(int n); //19 ���ñ���� 
void visit (ElemType x); //visit�������� 
double abs_D(double x);  //��������abs���� 
Status Compare (ElemType a,ElemType b);  //compare���� 
Status InitList(LinkList L);  //1 ��ʼ���� 
void DestroyList(LinkList *L);  //2 ���ٱ� 
Status ClearList(LinkList L);  //3 ��ձ� 
Status ListEmpty(LinkList L);  //4 �жϿձ� 
int ListLength(LinkList L);  //5 ��� 
Status GetElem(LinkList L,int i, ElemType *e);  //6 ��ȡԪ�� 
Status LocateElem(LinkList L, ElemType e, Status(Compare)());  //7 ����Ԫ�� 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);  //8  ���ǰ�� 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);  //9 ��ú�� 
Status ListInsert(LinkList L, int i, ElemType e);   //10 ����Ԫ�� 
Status ListDelete(LinkList L, int i, ElemType *e);   //11 ɾ��Ԫ�� 
Status ListTraverse(LinkList L, void(visit)());    //12 ���� 
Status CreatList(int n);    //21 ��������ʽ���Ա� 
Status ShowList(int num);    //22 �������ʽ 
Status AddList(int num1, int num2, int num3);   //23 ����ʽ�ӷ� 
Status MinusList(int num1, int num2, int num3);  //24 ����ʽ���� 

void exp_print(int exp ){   //�������ʽ�е�x^ 
	if (exp==1){
		printf("x");
	} 
	else if (exp!=0) cout<<"x^"<<exp; 
}
void coe_print(ElemType_D coe,int flag){  //�������ʽ�е�ϵ������Ҫ����ǰ�������������ϵ��Ϊ1��-1�����  
	int flag2 = 0; //flag2 ָʾ 1 Ϊ - 0Ϊ+ 
	if (flag){  //flag=1 Ϊ��һ��ϵ����Ϊ0��Ԫ�� 
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
int cmp(const void *a, const void *b){   //sort������ cmp 
	return (*(ARRAY_S *)a).exp > (*(ARRAY_S *)b).exp ? 1 : -1;
}
double abs_D(double x){    //double���͵�abs���� 
	if (x>=0) return x; else return (-x);
}
void setListnum(int n){  //���ñ�� 
	num = n;   //numΪȫ�ֱ��� 
}
void visit (ElemType x){  //visit���� 
	printf("%c",x);  //������� 
}
Status Compare (ElemType a,ElemType b){   //compare���������ڲ��ұȽ� 
	if (a==b) return OK; else return ERROR;
}
Status InitList(LinkList L){   //��ʼ���� 
	(L) = (LinkList)malloc(sizeof(LNode));  //��̬���ٿռ� 
	if(!(L)) return OVERFLOW;   //�ж���� 
	(L)->next = NULL;  //ָʾNULL 
	array[num] = L;   //��������������� 
	return OK;
}

void DestroyList(LinkList L){  //���ٱ� 
	LinkList p = L;    //��ͷ 
	while (p){   //ֻҪ��Ϊ�� 
		p = (L)->next;   //ָ����һ���ڵ� 
		free(L);  //�ͷſռ� 
		(L) = p;    // ָ����һ�� ��p�� 
	}
}

Status ClearList(LinkList L){  //��ձ� 
	LinkList ptemp, p;
	if(!L) return ERROR;   //���Ѿ�Ϊ���򷵻�ERROR 
	ptemp = L->next;   //ָ���һ���ڵ� 
	while(ptemp){   //ֻҪ��Ϊnull 
		p = ptemp->next;   //ָ����һ���ڵ� 
		free(ptemp);  //�ͷſռ� 
		ptemp = p;    
	}
	L->next = NULL;  //��ͷ��next��ֵΪNULL 
	return OK;
}

Status ListEmpty(LinkList L){  //�жϱ�� 
	if(L != NULL && L->next != NULL)
		return FALSE;  //��Ϊ�շ���FALSE 
	else return TRUE;  //Ϊ�շ���TRUE 
}
int ListLength(LinkList L){ //��� 
	LinkList p;
	int i = 0;  //ʹ��i���� 
	if (L){
		i = 0;    //����ֵ 0 
		p = L->next;  //ָ���һ���ڵ� 
		while (p){  //ֱ�� pΪ�գ�����β 
			i++;   //���ȼ�1 
			p = p->next;
		}	
	}
	return i;  //���ر� 
}

Status GetElem(LinkList L,int i, ElemType *e){  //���Ԫ�� 
	int j = 1;  //ʹ��j���� 
	LinkList p = L->next;  //ָ���һ��Ԫ�� 
	if (i>ListLength(L)) return ERROR;  //�ж�i�Ƿ�Ϸ� 
	while (p && j<i){   //ѭ������Ϊp��Ϊ����j<i 
		j++;
		p = p->next;
	}
	*e =  p->data; //�ѻ�õ�Ԫ����e���� 
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType,ElemType)){  //����Ԫ�� 
	int i;
	int t;
	LinkList p;
	if (L){   //��Ϊ�� 
		i = 0;   //������ֵ 
		p = L->next;  //ָ���һ���ڵ� 
		while (p){  //ֻҪ��ǰ�ڵ㲻Ϊnull 
			i++;   //λ�ü�1 
			if (!Compare(e,p->data)) p = p->next; else return i;  //���ҵ�����λ��i ����ǰ ����Ҫ���ҵ�Ԫ����ָ����һ���ڵ� 
		}

	}
	else return ERROR; //�����β��û�в��ҵ��򷵻�ERROR 
	if(!p) return ERROR;
}
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e){//���ǰ�� 
	LinkList p, temp;
	p = L->next;  //��һ��Ԫ�� 
	if (p->data != cur_e){  //��ǰԪ�ز��ǵĵ�һ��Ԫ�� ������ǵ�һ��Ԫ�ز�ִ��if��ֱ�ӷ���ERROR 
		while (p->next){
			temp = p->next; //ʹ��temp��ȡ ��һ��Ԫ�� 
			if (temp->data == cur_e){  //��һ��Ԫ����cur_e��ǰԪ�ؼ�Ϊcur_e��ǰ�� 
				*pre_e = p->data;   //ʹ��pre_e����ǰ�� 
				return OK;
			}
			p = temp;
		}
	}
	 return ERROR;  // ��һ��Ԫ�ص�ʱ�򷵻�ERROR 
}
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e){  //��ú�� 
	LinkList p, temp;
	if (L){   
		p = L->next;
		while (p && p->next){
			temp = p->next;  //ʹ��temp�����һ��Ԫ�� 
			if (p->data == cur_e){  // ��ǰԪ����cur_e����һ��Ԫ�ؼ�Ϊcur_e�ĺ�� 
				*next_e = temp->data;  //ʹ��next_e���غ�� 
				return OK;
			}
			p = temp;	
		}
	}
	return ERROR;  //���һ��Ԫ�ص�ʱ���򷵻�ERROR 
}
Status ListInsert(LinkList L, int i, ElemType e){ //����Ԫ�� 
	LinkList p = L, temp;
	int j = 0;  //ʹ��j��i��ǰһ��λ�� 
	while (p && j < i-1){   //���ҵ�i��ǰһ��λ�� 
		p = p->next;
		j++;
	}

	temp = (LinkList)malloc(sizeof(LNode));  //���ٿռ� 
	if (!temp) return OVERFLOW;   //��ֹ��� 
	temp->data = e;  //��ֵ 
	temp->next = p->next;  //���ӽ��� 
	p->next = temp;//���ӽ��� 
	return OK;
}

Status ListDelete(LinkList L, int i, ElemType *e){  //ɾ��Ԫ�� 
	LinkList temp, pre = L;
	int j = 1;  //j��i��ǰһ��λ�� 
	while (pre->next && j<i){
		pre = pre ->next;
		j++;
	}
	if (!pre->next || j>i) return ERROR;
	temp = pre->next;   //�������ӱ� 
	pre->next = temp->next;  //�������ӱ� 
	*e = temp->data;  //ʹ��e����ɾ����Ԫ�� 
	free(temp);  //�ͷſռ� 
	return OK;
}
Status ListTraverse(LinkList L, void(visit)(ElemType)){  //������ 
	LinkList p;
	if(!L) return ERROR;  //��Ϊ���򷵻�ERROR 
	else p = L->next;  //ָ���һ��Ԫ�� 
	while (p){    //ֻҪû����β 
		visit(p->data);  //���Ԫ�� 
		p = p->next;   //ָ����һ�� 
	}
	printf("\n");
	return OK;
}
Status CreatList(int n,int numm){   //��������ʽ�� 

	LinkList p = array[numm], temp;
	int i=0,j=0;

	qsort(sz,100,sizeof(sz[0]),cmp);//����ָ��Ϊ�ؼ��ֽ����������� 

	while(i<n){
		temp = (LinkList)malloc(sizeof(LNode));  //���ٿռ� 
		if (!temp) return OVERFLOW;  //��ֹ��� 
		while(sz[i].exp==sz[i+1].exp){  //���кϲ�ͬ���� 
			sz[i+1].co+=sz[i].co;
			i++;
		}
		temp->coe = sz[i].co;//�������ϵ�� 
		temp->expo = sz[i].exp;//�������ָ��  
		temp->next = p->next; // ͷ�巨���� 
		p->next = temp;	
		i++;
	}

	return OK;
}
Status ShowList(int num){  //�������ʽ  
	LinkList p=array[num];
	printf("��Ҫ�鿴�Ķ���ʽ���£�\n"); 
	int flag_1=1, flag_2 = 0;
	if (!p->next){   //������Ϊ0����� 
		printf("0\n");
		return OK;
	}
	p=p->next;   
	while((p->coe ==0)&&p->next){  //���ϵ��Ϊ0�������ֱ������ 
		p=p->next;
	}
	if (!p->next && p->coe ==0){  //�����һ��ϵ��Ϊ0��û�к�����0�˳� 
		printf("0\n");
		return OK;
	}
	coe_print(p->coe,1);  //����coe_print�������������ϵ���������ʱflagΪ1��ָʾ���ǵ�һ������ 
	exp_print(p->expo);  //����exp_print�������������ָ����� 
	p=p->next;  //��һ�� 
	while (p){

		while ((p->coe==0)&& p->next){
			p=p->next;    //ͬ���ж�ϵ���Ƿ�Ϊ0 
		}
		if (!p->next && p->coe ==0) break;  //ͬ���ж��Ƿ�ϵ��Ϊ0��û�к��� 
		coe_print(p->coe,0); //���ϵ����flag=0��ָʾ�ⲻ�ǵ�һ�����  
		exp_print(p->expo);   //���ָ�� 
		p=p->next;  //��һ�� 
	}
	printf("\n");
	return OK;
}
Status ListInsert_2(LinkList L,int i,ElemType_D co, int exp){ //����ָ����ϵ���Ĳ����㷨�����ڼӼ��������еĽ������  
	LinkList p=L,temp;
	int j = 0;
	while (p && j < i-1){
		p = p->next;
		j++;
	}
	temp = (LinkList)malloc(sizeof(LNode));
	if (!temp) return OVERFLOW;
	temp->coe =co;  //���Ͼ���ListINsert������ͬ����ͬ������������������Ҫ���и�ֵ 
	temp->expo = exp;
	temp->next = p->next;
	p->next = temp;
	return OK;
} 
Status AddList(int num1, int num2, int num3){  //����ʽ�ӷ� 
	LinkList L1=array[num1]->next,L2=array[num2]->next,L3=array[num3];
	int len_l3=0;  //ָʾ�������ʽ���� 
	ClearList(L3);  //���L3 
	while ((L1) &&(L2)){   //���L1��L2����Ϊ�� 
		
		if (L1->expo == L2->expo){   //�����ǰL1��L2ָʾ��ָ����ͬ�����ϵ�����мӷ� 
			ListInsert_2(array[num3],len_l3+1,L1->coe+L2->coe,L1->expo);  //�������뵽L3�� 
			len_l3++;//L3���ȼ�1
			L1 = L1->next;  //L1��L2��ָ����һ���ڵ� 
			L2 = L2->next;
		}
		else if (L1->expo > L2->expo){  //�����ǰL1ָ��Ĵ���L2ָʾ��ָ�������L1ָʾ�Ĳ���L3�У���L1���� 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;//L3���ȼ�1
			L1= L1->next;  //L1ָ����һ���ڵ� 
		}
		else if(L1->expo < L2->expo){//�����ǰL2ָ��Ĵ���L1ָʾ��ָ�������L2ָʾ�Ĳ���L3�У���L2���� 
			ListInsert_2(array[num3],len_l3+1,L2->coe,L2->expo);
			len_l3++;  //L3���ȼ�1 
			L2= L2->next;			
		}
	}
	if (!L1){   //L1Ϊ�� 
			while (L2){   //��L2��ʣ��Ķ����뵽L3�� 
				ListInsert_2(array[num3],len_l3+1,L2->coe,L2->expo);
				len_l3++;//L3���ȼ�1
				L2 = L2->next;  //L2 ָ����һ���ڵ� 

			}
		}
	if (!L2){  //L2Ϊ�� 
		while (L1){  //��L1��ʣ��Ķ����뵽L3�� 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;
			L1 = L1->next;
		}

	} 
	return OK;
}
Status MinusList(int num1, int num2, int num3){  //����ʽ���� 
	LinkList L1=array[num1]->next,L2=array[num2]->next,L3=array[num3];
	int len_l3=0;
	ClearList(L3);
	while ((L1) &&(L2)){
	
		if (L1->expo == L2->expo){//�����ǰL1��L2ָʾ��ָ����ͬ�����ϵ�����м��� 
			ListInsert_2(array[num3],len_l3+1,(L1->coe)-(L2->coe),L1->expo);
			len_l3++;
			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->expo > L2->expo){ //�����ǰL1ָ��Ĵ���L2ָʾ��ָ�������L1ָʾ�Ĳ���L3�У�����L1���� 
			ListInsert_2(array[num3],len_l3+1,L1->coe,L1->expo);
			len_l3++;
			L1= L1->next;
		}
		else if(L1->expo < L2->expo){//�����ǰL2ָ��Ĵ���L1ָʾ��ָ�������L2ָʾϵ��ȡ���Ĳ���L3�У�����L2���� 
			ListInsert_2(array[num3],len_l3+1,-L2->coe,L2->expo);
			len_l3++;
			L2= L2->next;			
		}
	}
	if (!L1){//L1Ϊ�� 
		while (L2){ //��L2��ʣ��Ķ����뵽L3�� 
			ListInsert_2(array[num3],len_l3+1,-L2->coe,L2->expo);
			len_l3++;
			L2 = L2->next;

		}
	
	}
	if (!L2){ //L2Ϊ�� 
		while (L1){//��L1��ʣ��Ķ����뵽L3�� 
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