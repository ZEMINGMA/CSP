#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


typedef struct Team
{
    int num;
    int a;
    int b;
    int c;
}Team;

Team team[6];
int mt_num;

int main()
{
    for(int i=0;i<6;++i){
        int num;
        cin>>num;
        team[i].num=num;
    }

    for(int i=0;i<6;++i){
        string str;
        cin>>str;
        if(str[0]=='1') team[i].a=1,mt_num++;
        if(str[1]=='1') team[i].b=1;
        if(str[2]=='1') team[i].c=1;
    }
    
    if(mt_num<2){
        cout<<"GG";
        return 0;
    }
}