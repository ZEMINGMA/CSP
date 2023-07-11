#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=105;
struct  Node
{
    int x;
    int y;
};

int n,m;
int g[N][N];
int dis[N][N];
bool vis[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void bfs(int x,int y){
    queue<Node> q;
    Node node;
    node.x=x;
    node.y=y;
    q.push(node);
    vis[x][y]=true;

    while(!q.empty()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int xx=t.x+dx[i];
            int yy=t.y+dy[i];
            if(!vis[xx][yy] && g[xx][yy]==0){
                node.x=xx;
                node.y=yy;
                vis[xx][yy]=true;
                q.push(node);
                dis[xx][yy]=dis[t.x][t.y]+1;
            }
        }
    }
    cout<<dis[n][m];
}

int main(){
    cin>>n>>m;
    memset(g,-1,sizeof(g));

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>g[i][j];
        }
    }

    bfs(1,1);

    return 0;
}