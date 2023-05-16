#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
vector<double> a;
double D;
double sum;
double average;


int main()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    average=sum/n;

    for(int i=0;i<n;++i){
        D+=pow((a[i]-average),2);
    }
    D=D/n;

    for(int i=0;i<n;++i){
        cout<<setprecision(10)<<(a[i]-average)/sqrt(D)<<endl;
    }
    system("pause");
    return 0;
}