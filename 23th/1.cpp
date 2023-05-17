#include<iostream>
using namespace std;

const int maxn=1e5+5;
int b[maxn];
int n;
int sum_max;
int sum_min;


int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>b[i];
        if(b[i]==b[i-1]){
            sum_max+=b[i];
            sum_min+=0;
        }
        else{
            sum_max+=b[i];
            sum_min+=b[i];
        }
    }

    cout<<sum_max<<endl<<sum_min;
    system("pause");
    return 0;
}