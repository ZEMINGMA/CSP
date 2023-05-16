#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

const int N=1e3+5;
int n;//days
int region_risk_num[N];
int info_num[N];

typedef struct Info{
    int date;
    int user;
    int region;
}Info;

vector<Info> info[N];
vector<int> risk_user[N];
unordered_map<int,int> start_time;
unordered_map<int,int> end_time;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>region_risk_num[i]>>info_num[i];

        int risk_region;
        for(int j=0;j<region_risk_num[i];++j){
            cin>>risk_region;
            if(start_time.count(risk_region)==0||end_time[risk_region]+1<i)//no risk or interrupt
                start_time[risk_region]=i;
            end_time[risk_region]=i+6;//update certainly
        }

        for(int j=0;j<info_num[i];++j){

            int  di,ui,ri;
            Info temp_info;
            cin>>di>>ui>>ri;
            temp_info.date=di;
            temp_info.user=ui;
            temp_info.region=ri;

            if(start_time.count(ri)==0 || end_time[ri]<i) continue;
                info[i].push_back(temp_info);
        }

        for(int j=max(0,i-6);j<=i;++j)
            for(int k=0;k<info[j].size();++k){
                if(info[j][k].date >i-7 && end_time[info[j][k].region]>=i && info[j][k].date >= start_time[info[j][k].region])
                    risk_user[i].push_back(info[j][k].user);
            }  
    }

    for(int i=0;i<n;++i){
        sort(risk_user[i].begin(),risk_user[i].end());
        risk_user[i].erase(unique(risk_user[i].begin(),risk_user[i].end()),risk_user[i].end());
        cout<<i<<" ";
        for(int j=0;j<risk_user[i].size();++j)
            cout<<risk_user[i][j]<<" ";
        cout<<endl;
    }
    system("pause");
    return 0;
    
}