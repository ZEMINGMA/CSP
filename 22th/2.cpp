#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=605;
int n,L,r,t;
int A[N];
int ans=0;
int sum[N][N];



int main()
{
    cin>>n>>L>>r>>t;


    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x;
            cin>>x;
            sum[i][j]=x+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x1=max(1,i-r),y1=max(1,j-r);
            int x2=min(n,i+r),y2=min(n,j+r);
            int total=sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1];

            int cnt=(x2-x1+1)*(y2-y1+1)*t;
            if(total<=cnt) ans++;
        }
    }

    cout<<ans;
    system("pause");
    return 0;
}