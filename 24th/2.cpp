#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=1e5+5;
typedef long long LL;


LL n,N;
LL r;
LL A[maxn];
LL step;
LL f,g;
LL last;
LL err;

/*
首先对f分段 因为在[Ai,Ai+1)中恒为i
在每一个f段中继续考虑对g分段
每一个g分段一定有r个整数点（向下取整函数性质）

特别考虑地是考虑一个f段的最后一个g段的时候 不一定恰好完全重合
有可能g段跨越过两个f段 所以需要分类讨论
*/
int main()
{
    cin>>n>>N;
    r=N/(n+1);

    for(int i=1;i<=n;++i){
        cin>>A[i];
    }
    A[n+1]=N;

    for(int i=0;i<=n;++i){
        f=i;
        for(int j=A[i];j<A[i+1];j+=step){
            g=j/r;
            last=min(g*r+r-1,A[i+1]-1);
            step=last-j+1;
            err+=step*abs(f-g);
        }
    }
    cout<<err;
    system("pause");
    return 0;
}