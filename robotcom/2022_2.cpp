#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e3+5;
unordered_map<int,int> last_ti;
int ti[maxn];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>ti[i];
    }

    for(int i=0;i<m;++i){
        int t,k;
        cin>>t>>k;
        for(int j=0;j<k;++j){
            int temp;
            cin>>temp;
            if(last_ti.count(temp)){
                if((t-last_ti[temp])<ti[temp]){
                    cout<<"Don't take "<<temp<<" at "<<t<<"!"<<endl;
                }
                else last_ti[temp]=t;
            }
            else
                last_ti[temp]=t;
        }
    }

    system("pause");
    return 0;
}