#include<iostream>
#include<cstring>
using namespace std;

const int N=1e6+5;
const int M=2e6+10;
int n;

int color[N];//-1 0 1
int h[N],e[M],ne[M],idx;
long long  cnt=0;


void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


void dfs(int u,int c){

    if(color[u]==-1){
        color[u]=c;
        if(c==1) cnt++;
        for(int i=h[u];i!=-1;i=ne[i]){
            if(color[e[i]]==-1)
                dfs(e[i],1-c);
        }
    }
    return;
}

int main()
{
    memset(h,-1,sizeof(h));
    memset(color,-1,sizeof(color));

    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }

    dfs(1,1);

    unsigned long  long  ans=cnt*(n-cnt)-n+1;
    cout<<ans;
    system("pause");
    return 0;   
}