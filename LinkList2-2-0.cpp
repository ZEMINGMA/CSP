#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<ctype.h>


typedef struct node
{
	int coef;	//系数
	int exp;		//指数
	int layer;		//该栈当前所处的地址（层数），建议从0开始，layer<5。用于判断栈满情况
	struct node* next;
}node, * pstack; 		//node用于声明结点，pstack用于声明栈指针


pstack create_1(pstack L1);//建立链式栈L1
pstack create_2(pstack L2);//建立链式栈L2
pstack push(pstack L1, pstack L2);//根据exp大小压栈
void print_stack(pstack final_stack);//打印final_stack

pstack create_1(pstack L1)
{
    int coef,exp;
    int layer=0;
    while(scanf("%d %d",&coef,&exp)==2)//建立链表L1
        {
            node *s=(pstack)malloc(sizeof(node));
            s->coef=coef;
            s->exp=exp;
            s->layer=layer;//设置layer
            if(L1->next==NULL) L1->next=s,s->next=NULL;//用头插法建立链表
            else
            {
                s->next=L1->next;
                L1->next=s;
            }
            ++layer;
        }
        getchar();
    return L1;
}//L1建立终止,scanf(%d)会跳过字符读入数字



pstack create_2(pstack L2)
{
    int coef,exp;
    int layer=0;
    do{
        if(scanf("%d %d",&coef,&exp)==2)//读入coef和exp
        //建立链表L1
        {
            //printf("xmxsz");
            node *s=(pstack)malloc(sizeof(node));
            s->coef=coef;
            s->exp=exp;
            s->layer=layer;//设置layer
            if(L2->next==NULL) L2->next=s,s->next=NULL;//用头插法建立链表
            else
            {
                s->next=L2->next;
                L2->next=s;
            }
            ++layer;
            //printf("%d %d",s->coef,s->exp);
        }
        //printf("%d %d",L2->next->coef,L2->next->exp);
    }while(getchar()!='\n');//L2建立终止,scanf(%d)会跳过字符读入数字
    return L2;
}

pstack push(pstack L1, pstack L2)//两个链式栈按照exp由大到小入栈
{

    pstack final_stack = (pstack)malloc(sizeof(node));//用于存储链接后的链式栈
    final_stack->next = NULL;
    node *p=L1->next,*s=L2->next;//指针p、s分别指向两个结点，进行大小比较
    pstack r = final_stack;
    node *_space;//开辟新的链式栈空间
    while(p!=NULL&&s!=NULL)
    {
        if(p->exp>s->exp)//比较两个链式的第一个结点exp的大小，大的结点入栈
        {
            _space=(pstack)malloc(sizeof(node));
            _space->coef=p->coef;
            _space->exp=p->exp;
            p=p->next;
            r->next=_space;//使用尾插法
            r=_space;
        }
        else
        {
            _space=(pstack)malloc(sizeof(node));
            _space->coef=s->coef;
            _space->exp=s->exp;
            s=s->next;
            r->next=_space;//使用尾插法
            r=_space;
        }
        
        
    }
    r->next=p?p:s;//将剩余的结点链接上final_stack
    
    return final_stack;
}

void print_stack(pstack final_stack)
{

    node *s=final_stack->next;
    while(s!=NULL)
    {
        printf("%d %d ",s->coef,s->exp);
        //printf("\n layer: %d",s->layer);
        s=s->next;
    }
}

int main()
{
    
    pstack L1=(pstack)malloc(sizeof(node));//初始化L1、L2
    pstack L2=(pstack)malloc(sizeof(node));
    pstack final_stack=(pstack)malloc(sizeof(node));
    L1->next=NULL;
    L2->next=NULL;
    final_stack->next=NULL;

    L1=create_1(L1);
    //print_stack(L1);
    //printf("%d \n",L1->next->layer);
    if(L1->next->layer>4) {printf("Full!");system("pause");return 0;}

    L2=create_2(L2);
    //print_stack(L2);
    //printf("%d ",L2->next->layer);
    if(L2->next->layer>4) {printf("Full!");system("pause");return 0;}
    
    final_stack=push(L1,L2);
    print_stack(final_stack);
    
    system("pause");
    return 0;

}