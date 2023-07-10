#include<iostream>
using namespace std;
const int maxn=1e3+5;
int n,m;
int a[maxn];
int cnt=0;
int sum=0;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
        if(sum>m){
            sum=a[i];
            cnt++;
        }
    }

    cout<<cnt;
    return 0;
}