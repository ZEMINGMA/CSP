#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int n,X,Y;
const int N=205;
typedef struct  Point
{
    int x,y,id;
    int  dis;
    bool operator < (const Point &t){
        if(dis!=t.dis) return dis<t.dis;
        return id<t.id;
    }
}Point;

Point pos[N];

int get_dis(int x,int y,int X,int Y){
    return pow( (x-X),2)+pow((y-Y),2);
}


int main()
{
    cin>>n>>X>>Y;
    for(int i=1;i<=n;++i){
        pos[i].id=i;
        cin>>pos[i].x>>pos[i].y;
        pos[i].dis=get_dis(X,Y,pos[i].x,pos[i].y);
    }
    sort(pos+1,pos+n+1);
    cout<<pos[1].id<<endl<<pos[2].id<<endl<<pos[3].id<<endl;
    system("pause");
    return 0;
}