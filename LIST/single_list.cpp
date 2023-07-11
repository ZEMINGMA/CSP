#include<iostream>

using namespace std;
const int N=1e5+5;

int h,e[N],ne[N],idx;
int m;
void add(int x)
{
    e[idx]=x;
    ne[idx]=h;
    h=idx++;
}

void dele(int k){
    if(k==-1){
        h=ne[h];
    }else{
        ne[k]=ne[ne[k]];
    }
}

void add_k(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}

int main()
{
    h=-1;
    idx=0;
    cin>>m;
    
    for(int i=0;i<m;++i){
        char ch;
        cin>>ch;
        if(ch=='H'){
            int x;
            cin>>x;
            add(x);
        }else if(ch=='D'){
            int k;
            cin>>k;
            dele(k-1);
        }else{
            int x,k;
            cin>>k>>x;
            add_k(k-1,x);
        }
    }

    for(int i=h;i!=-1;i=ne[i])
        cout<<e[i]<<" ";

    return 0;
}