#include<iostream>
#include<cstring>
using namespace std;

const int N=1e3+5;
const int M=1e5+5;

int h[N],e[M],ne[M],idx;
int n1,n2,m;
int cnt;
int match[N];
bool vis[N];



void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool find_(int u){
    
    for(int i=h[u];i!=-1;i=ne[i]){
        int t=e[i];
        if(!vis[t]){
            vis[t]=true;
            if(match[t]==-1 || find_(match[t])){
                match[t]=u;
                return true;
            }

        }
    }
    return false;
}



int main()
{
    memset(h,-1,sizeof(h));
    memset(match,-1,sizeof(match));

    cin>>n1>>n2>>m;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }

    for(int i=1;i<=n1;++i){
        memset(vis,false,sizeof(vis));
        if(find_(i))
            cnt++;
    }
    cout<<cnt;
    return 0;
}