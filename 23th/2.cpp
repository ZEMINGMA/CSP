#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
const int M=1e4+5;

int a[N];
int cnt[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]>a[i-1]){
            cnt[a[i-1]+1]++;
            cnt[a[i]+1]--;
        }
    }

    int sum=0,res=0;
    for(int i=1;i<=M;++i){
        sum+=cnt[i];
        res=max(res,sum);
    }
    cout<<res;

    system("pause");
    return 0;
}
