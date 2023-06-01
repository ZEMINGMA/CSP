#include<iostream>
#include<iomanip>
using namespace std;
 
double f[16*5+1][1<<16];//[coin][state]
double p[16+1];
int  n,k;

double dp(double depth,int  coin,int  state,double cnt){
    if(f[coin][state]) return f[coin][state];//记忆化搜索
    if(coin>=cnt*k) return depth;//返回搜索的层数
    double s=0;

    //遍历所有的卡
    for(int i=0;i<n;++i){
        if((state>>i)&1)
            s+=p[i]*dp(depth+1,coin+1,state,cnt);
        else
            s+=p[i]*dp(depth+1,coin,state|(1<<i),cnt-1);
    }
    f[coin][state]=s;
    return s;
}

int  main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>p[i];
    
    printf("%.10lf",dp(0,0,0,n));
    system("pause");
    return 0;
}