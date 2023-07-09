#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6;
int n,q;
int a[maxn];

//二分模板 找右侧
int start_(int x,int l,int r){
    while(l<r){
        int mid=l+r>>1;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
}

//二分模板 找左侧
int end_(int x,int l,int r){
    while(l<r){
        int mid=l+r+1>>1;
        if(a[mid]<=x) l=mid;
        else r=mid-1;
    }
    return l;
}

int main()
{
    cin>>n>>q;
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    while (q--)
    {
        int k;
        cin>>k;
        if(a[start_(k,0,n-1)]!=k)
            cout<<"-1 -1"<<endl;
        else
            cout<<start_(k,0,n-1)<<" "<<end_(k,0,n-1)<<endl;
    }

    system("pause");
    return 0;
}