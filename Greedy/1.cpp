#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


map<int,int> m;
int n;
int cnt=0;
int mr=-2e9;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        int l,r;
        cin>>l>>r;
        if(!m.count(l))
             m[l]=r;
        else 
            m[l]=min(r,m[l]);
    }

    for(auto i=m.begin();i!=m.end();++i){
        if(i->first>mr){
            mr=i->second;
            cnt++;
        }else{
            mr=min(mr,i->second);
        }
    }
    cout<<cnt;
    return 0;
}