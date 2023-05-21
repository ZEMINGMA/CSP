#include<iostream>
#include<algorithm>
using namespace std;

int n;
int y;

int main()
{

    cin>>n;
    
    for(int i=1;i<=n;++i){
        int w,score;
        cin>>w>>score;
        y+=w*score;
    }

    y=max(0,y);

    cout<<y;
    system("pause");
    return 0;
}