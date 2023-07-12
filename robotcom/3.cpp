#include<iostream>
#include<string>
#include<map>
using namespace std;

string str;
map<int,int> face2num;
int sign=1;
int maxx;
int minn;
int i;

int get_num(){
    int num=0;
    while(isdigit(str[i])){
        num=num*10+str[i]-'0';
        i++;
    }
    return num;
}

void pro(){
    int len=str.length();

    for(i=0;i<len;){

        if(isdigit(str[i])){
            int num=get_num();
            if(str[i]=='d'){
                ++i;
                int fa=get_num();
                if(sign==1){
                    maxx+=num*fa;
                    minn+=num;
                }else{
                    maxx-=num;
                    minn-=num*fa;
                }
                face2num[fa]+=num;
            }

            else{
                maxx+=sign*num;
                minn+=sign*num;
            }
        }  

        if(str[i]=='d'){
            i++;
            int num=get_num();
            if(sign==1){
                maxx+=num;
                minn+=1;
            }else{
                maxx-=1;
                minn-=num;
            }

            face2num[num]+=1;
        }
        
        if(str[i]=='+') sign=1,++i;
        if(str[i]=='-') sign=-1,++i;


    }
}

int main()
{
    cin>>str;
    pro();
    for(auto i=face2num.begin();i!=face2num.end();++i){
        cout<<i->first <<" "<<i->second<<endl;
    }
    cout<<minn<<" "<<maxx;
    system("pause");
    return 0;

}