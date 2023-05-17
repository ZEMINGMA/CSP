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