#include<iostream>
#include <string>
using namespace std;

int main()
{
    string str[]={"Mon is happy 8!","Tue is happier 8!","Wed is the happiest 8!","Thu is tired 8!","Fri is unknown 8!"};
    string str2="徐梦茜把我的环境弄乱了！";
    string str3="xmx is pig";
    string str4="xmx is  a pig";
    for(int i=0;i<5;i++)
    {
       cout<<str[i] << endl;
    }
    cout<<str2<<endl;
    cout<<str3<<endl;
    system("pause") ;
    return 0;
}
