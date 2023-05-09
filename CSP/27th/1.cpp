#include<iostream>
using namespace std;

int n,m;//number of problem,the chioce of each problem
int c[21];//auxiliary array
int a[21];
int b[21];
int remainder[21];
int main()
{
    cin>>n>>m;
    c[0]=1;
    remainder[0]=0;

    for(int i=1;i<=n;++i){
        cin>>a[i];
        c[i]=c[i-1]*a[i];
        remainder[i]=m%c[i];
        b[i]=(remainder[i]-remainder[i-1])/c[i-1];
        cout<<b[i]<<" ";
    }
    system("pause");
    return 0;
}
