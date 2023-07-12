#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Group
{
    int mt[2],gb[2],zh[2];
    int ow_num;
    int yt_num;
    int num;
    vector<int> ow;
    vector<int> yt;   
}g[150],gg;

struct Team
{
    int num;
    int mt,gb,zh;
}team[10];

int st=0;

void dfs(int x,Group gt)
{
    if(x==7){
        if(gt.ow_num>0 && gt.yt_num>0)
            if(gt.mt[0] && gt.mt[1])
            g[st++]=gt;
        return;
    }
    
    if(!team[x].num){
        dfs(x+1,gt);
        return;
    }

    for(int i=0;i<=1;++i){
        Group gtt=gt;
        gtt.mt[i]=gtt.mt[i]|team[x].mt;
        gtt.gb[i]=gtt.gb[i]|team[x].gb;
        gtt.zh[i]=gtt.zh[i]|team[x].zh;

        if(i==0){
            gtt.num+=team[x].num;
            gtt.ow_num+=team[x].num;
            gtt.ow.push_back(x);
        }
        else{
            gtt.num+=team[x].num;
            gtt.yt_num+=team[x].num;
            gtt.yt.push_back(x);
        }
        dfs(x+1,gtt);
    }
}

bool cmp(Group a,Group b){
    bool a1=a.zh[0]&&a.zh[1]&&a.gb[1]&&a.gb[0];
    bool b1=b.zh[0]&&b.zh[1]&&b.gb[0]&&b.gb[1];
    if(a1!=b1) return a1;

    bool a2=a.zh[0]&&a.zh[1];
    bool b2=b.zh[0]&&b.zh[1];
    if(a2!=b2) return a2;

    int a3=abs(a.ow_num-a.yt_num);
    int b3=abs(b.ow_num-b.yt_num);
    if(a3!=b3) return a3<b3;

    bool a4=(a.ow_num>=a.yt_num);
    bool b4=(b.ow_num>=b.yt_num);
    if(a4!=b4) return a4;

    return a.ow<b.ow;
}


int main()
{
    for(int i=1;i<=6;++i){
        cin>>team[i].num;
    }

    for(int i=1;i<=6;++i){
        string str;
        cin>>str;
        if(str[0]=='1') team[i].mt=1;
        if(str[1]=='1') team[i].gb=1;
        if(str[2]=='1') team[i].zh=1;
    }

    dfs(1,gg);
    if(st){
        sort(g,g+st,cmp);
    for(auto i=g[0].ow.begin();i!=g[0].ow.end();++i){
        if(i!=g[0].ow.end()-1)
            cout<<*i<<" ";
        else
            cout<<*i;
    }
    cout<<endl;
        for(auto i=g[0].yt.begin();i!=g[0].yt.end();++i){
        if(i!=g[0].yt.end()-1)
            cout<<*i<<" ";
        else
            cout<<*i;
        }
    }
    else cout<<"GG";



    system("pause");
    return 0;
}