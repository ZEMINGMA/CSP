#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=1e5+5;

int n,m;
unordered_map<int ,int> val;
vector<int> all;
int a[maxn];
int sum[maxn];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int x,c;
        cin>>x>>c;
        all.push_back(x);
        val[x]+=c;
    }

    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());

    for(int i=0;i<all.size();++i){
        a[i]=val[all[i]];
    }
    
    sum[0]=a[0];
    for(int i=1;i<all.size();++i){
        sum[i]=sum[i-1]+a[i];   
    }

    for(int i=0;i<m;++i){
        int l,r;
        cin>>l>>r;

        l=lower_bound(all.begin(),all.end(),l)-all.begin();
        r=upper_bound(all.begin(),all.end(),r)-all.begin()-1;

        if(l>r)
            cout<<0<<endl;
        else if(l!=0)
            cout<<sum[r]-sum[l-1]<<endl;
        else
            cout<<sum[r]<<endl;
    }
    system("pause");
    return 0;

}   