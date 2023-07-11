#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
int h[N],e[M],ne[M],idx;
int n,m;
int color[N];//-1 0 1


void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool dfs(int u,int c)
{
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int b=e[i];
        if(color[b]==c){
            return false;
        }else if(color[b]==-1){
            if(!dfs(b,1-c)){
                return false;
            }
        }
    }
    return true;
}


int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }

    memset(color,-1,sizeof(color));

    bool flag=true;
    for(int i=1;i<=n;++i){
        if(color[i]==-1){
            if(!dfs(i,0)){
                cout<<"No";
                return 0;
            }
        }
    }

    cout<<"Yes";
    return 0;

}