#include<iostream>

using namespace std;

int n,m;
int cnt=0;
int sum=0;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int p;
        cin>>p;
        if((sum+p)>m) sum=p,cnt++;
        else sum+=p;
    }
    
    cout<<cnt;
    return 0;
}