#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int n,k;
int a[maxn];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[k-1];
    return 0;
}