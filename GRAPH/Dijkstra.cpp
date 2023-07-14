#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=15e4;

int h[N],e[N],ne[N],w[N],idx;
int d[N];
bool vis[N];
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii>> heap;

void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

int n,m;


int dij(int u){
    heap.push({0,1});

    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();


        int v=t.second,dis=t.first;
        if(vis[v]) continue;
        vis[v]=true;

        for(int i=h[v];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]>dis+w[i]){
                d[j]=dis+w[i];
                heap.push({d[j],j});
            }
        }
    }

    if(d[u]==0x3f3f3f3f) return -1;
    else return d[u];
}

int main()
{
    memset(h,-1,sizeof(h));

    memset(d,0x3f,sizeof(d));
    d[1]=0;

    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    int ans=dij(n);
    cout<<ans;

    return 0;
}