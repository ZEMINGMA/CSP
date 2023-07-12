#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;

unordered_map<int,int> last_time;
unordered_map<int,int> diff;

int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int t;
        cin>>t;
        diff[i]=t;
    }

    for(int i=1;i<=m;++i){
        int t,k;
        cin>>t>>k;
        for(int j=1;j<=k;++j){
            int temp;
            cin>>temp;
            if(!last_time.count(temp))
                last_time[temp]=t;
            else if((t-last_time[temp])<diff[temp]){
                cout<<"Don't take "<<temp<<" at "<<t<<"!"<<endl;
            }else{
                last_time[temp]=t;
            }
        }
    }

    return 0;
}