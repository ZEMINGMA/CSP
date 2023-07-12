#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<numeric>
#include<algorithm>
using namespace std;


int st_num;

struct Group{
    int mt[2],gb[2],zh[2];
    int num;
    int ow_num;
    int yt_num;
    vector<int> ow;
    vector<int> yt;
}group[1000],t;

struct Team{
    int mt,gb,zh;
    int num;
}team[10];


bool cmp(Group a, Group b) {
    // Rule 1: Prefer solutions where each group has at least one commander and one engineer.
    bool aSatisfiesRule1 = a.zh[0] && a.zh[1] && a.gb[0] && a.gb[1];
    bool bSatisfiesRule1 = b.zh[0] && b.zh[1] && b.gb[0] && b.gb[1];
    if (aSatisfiesRule1 != bSatisfiesRule1) return aSatisfiesRule1;
    
    // Rule 2: If Rule 1 is not satisfied, prefer solutions where each group has at least one commander.
    bool aSatisfiesRule2 = a.zh[0] && a.zh[1];
    bool bSatisfiesRule2 = b.zh[0] && b.zh[1];
    if (aSatisfiesRule2 != bSatisfiesRule2) return aSatisfiesRule2;

    
    int a_diff=abs(a.ow_num-a.yt_num);
    int b_diff=abs(b.ow_num-b.yt_num);
    if(a_diff!=b_diff) return a_diff<b_diff;
    
    bool a4=(a.ow_num>=a.yt_num);
    bool b4=(b.ow_num>=b.yt_num);
    if(a4!=b4) return a4;


    // Rule 5: If Rule 4 is not satisfied or multiple solutions satisfy Rule 4, prefer the solution with minimum "Owen" team id sum.
    return a.ow<b.ow;
}

void dfs(int x,Group g){
    if(x>6){
        if(g.ow.size()>0 && g.yt.size()>0)
            if(g.mt[0] && g.mt[1]){
                group[st_num++]=g;
            }
        return ;
    }

    if(team[x].num==0){
        dfs(x+1,g);
        return;
    }

    for(int i=0;i<=1;++i){
        Group gg=g;
        gg.mt[i]=gg.mt[i]|team[x].mt;
        gg.gb[i]=gg.gb[i]|team[x].gb;
        gg.zh[i]=gg.zh[i]|team[x].zh;
        gg.num+=team[x].num;
        if(i==0){
            gg.ow_num+=team[x].num;
            gg.ow.push_back(x);
        }
        else{
            gg.yt_num+=team[x].num;
            gg.yt.push_back(x);
        }
        dfs(x+1,gg);
    }
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
    dfs(1,t);
    if(st_num){
        sort(group,group+st_num,cmp);
        for(auto i=group[0].ow.begin();i!=group[0].ow.end();++i){
            if(i!=group[0].ow.end()-1)
            cout<<*i<<" ";
            else
            cout<<*i;
        }
        cout<<endl;
        for(auto i=group[0].yt.begin();i!=group[0].yt.end();++i){
         if(i!=group[0].yt.end()-1)
            cout<<*i<<" ";
            else
            cout<<*i;
        }
    }
    else
        cout<<"GG";

    system("pause");
    return 0;
}