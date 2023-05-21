#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+2;

typedef struct Stu{
    int y;
    int result;
    bool operator < (const Stu &t){
        if(y!=t.y) return y<t.y;
        return result>t.result;
    }
}Stu;

Stu stu[N];
int s[N];
int m;
int cnt,cnt_max;
int y_m;
int main()
{
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>stu[i].y>>stu[i].result;
    }
    sort(stu+1,stu+m+1);

    for(int i=1;i<=m;++i){
        s[i]=s[i-1]+stu[i].result;
    }

    for(int i=1;i<=m;++i){
        cnt=0;
        int num1=i-1-s[i-1];
        int num2=s[m]-s[i-1];
        //cout<<num1<<" "<<num2<<endl;
        cnt=num1+num2;

        if(cnt>=cnt_max){
            cnt_max=cnt;
            y_m=stu[i].y;
        }
    }

    cout<<y_m;
    system("pause");
    return 0;
}