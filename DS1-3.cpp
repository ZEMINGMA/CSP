#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<math.h>
#define MAX 100

typedef struct Node{
    float c;//系数
    int f;//指数
    struct Node *next;
    struct Node *pre;
}node,*linklist;

typedef struct Matrix
{
    float c;
    int f;
}Tuple;

typedef struct{
    Tuple data[MAX+1];
}TSMatrix;

linklist Insertlist(linklist L,float c1,int f1);
TSMatrix Caculate(linklist L1,linklist L2,char sign);
void PrintMatrix(TSMatrix M);

linklist Insertlist(linklist L,float c1,int f1)
{
    node*s;
    node*p=(linklist)malloc(sizeof(node));
    p=L->next;
    if(L->next==NULL)//直接进行尾插法
    {
        s=(linklist)malloc(sizeof(node));
        s->c=c1;
        s->f=f1;
        s->next=L->next;
        s->pre=L;
        L->next=s;
    }
    else
    {
        while(p!=NULL)
        {
            //如果当前元素大于f，且不是最后一个结点，则p指向下一个
            if(p->f>f1)
            {
                if(p->next==NULL)//是最后一个，则插入
                {
                    s=(linklist)malloc(sizeof(node));
                    s->c=c1;
                    s->f=f1;
                    s->next=p->next;
                    s->pre=p;
                    p->next=s;
                    break;
                }
                else p=p->next;
            }
            //当前结点p小于f，则在前面插入
            else
            {
                s=(linklist)malloc(sizeof(node));
                s->c=c1;
                s->f=f1;
                p->pre->next=s;
                s->pre=p->pre;
                s->next=p;
                p->pre=s;
                break;
            }

        }
    
    
    }
    return L;
}

TSMatrix Caculate(linklist L1,linklist L2,char sign)
//依次比较最大的指数，如果大于，则存储到结果矩阵SUM，如果等于则进行运算后存储到结果矩阵
{
    node *p1,*p2;//分别指向L1、L2
    int i=0;
    TSMatrix M;
    p1=(linklist)malloc(sizeof(node));
    p2=(linklist)malloc(sizeof(node));
    p1=L1->next;
    p2=L2->next;
     for(int j=0;j<=MAX;j++)
    {
        M.data[j].c=0;
        M.data[j].f=0;
    }
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->f>p2->f)//依次比较最大的指数，如果大于，则存储到结果矩阵M
        {
            M.data[i].c=p1->c;
            M.data[i].f=p1->f;
            p1=p1->next;
            ++i;
        }
        //如果等于则进行运算后存储到结果矩阵
        else if(p1->f==p2->f)
        {
            if(sign=='+')//系数不为0则存储
            {
                if((p1->c+p2->c)!=0)
                {
                    M.data[i].c=p1->c+p2->c;
                    M.data[i].f=p1->f;
                    ++i;
                    
                }
                p1=p1->next;
                p2=p2->next;

            }
            else{
                if((p1->c-p2->c)!=0)//系数不为0则存储
                {
                    M.data[i].c=p1->c-p2->c;
                    M.data[i].f=p1->f;
                    ++i;
                    
                }
                p1=p1->next;
                p2=p2->next;
            }
        }
        else{
            M.data[i].c=p2->c;
            M.data[i].f=p2->f;
            p2=p2->next;
            ++i;
        }
    }
    //如果L1遍历完，则链接L2
    if(p1==NULL)
        while(p2!=NULL)
        {
            M.data[i].c=p2->c;
            M.data[i].f=p2->f;
            p2=p2->next;
            ++i;
        }
    else
        while(p1!=NULL)
        {
            M.data[i].c=p1->c;
            M.data[i].f=p1->f;
            p1=p1->next;
            ++i;
        }
        M.data[i].c=0;
    return M;

}

void PrintMatrix(TSMatrix M)
{
    //系数不为0，则打印
    int i=0;
    while(M.data[i].c!=0)
    {
        printf("%g %d ",M.data[i].c,M.data[i].f);
        ++i;
    }
    if(M.data[0].c==0)
    {
        printf("0 0");
    }
}

int main()
{
    float c;//系数
    int f;//指数
    linklist L1,L2;//构建两个链表，从大到小存储
    TSMatrix result;//用于存储计算结果

    L1=(linklist)malloc(sizeof(node));
    L2=(linklist)malloc(sizeof(node));
    L1->next=NULL;
    L2->next=NULL;
    int len1,len2;//记录链表长度
    int i=0;
    int j=0;//用来遍历结构体数组
    char ch[MAX];
    char sign;
    int flag1=0,flag2=0;//用来判断输入的数字是整数还是负数

    gets(ch);//读取字符串  -1 1 4.4 2 -1.2 9 - -6 -3 5.4 2 7.8 15

    for(i=0,j=0;ch[i]!='+'&&!(ch[i]=='-'&&!(isdigit(ch[i+1])));++i,++j)
    {
        float num1=0;
        float num2=0;
        flag1=0,flag2=0;
        if(ch[i]=='-') //判断是否是负数
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        //如果是小数，则进行处理
        if(ch[i]=='.')
        {
            ++i;
            int count=0;
            while(isdigit(ch[i]))//读到空格退出
            {
                num2=num2*10+ch[i]-'0';
                ++i;
                ++count;
            }
            while (count!=0)
            {
                num2/=10;
                --count;
            }
            
            num1+=num2;
            //cout<<num1<<endl;
        }

        if(flag1==1) num1=0-num1;//如果是负数，则num1取相反数，且置0
        
        c=num1;
        flag1=0,num1=0,num2=0;
        //系数处理完毕
        ++i;
       
        if(ch[i]=='-') //判断是否是负数
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        if(flag1==1) num1=0-num1;//如果是负数，则num1取相反数，且置0
        f=(int)num1;
        flag1=0,num1=0,num2=0;
        L1=Insertlist(L1,c,f);
        //指数处理完毕
              
    }

    sign=ch[i];
    len1=j;
    i+=2;

    for(j=0;ch[i]!=0;++i,++j)
    {
        float num1=0;
        float num2=0;
        flag1=0,flag2=0;
        if(ch[i]=='-') //判断是否是负数
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        //如果是小数，则进行处理
        if(ch[i]=='.')
        {
            ++i;
            int count=0;
            while(isdigit(ch[i]))//读到空格退出
            {
                num2=num2*10+ch[i]-'0';
                ++i;
                ++count;
            }
            while (count!=0)
            {
                num2/=10;
                --count;
            }
            
            num1+=num2;
            //cout<<num1<<endl;
        }

        if(flag1==1) num1=0-num1;//如果是负数，则num1取相反数，且置0
        
        c=num1;
        flag1=0,num1=0,num2=0;
        //系数处理完毕
        ++i;
       
        if(ch[i]=='-') //判断是否是负数
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        if(flag1==1) num1=0-num1;//如果是负数，则num1取相反数，且置0
        f=(int)num1;
        flag1=0,num1=0,num2=0;
        L2=Insertlist(L2,c,f);
        //指数处理完毕
              
    }
    len2=j;
    
    result=Caculate(L1,L2,sign);
    PrintMatrix(result);

    system("pause");
    return 0;
}