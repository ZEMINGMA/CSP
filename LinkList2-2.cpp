//Your code begin.
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<ctype.h>

typedef struct node
{
	int coef;	//系数
	int exp;		//指数
	int layer;		//该栈当前所处的地址（层数），建议从0开始，layer<5。用于判断栈满情况
	struct node* next;
    struct node* pre;
}node, * pstack; 		//node用于声明结点，pstack用于声明栈指针

int  create_node(pstack S1,pstack S2);
void print_stack(pstack S);//打印最终栈


int  create_node(pstack S1,pstack S2)
{
    int num=0;
    node *p=(pstack)malloc(sizeof(node));
    S1=p;
    node *temp_node;
    int i=0;
    for(i=0;(scanf("%d",&num)==1);++i)
    {
        if(i%2==0)                          //coef
        {
        temp_node=(pstack)malloc(sizeof(node));
        temp_node->layer=i/2;
        temp_node->coef=num;
        }
        else 
        { 
        temp_node->exp=num;                     //exp
        p->next=temp_node;
        temp_node->pre=p;
        p=temp_node;
        }
    } 
    getchar();
    temp_node->next=NULL;
    S1=S1->next;    
    if(i>10){
        printf("Full!");
        return 0;
    }

    node* q=(pstack)malloc(sizeof(node));
    S2=q;
    node *temp_node2;
    for(i=0;(scanf("%d",&num)!=EOF);++i)
    {
        if(i%2==0)                          //coef
        {
        temp_node2=(pstack)malloc(sizeof(node));
        temp_node2->layer=i/2;
        temp_node2->coef=num;
        }
        else 
        { 
        temp_node2->exp=num;                     //exp
        q->next=temp_node2;
        temp_node2->pre=q;
        q=temp_node2;
        }
    } 
    temp_node2->next=NULL;
    S2=S2->next;    
    if(i>10){
        printf("Full!");
        return 0;
    }

    node *top=NULL;
    node *temp;
    node *p2=S1;
    node *q2=S2;
    while(p2!=NULL||q2!=NULL){
        temp=(pstack)malloc(sizeof(node));
             if(p2==NULL) temp->coef=q2->coef,temp->exp=q2->exp,temp->pre=top,temp->next=NULL,top=temp,q2=q2->next;
        else if(q2==NULL) temp->coef=p2->coef,temp->exp=p2->exp,temp->pre=top,temp->next=NULL,top=temp,p2=p2->next;
        else if(q2->exp<p2->exp)temp->coef=q2->coef,temp->exp=q2->exp,temp->pre=top,temp->next=NULL,top=temp,q2=q2->next;
        else if(p2->exp<q2->exp)temp->coef=p2->coef,temp->exp=p2->exp,temp->pre=top,temp->next=NULL,top=temp,p2=p2->next;
    }

    while(top!=NULL)
    {
        printf("%d %d ",top->coef,top->exp);
        top=top->pre;
    }

    return 0;
}

void print_stack(pstack S)
{
    node *p=S;
    while(p!=NULL)
    {
        printf("%d %d ",p->coef,p->exp);
        p=p->next;
    }
    printf("\n");
}






int main()
{
    pstack S1,S2;
    create_node(S1,S2);
    //print_stack(S1);
    //print_stack(S2);
    system("pause");
    return 0;
}
//Your code end.

