#include<iostream>
#include<string>
#include<vector>
using namespace std;


int n;
bool col[10],dg[10],udg[10];
vector<string> str;

void dfs(int u)
{
    if(u>n){
        for(int i=0;i<n;++i){
            cout<<str[i]<<endl;
        }
        cout<<endl;
        return ;
    }


    for(int i=1;i<=n;++i){
        if(!col[i] && !dg[u+i] && !udg[u-i+n]){
            str[u-1][i-1]='Q';
            col[i]=true;
            dg[u+i]=true;
            udg[u+n-i]=true;
            dfs(u+1);
            str[u-1][i-1]='.';
            col[i]=dg[u+i]=udg[u-i+n]=false;
        }
    }
}


int main()
{
    cin>>n;
    str.resize(n, string(n,'.'));
    dfs(1);
    return 0;
}