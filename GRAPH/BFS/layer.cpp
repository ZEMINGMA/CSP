#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+5;

int h[N],e[N],ne[N],idx;
int dis[N];
int p[N];
int n,m;
queue<int> q;


void add (int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


void bfs(int u)
{

    q.push(u);
    while(!q.empty()){
        int t=q.front();
        q.pop();

        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]==-1){
                q.push(j);
                dis[j]=dis[t]+1;
            }
        }
    }
    return;
}



int main()
{
    memset(h,-1,sizeof(h));
    memset(dis,-1,sizeof(dis));

    cin>>n>>m;

    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    dis[1]=0;
    bfs(1);

    cout<<dis[n];
    return 0;


}