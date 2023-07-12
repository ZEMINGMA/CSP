#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=105;
int n,m;
int g[N][N];
bool vis[N][N];
int dis[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

struct Node
{
    int x,y;
};

queue<Node> q;

void bfs(int x,int y)
{
    Node tt;
    tt.x=x,tt.y=y;
    vis[x][y]=true;
    q.push(tt);
    while(!q.empty()){
        Node t=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int xx=t.x+dx[i];
            int yy=t.y+dy[i];
            if (g[xx][yy]==0 && !vis[xx][yy])
            {
                Node t3;
                t3.x=xx;
                t3.y=yy;
                vis[xx][yy]=true;
                dis[xx][yy]=dis[t.x][t.y]+1;
                q.push(t3);
            }
            
        }
    }
}

int main()
{

    memset(vis,false,sizeof(vis));   
    memset(g,-1,sizeof(g));

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>g[i][j];
        }
    }

    bfs(1,1);
    cout<<dis[n][m];
    system("pause");
    return 0;
}
