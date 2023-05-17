#include<iostream>
using namespace std;


const int maxn=205;
int A[maxn];
int n,N;
int sum=0;

int main()
{
    cin>>n>>N;
    for(int i=1;i<=n;++i){
        cin>>A[i];
        sum+=(A[i]-A[i-1])*(i-1);
    }
    sum+=(N-A[n])*n;
    cout<<sum;
    system("pause");
    return 0;
}