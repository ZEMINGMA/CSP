#include<iostream>
#include<queue>
using namespace std;
const int MAXN=1e8;

int n,m;
int uid[MAXN];
int idx;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>uid[i];
    for(int i=1;i<=m;++i)
        cin>>idx,cout<<uid[idx]<<endl;
    system("pause");
    return 0;
}


