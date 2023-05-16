#include<iostream>
#include<unordered_map>
using namespace std;

int n,k;
int ans=0;
unordered_map<int,int> eq;


int main()
{
    cin>>n>>k;
    for(int i=0;i<k;++i){
        int left,right;
        cin>>left>>right;
        if(eq.count(right)==0 && right!=0 ) ans++;
        eq[left]=right;
    }
    cout<<ans;
    system("pause");
    return 0;
}