#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,k;
int b[N];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        int t,c;
        cin>>t>>c;
        int l=max(0,t-k-c+1);
        int r=max(0,t-k);
        b[l]++;
        b[r+1]--;
    }

    for(int i=1;i<N;++i)
        b[i]+=b[i-1];
    
    for(int i=0;i<m;++i){
        int q;
        cin>>q;
        cout<<b[q]<<endl;
    }
    system("pause");
    return 0;
}