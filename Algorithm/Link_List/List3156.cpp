#include <iostream>
using namespace std;
const int MAXN=1e7;
typedef struct LNode{                       //�������㶨��
    int num;
    struct LNode *next; 
}LNode,*LinkList;

LinkList Initialize(LinkList &L,int n);
int Search(LinkList L);

LinkList Initialize(LinkList &L,int n){          
    LNode *s;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    L->num=n;    
    LNode* temp;
    temp=(LinkList)malloc(sizeof(LNode));
    int flag=0;
    for(int i=0;i<n;i++){
        s=(LinkList)malloc(sizeof(LNode));
        cin>>s->num;
        if(flag==0){
            L->next=s;
            temp=s;
            flag=1;
        }
        else{
         temp->next=s;
         temp=s;              
        }                       //Lָ��ͷ��� ��Ӧ�øı�
       // cout<<"������ɵ��ɵ��ɵ��ɵ��"<<endl;
    }
    s->next=NULL;
    return L;
}


int Search(LinkList L){                            //wrong
    int idx;
    cin>>idx;                                       //�����ı��index
    LNode* temp;
    temp=(LinkList)malloc(sizeof(LNode));
    for(int j=0;j<idx;j++){
        temp=L->next;
        L=temp;
    }

    return temp->num;

}

int arr[MAXN];
LinkList L;
int n,m;
int main()
{

    cin>>n>>m;
    L=Initialize(L,n);     

    for(int i=0;i<m;i++)
        arr[i]=Search(L);
    
    for(int i=0;i<m;i++)
        cout<<arr[i]<<endl;
    system("pause");
    return 0;
}