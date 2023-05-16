#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;
int n,L,S;
int ans=0;
int sum=0;
typedef struct Tree{
    int x;
    int y;
}Tree;

Tree tree[N];
int B[105][105];
int main()
{
    cin>>n>>L>>S;
    for(int i=0;i<n;++i){
        cin>>tree[i].x>>tree[i].y;
    }

    for(int i=S;i>=0;--i)
        for(int j=0;j<=S;++j){
            cin>>B[i][j];
            sum+=B[i][j];
        }

    for(int i=0;i<n;++i){
        int x=tree[i].x;
        int y=tree[i].y;
        if(x+S>L||y+S>L) continue;
        
        int cnt=0;
        for(int j=0;j<n;++j){
            if(tree[j].x-x>=0 && tree[j].x -x<=S && tree[j].y-y>=0 && tree[j].y-y<=S){
                 if(B[tree[j].x-x][tree[j].y-y]==1) cnt++;
                 else cnt-=1e3;
            }
        }
        if(cnt==sum) ans++;  
    } 

    cout<<ans;
    system("pause");
    return 0;

}