#include<iostream>
#include<ctype.h>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    char put1;
    int flag=0;
    int a,b,num=0;
    
    cin>>put1;
    while(put1!='@')
    {
        while(put1!='.'&&isdigit(put1))
        {
            num=num*10+put1-'0';
            cin>>put1;
            flag=1;
        }
        while(flag==1)
        {
            s.push(num);
           //cout<<"num:"<<num<<endl;
            
            flag=0;
            num=0;
        }
            
        cin>>put1;
        while(put1!='@'&&!(isdigit(put1))) {
            
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            //cout<<"mzm is pig2·ûºÅÊÇ"<<put1<<endl;
            //cout<<a<<endl;
            //cout<<b<<endl;
            switch(put1)
            {
                case '+':s.push(a+b);break;
                case '-':s.push(b-a);break;
                case '*':s.push(b*a);break;
                case '/':s.push(b/a);break;
            }
        cin>>put1;
        }
   
    }
    cout<<s.top()<<endl;
    system("pause");
    return 0;
}