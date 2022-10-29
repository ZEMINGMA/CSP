#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<math.h>
#define MAX 100

typedef struct Node{
    float c;//ϵ��
    int f;//ָ��
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
    if(L->next==NULL)//ֱ�ӽ���β�巨
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
            //�����ǰԪ�ش���f���Ҳ������һ����㣬��pָ����һ��
            if(p->f>f1)
            {
                if(p->next==NULL)//�����һ���������
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
            //��ǰ���pС��f������ǰ�����
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
//���αȽ�����ָ����������ڣ���洢���������SUM�������������������洢���������
{
    node *p1,*p2;//�ֱ�ָ��L1��L2
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
        if(p1->f>p2->f)//���αȽ�����ָ����������ڣ���洢���������M
        {
            M.data[i].c=p1->c;
            M.data[i].f=p1->f;
            p1=p1->next;
            ++i;
        }
        //�����������������洢���������
        else if(p1->f==p2->f)
        {
            if(sign=='+')//ϵ����Ϊ0��洢
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
                if((p1->c-p2->c)!=0)//ϵ����Ϊ0��洢
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
    //���L1�����꣬������L2
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
    //ϵ����Ϊ0�����ӡ
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
    float c;//ϵ��
    int f;//ָ��
    linklist L1,L2;//�������������Ӵ�С�洢
    TSMatrix result;//���ڴ洢������

    L1=(linklist)malloc(sizeof(node));
    L2=(linklist)malloc(sizeof(node));
    L1->next=NULL;
    L2->next=NULL;
    int len1,len2;//��¼������
    int i=0;
    int j=0;//���������ṹ������
    char ch[MAX];
    char sign;
    int flag1=0,flag2=0;//�����ж�������������������Ǹ���

    gets(ch);//��ȡ�ַ���  -1 1 4.4 2 -1.2 9 - -6 -3 5.4 2 7.8 15

    for(i=0,j=0;ch[i]!='+'&&!(ch[i]=='-'&&!(isdigit(ch[i+1])));++i,++j)
    {
        float num1=0;
        float num2=0;
        flag1=0,flag2=0;
        if(ch[i]=='-') //�ж��Ƿ��Ǹ���
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        //�����С��������д���
        if(ch[i]=='.')
        {
            ++i;
            int count=0;
            while(isdigit(ch[i]))//�����ո��˳�
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

        if(flag1==1) num1=0-num1;//����Ǹ�������num1ȡ�෴��������0
        
        c=num1;
        flag1=0,num1=0,num2=0;
        //ϵ���������
        ++i;
       
        if(ch[i]=='-') //�ж��Ƿ��Ǹ���
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        if(flag1==1) num1=0-num1;//����Ǹ�������num1ȡ�෴��������0
        f=(int)num1;
        flag1=0,num1=0,num2=0;
        L1=Insertlist(L1,c,f);
        //ָ���������
              
    }

    sign=ch[i];
    len1=j;
    i+=2;

    for(j=0;ch[i]!=0;++i,++j)
    {
        float num1=0;
        float num2=0;
        flag1=0,flag2=0;
        if(ch[i]=='-') //�ж��Ƿ��Ǹ���
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        //�����С��������д���
        if(ch[i]=='.')
        {
            ++i;
            int count=0;
            while(isdigit(ch[i]))//�����ո��˳�
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

        if(flag1==1) num1=0-num1;//����Ǹ�������num1ȡ�෴��������0
        
        c=num1;
        flag1=0,num1=0,num2=0;
        //ϵ���������
        ++i;
       
        if(ch[i]=='-') //�ж��Ƿ��Ǹ���
        {
            flag1=1;
            ++i;
        }
        while(isdigit(ch[i]))
        {
            num1=num1*10+ch[i]-'0';
            ++i;
        }
        if(flag1==1) num1=0-num1;//����Ǹ�������num1ȡ�෴��������0
        f=(int)num1;
        flag1=0,num1=0,num2=0;
        L2=Insertlist(L2,c,f);
        //ָ���������
              
    }
    len2=j;
    
    result=Caculate(L1,L2,sign);
    PrintMatrix(result);

    system("pause");
    return 0;
}