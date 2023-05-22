#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=1e3+5;

typedef struct Point{
    int x;
    int y;
    string type;
}Point;

Point p[maxn];
int n,m;

string judge(long long s1,long long s2,long long s3){
    bool flag=false;
    if(p[1].type=="A" && s1+s2*p[1].x+s3*p[1].y>0){
        flag=true;
        for(int i=1;i<=n;++i){
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y>0)
                continue;
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y<0)
                flag=false;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y<0)
                continue;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y>0)
                flag=false;
        }
    }

        if(p[1].type=="B" && s1+s2*p[1].x+s3*p[1].y<0){
        flag=true;
        for(int i=1;i<=n;++i){
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y>0)
                continue;
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y<0)
                flag=false;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y<0)
                continue;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y>0)
                flag=false;
        }
    }

     if(p[1].type=="A" && s1+s2*p[1].x+s3*p[1].y<0){
        flag=true;
        for(int i=1;i<=n;++i){
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y<0)
                continue;
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y>0)
                flag=false;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y>0)
                continue;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y<0)
                flag=false;
        }
    }

         if(p[1].type=="B" && s1+s2*p[1].x+s3*p[1].y>0){
        flag=true;
        for(int i=1;i<=n;++i){
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y<0)
                continue;
            if(p[i].type=="A" && s1+s2*p[i].x+s3*p[i].y>0)
                flag=false;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y>0)
                continue;
            if(p[i].type=="B" && s1+s2*p[i].x+s3*p[i].y<0)
                flag=false;
        }
    }

    if(flag) return "Yes";
    else return "No";
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>p[i].x>>p[i].y>>p[i].type;
    }

    for(int i=1;i<=m;++i){
        long long x1,x2,x3;
        cin>>x1>>x2>>x3;
        cout<<judge(x1,x2,x3)<<endl;
    }
    system("pause");
    return 0;
}