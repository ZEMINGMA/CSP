#include<iostream>
using namespace std;
const int maxn=501;

int n,m,L;
int A[maxn][maxn];
int h[maxn];


int main()
{
    cin>>n>>m>>L;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>A[i][j];
            h[A[i][j]]++;
        }
    }

    for(int i=0;i<L;++i)
        cout<<h[i]<<" ";
    system("pause");
    return 0;
}