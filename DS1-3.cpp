#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct {
    float c;   
}Tuple;

typedef struct{
    Tuple data[MAX+1];    //���ڶ�Ӧx��ָ��
    int mu,nu,tu;
}TSMatrix;


TSMatrix ADD(TSMatrix M1,TSMatrix M2,char sign);//����ָͬ����ϵ�����м���
int cmp(const void *a, const void *b);//���qsort����ĺ���
void Print(TSMatrix SUM,int *arr,int length);//��ӡ��������



TSMatrix ADD(TSMatrix M1,TSMatrix M2,char sign)
{
    TSMatrix SUM;
    memset(SUM.data,0,sizeof(SUM.data));
    int i=0;
    while(i<=10)
    {
        if(sign=='-')
        SUM.data[i].c=M1.data[i].c-M2.data[i].c;
        if(sign=='+')
        SUM.data[i].c=M1.data[i].c+M2.data[i].c;
        ++i;
    }
    return SUM;
    
}

int cmp(const void *a, const void *b)
{
    
    return *(int *)b - *(int *)a; //�ɴ�С����
}

void Print(TSMatrix SUM,int *arr,int length)
{
    int i=0;
    for(i=0;i<length;i++)
    {
        printf("%f %d ",SUM.data[arr[i]].c,arr[i]);
    }


}

int main()
{
    //qsort(a, 1000, sizeof(int), cmp);
    TSMatrix M1,M2,SUM;
    memset(M1.data,0,sizeof(M1.data));
    memset(M2.data,0,sizeof(M2.data));
    float ci;//ϵ��
    int e;//ָ��
    char ch,sign;
    int arr[MAX];//����ͳ��ָ��������qsort
    int length=0;//������¼��Чָ���ĸ���



    do
    {

        if(scanf("%f %d",&ci,&e)==2)
        M1.data[e].c=ci;//����ϵ������M1
       // printf("%f %d\n",ci,e );
        //cout<<ci<<" "<<e<<endl;

        getchar();
        sign=getchar();

    }while(sign!='+'&&sign!='-');

    printf("xmxsz");
    

    do
    {
        if(scanf("%f %d",&ci,&e)==2)
        M2.data[e].c=ci;//����ϵ������M2
        ch=getchar();
    }while(ch!='\n');
    // M1.data[0].c=3;M1.data[1].c=1;
    // M2.data[1].c=-2;
    // sign='-';

    SUM=ADD(M1,M2,sign);//����ADD

    //ͳ����Чָ��
    for(int i=0;i<MAX;i++)
    {
        if(SUM.data[i].c!=0)
        {
            
            arr[length]=i;
            ++length;
        }
    }
    qsort(arr, length, sizeof(int), cmp);//����Чָ�����н�������

    //��ӡSUM
    Print(SUM,arr,length);

    system("pause");

    return 0;
}