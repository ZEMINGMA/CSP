#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
const int N=405;

int n,m,q;

typedef struct Role{
    int op_num;
    int type_num;
    int so_num;
    unordered_set<string> op;
    unordered_set<string> type;
    unordered_set<string> so;
}Role;

typedef struct User{
    string name;

    int group_num;
    unordered_set<string> group;
    string op;
    string type;
    string so;
}User;
User user;

unordered_map<string,Role> role;
unordered_map<string,vector<string>> relation;//前者为用户（用户名）  后者为被授权的角色

int main()
{
    cin>>n>>m>>q;

    //读入角色
    for(int i=1;i<=n;++i){
        string name;
        cin>>name;

        cin>>role[name].op_num;
        for(int j=1;j<=role[name].op_num;++j){
            string op;
            cin>>op;
            role[name].op.insert(op);
        }
        
        cin>>role[name].type_num;
        for(int j=1;j<=role[name].type_num;++j){
            string type;
            cin>>type;
            role[name].type.insert(type);
        }
        
        cin>>role[name].so_num;
        for(int j=1;j<=role[name].so_num;++j){
            string so;
            cin>>so;
            role[name].so.insert(so);
        }
    }

    for(int i=1;i<=m;++i){
        string role_name;
        cin>>role_name;
        int ns;
        cin>>ns;
        string ug,obj_name;
        for(int j=1;j<=ns;++j){
            cin>>ug>>obj_name;
            relation[obj_name].push_back(role_name);
        }
    }

    for(int i=1;i<=q;++i){
        cin>>user.name;
        cin>>user.group_num;
        for(int j=1;j<=user.group_num;++j){
            string group;
            cin>>group;
            user.group.insert(group);
        }
        cin>>user.op;
        cin>>user.type;
        cin>>user.so;

        vector<string> temp=relation[user.name];//先查用户名对应的角色权限
        bool found=false;

        for(auto it =temp.begin();it!=temp.end();++it){

            if(role[*it].op.count(user.op)==0 && role[*it].op.count("*")==0)
                continue;

            if(role[*it].type.count(user.type)==0 && role[*it].type.count("*")==0)
                continue;
            
            if(role[*it].so.count(user.so)==0 && role[*it].so_num!=0)
                continue;

            found=true;
            break;
          }
        

            // 遍历用户的所有组
            for (auto role_it = user.group.begin(); role_it != user.group.end() && !found; ++role_it) {
            vector<string> temp = relation[*role_it];

            // 遍历temp中的角色并检查权限
            for(auto it =temp.begin();it!=temp.end();++it){

                if( role[*it].op.count(user.op)==0 && role[*it].op.count("*")==0)
                    continue;

                if(role[*it].type.count(user.type)==0 && role[*it].type.count("*")==0)
                    continue;
                
                if(role[*it].so.count(user.so)==0 && role[*it].so_num!=0)
                    continue;
                    
                found=true;
                break;
                }
            }

     if(found) cout<<1<<endl;
        else cout<<0<<endl;
    
        user.group.clear();//要清空！
    }


    system("pause");
    return 0;
}