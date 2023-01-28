#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

//构造n个字符串
//按首字母和位置排序
//输出尾字符，和p

//确定排序后的首字母序列
//相对位置不变


int main()
{
    string str1,str2,letter;

    char a;
    int temp;
    int n,p;
    
    cin>>n;//长度
    cin>>str1;
    cin>>p;//位置
    str2=str1;//str2 :begin letters
    sort(str2.begin(),str2.end());

    //从首字母开始，访问后标记‘1’
    a=str1[p-1];
    letter[0]=a;
    temp=str2.find(a);
    str2[temp]='1';
    for(int i=n-1;i>0;--i)
    {
        letter[i]=str1[temp];
        a=letter[i];
        temp=str2.find(a);
        str2[temp]='1';
    }

    for(int j=0;j<n;++j)
    cout<<letter[j];
    
    system("pause");
}