#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string ending="12345678x";
string str;
unordered_map<string,int> dis;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};


void bfs(){
    queue<string> q;
    q.push(str);
    dis[str]=0;

    while(!q.empty()){
        auto t=q.front();

        if(t == ending){
            cout<<dis[t];
            return ;
        }
        string tt=t;
        q.pop();
        int idx=t.find("x");
        int x=idx/3;
        int y=idx%3;

        for(int i=0;i<4;++i){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0 && xx <=2 && yy>=0 && yy<=2){
                swap(t[idx],t[xx*3+yy]);
                if(!dis.count(t)){
                    dis[t]=dis[tt]+1;
                    q.push(t);
                }
                swap(t[idx],t[xx*3+yy]);
            }
        }
    }
    cout<<-1;
}


int main()
{

    char ch;
    for(int i=0;i<9;++i){
        cin>>ch;
        str+=ch;
    }

    bfs();
    return 0;
}