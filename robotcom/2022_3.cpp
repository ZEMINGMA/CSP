#include<iostream>
#include<algorithm>
#include<cctype>
#include<map>
#include<string>
using namespace std;

string str;
map<int,int> face_num;
int min_num;
int max_num;
int sign=1;
int i=0;

int get_num(){
    int num=0;
    while(isdigit(str[i])){
        num=num*10+str[i]-'0';
        i++;
    }
    return num;
}


void process(){
    while(i<str.length()){


        if(str[i]=='d' && (i==0 || !isdigit(str[i-1])) ){
            i++;
            int face=get_num();
            face_num[face]+=1;

            if(sign==1){
                max_num+=face;
                min_num+=1;
            }
            else{
                max_num-=1;
                min_num-=face;
            }
        }

        if(str[i]=='+'){
            sign=1;
            i++;
        }
        if(str[i]=='-'){
            sign=-1;
            i++;
        }

        if(isdigit(str[i])){
            int temp=get_num();
            if(str[i]=='d'){
                i++;
                int face=get_num();
                face_num[face]+=temp;

                if(sign==1){
                    max_num+=temp*face;
                    min_num+=temp;
                }
                else{
                    max_num-=temp;
                    min_num-=temp*face;
                }
            }
            else{
                if(sign==1){
                    max_num+=temp;
                    min_num+=temp;
                }
                else{
                    max_num-=temp;
                    min_num-=temp;
                }
            }
        }
    }
}

int main()
{
    cin>>str;
    process();
    for(auto it=face_num.begin();it!=face_num.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<min_num<<" "<<max_num<<endl;
    system("pause");
    return 0;
}