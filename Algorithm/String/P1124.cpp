#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

//����n���ַ���
//������ĸ��λ������
//���β�ַ�����p

//ȷ������������ĸ����
//���λ�ò���


int main()
{
    string str1,str2,letter;

    char a;
    int temp;
    int n,p;
    
    cin>>n;//����
    cin>>str1;
    cin>>p;//λ��
    str2=str1;//str2 :begin letters
    sort(str2.begin(),str2.end());

    //������ĸ��ʼ�����ʺ��ǡ�1��
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