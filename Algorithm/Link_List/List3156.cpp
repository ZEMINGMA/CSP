#include <iostream>
using namespace std;
const int MAX=1e7;
typedef struct LNode{
    int num;
    struct LNode *next; 
}LNode,*LinkList;

LinkList Initialize(LinkList &L,int n);
int Search(LinkList &L);

LinkList Initialize(LinkList &L,int n){
    LNode *s;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    L->num=n;
    for(int i=0;i<n;i++){
        s=(LinkList)malloc(sizeof(LNode));
        cin>>s->num;
        L->next=s;
        L=s;
        cout<<"mzm is a pig"<<endl;
    }
    s->next=NULL;
    return L;
}


int Search(LinkList &L){
    int i;
    LNode*s;
    cin>>i;
    for(int j=0;j<i;j++){
     cout<<s->num<<"test"<<endl;
        s=L->next;
        L=s;
    }

    return s->num;

}

int arr[MAX];
int main()
{
    LinkList L;
    int n,m;
    cin>>n>>m;

    L=Initialize(L,n);
    
    for(int i=0;i<m;i++){
        arr[i]=Search(L);
    }

    for(int i=0;i<m;i++)
        cout<<arr[i]<<endl;
    system("pause");
    return 0;
}