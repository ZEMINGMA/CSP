#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=3e5+5;
int n;
int x;
int sum=0;
int f[maxn];
int a[31];

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }

    int m=sum-x;

    for(int i=1;i<=n;++i)
        for(int j=m;j>=a[i];j--)
            f[j]=max(f[j],f[j-a[i]]+a[i]);
    cout<<sum-f[m];
    system("pause");
    return 0;
}