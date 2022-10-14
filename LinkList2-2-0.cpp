#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<ctype.h>


typedef struct node
{
	int coef;	//ϵ��
	int exp;		//ָ��
	int layer;		//��ջ��ǰ�����ĵ�ַ���������������0��ʼ��layer<5�������ж�ջ�����
	struct node* next;
}node, * pstack; 		//node����������㣬pstack��������ջָ��


pstack create_1(pstack L1);//������ʽջL1
pstack create_2(pstack L2);//������ʽջL2
pstack push(pstack L1, pstack L2);//����exp��Сѹջ
void print_stack(pstack final_stack);//��ӡfinal_stack

pstack create_1(pstack L1)
{
    int coef,exp;
    int layer=0;
    while(scanf("%d %d",&coef,&exp)==2)//��������L1
        {
            node *s=(pstack)malloc(sizeof(node));
            s->coef=coef;
            s->exp=exp;
            s->layer=layer;//����layer
            if(L1->next==NULL) L1->next=s,s->next=NULL;//��ͷ�巨��������
            else
            {
                s->next=L1->next;
                L1->next=s;
            }
            ++layer;
        }
        getchar();
    return L1;
}//L1������ֹ,scanf(%d)�������ַ���������



pstack create_2(pstack L2)
{
    int coef,exp;
    int layer=0;
    do{
        if(scanf("%d %d",&coef,&exp)==2)//����coef��exp
        //��������L1
        {
            //printf("xmxsz");
            node *s=(pstack)malloc(sizeof(node));
            s->coef=coef;
            s->exp=exp;
            s->layer=layer;//����layer
            if(L2->next==NULL) L2->next=s,s->next=NULL;//��ͷ�巨��������
            else
            {
                s->next=L2->next;
                L2->next=s;
            }
            ++layer;
            //printf("%d %d",s->coef,s->exp);
        }
        //printf("%d %d",L2->next->coef,L2->next->exp);
    }while(getchar()!='\n');//L2������ֹ,scanf(%d)�������ַ���������
    return L2;
}

pstack push(pstack L1, pstack L2)//������ʽջ����exp�ɴ�С��ջ
{

    pstack final_stack = (pstack)malloc(sizeof(node));//���ڴ洢���Ӻ����ʽջ
    final_stack->next = NULL;
    node *p=L1->next,*s=L2->next;//ָ��p��s�ֱ�ָ��������㣬���д�С�Ƚ�
    pstack r = final_stack;
    node *_space;//�����µ���ʽջ�ռ�
    while(p!=NULL&&s!=NULL)
    {
        if(p->exp>s->exp)//�Ƚ�������ʽ�ĵ�һ�����exp�Ĵ�С����Ľ����ջ
        {
            _space=(pstack)malloc(sizeof(node));
            _space->coef=p->coef;
            _space->exp=p->exp;
            p=p->next;
            r->next=_space;//ʹ��β�巨
            r=_space;
        }
        else
        {
            _space=(pstack)malloc(sizeof(node));
            _space->coef=s->coef;
            _space->exp=s->exp;
            s=s->next;
            r->next=_space;//ʹ��β�巨
            r=_space;
        }
        
        
    }
    r->next=p?p:s;//��ʣ��Ľ��������final_stack
    
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
    
    pstack L1=(pstack)malloc(sizeof(node));//��ʼ��L1��L2
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