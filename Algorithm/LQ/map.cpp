#include<iostream>
#include<map>
using namespace std;

map<string,int> mp;

int main()
{
    mp["a"]=1;
    mp["b"]=2;
    int n=3;

    for(int i=0;i<1;++i){
        string s;
        int x;
        cin>>s>>x;
        mp[s]=x;
    }
    mp.erase("a");
    for(auto i=mp.begin();i!=mp.end();++i)
        cout<<i->first<<":"<<i->second<<endl;
    map<string,int>::iterator ii;
    ii=mp.find("cde");
    if(ii==mp.end()) cout<<"not found"<<endl;
    else cout<<ii->first<<":"<<ii->second<<endl;
    system("pause");
    return 0;
}