#include<iostream>
#include<unordered_set>
using namespace std;
const int N=55;
const int M=260;
int n,k;
int a[N];
bool vis[M];
unordered_set<int> s;


void dfs(int u,int sum){
    if(u==5){
        s.insert(sum);
        return;
    }

    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=true;
            dfs(u+1,sum+a[i]);
            vis[i]=false;
        }
    }

}

int main()
{
    cin>>n>>k;

    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    dfs(1,0);

    for(int i=1;i<=k;++i){
        int m;
        cin>>m;
        bool check=true;
        for(int j=1;j<=m;++j){
            int x;
            cin>>x;
            if(!s.count(x*4)) check=false;
        }
        if(!check){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }


    return 0;
}