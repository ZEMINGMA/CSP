#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


map<int,int> m;
int n;
int mr=-2e9;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        int l,r;
        cin>>l>>r;
        m[l]=r;
    }
    for(auto i=m.begin();i!=m.end();i++){
        if(i->first>mr){
            
        }
    }


}