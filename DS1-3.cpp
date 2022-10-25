#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct {
    float c;   
}Tuple;

typedef struct{
    Tuple data[MAX+1];    //用于对应x的指数
    int mu,nu,tu;
}TSMatrix;


TSMatrix ADD(TSMatrix M1,TSMatrix M2,char sign);//将相同指数的系数进行计算
int cmp(const void *a, const void *b);//配合qsort排序的函数
void Print(TSMatrix SUM,int *arr,int length);//打印最终数组



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
    
    return *(int *)b - *(int *)a; //由大到小排序
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
    float ci;//系数
    int e;//指数
    char ch,sign;
    int arr[MAX];//用来统计指数，进行qsort
    int length=0;//用来记录有效指数的个数



    do
    {

        if(scanf("%f %d",&ci,&e)==2)
        M1.data[e].c=ci;//创建系数矩阵M1
       // printf("%f %d\n",ci,e );
        //cout<<ci<<" "<<e<<endl;

        getchar();
        sign=getchar();

    }while(sign!='+'&&sign!='-');

    printf("xmxsz");
    

    do
    {
        if(scanf("%f %d",&ci,&e)==2)
        M2.data[e].c=ci;//创建系数矩阵M2
        ch=getchar();
    }while(ch!='\n');
    // M1.data[0].c=3;M1.data[1].c=1;
    // M2.data[1].c=-2;
    // sign='-';

    SUM=ADD(M1,M2,sign);//调用ADD

    //统计有效指数
    for(int i=0;i<MAX;i++)
    {
        if(SUM.data[i].c!=0)
        {
            
            arr[length]=i;
            ++length;
        }
    }
    qsort(arr, length, sizeof(int), cmp);//对有效指数进行降序排列

    //打印SUM
    Print(SUM,arr,length);

    system("pause");

    return 0;
}