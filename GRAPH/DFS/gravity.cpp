#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;


int n;
int h[N],e[M],ne[M],idx;
bool vis[N];

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int ans=N;

int dfs(int u){
    vis[u]=true;
    
    int sum=1,res=0;

    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!vis[j]){
            vis[j]=true;
            int t=dfs(j);
            sum+=t;
            res=max(res,t);
        }
    }
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}

int main()
{
    memset(h,-1,sizeof(h));
    cin>>n;

    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }

    dfs(1);
    cout<<ans;
    return 0;
}