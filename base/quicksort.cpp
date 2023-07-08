#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6;

void quick_sort(int a[],int l,int r){
    if(l>=r) return;

    //确定分界点
    int x=a[l+r>>1];
    int i=l,j=r;

    //双指针调节范围
    while(i<=j){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j) swap(a[i++],a[j--]);
    } 
    //递归处理子程序
    quick_sort(a,l,j);
    quick_sort(a,i,r);
}

int q[maxn];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    for(int i=0;i<n;++i){
        printf("%d ",q[i]);
    }
    system("pause");
    return 0;
}