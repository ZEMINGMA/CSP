#include<iostream>
#include<string.h>
using namespace std;
//N进制数的加法
////镜像数字
//判断回文数字
bool  Palindrome(int *ans,int len);

bool  Palindrome(int *ans,int len)
{
    for(int i=0;i<len/2;++i)
    {
        if(ans[i]!=ans[len-1-i]) return false;
    }
    return true;
}


int main()
{
    int N;
    char M[100];
    int len;//位数
    int i,j;
    int num[150];//存放镜像数字
    int ans[150];
    cin>>N;
    scanf("%s",M);
    //数字处理
    len=strlen(M);

    for(j=0;j<len;++j)
    {
        if(M[len-1-j]>='0'&&M[len-1-j]<='9')  num[j]=M[len-1-j]-'0';
        else if(M[len-1-j]>='a'&&M[len-1-j]<='f') num[j]=M[len-1-j]-'a'+10;
        else num[j]=M[len-1-j]-'A'+10;
    }

    //输出循环设置
    for( i=0;i<30;++i)
    {
        //N进制数的加法
        int count=0;//进位标志
        for(int k=0;k<len;++k)
        {
            //位数k，len-1-k，相加
            ans[k]=(num[k]+num[len-1-k]+count)%N;
            if((num[k]+num[len-1-k])+count>=N) count=1;
            else count=0;
            //结果存放入ans
        }
        ans[len]=count;
        if(count==1) len+=1;
        
        //判断回文数字
        if(Palindrome(ans,len)) 
        {
            cout<<"STEP="<<i+1<<endl;break;
        }
        else{
            for(int m=0;m<len;++m)
            {
                num[m]=ans[m];
            }
        }
    }
    //cout<<i<<endl;
    if(i>=30) cout<<"Impossible!"<<endl;
    system("pause");
    return 0;
}