#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=405;

int n,m,q;

typedef struct Role{
    int op_num;
    string op[N];
    int type_num;
    string type[N];
    int so_num;
    string  so[N];
}Role;

typedef struct User{
    string name;
    int group_num;
    string group[N];
    string op;
    string type;
    string so;
}User;
User user;

unordered_map<string,Role> role;
unordered_map<string,vector<string>> relation;

int main()
{
    cin>>n>>m>>q;

    for(int i=1;i<=n;++i){
        string name;
        cin>>name;

        cin>>role[name].op_num;
        for(int j=1;j<=role[name].op_num;++j)
            cin>>role[name].op[j];
        
        cin>>role[name].type_num;
        for(int j=1;j<=role[name].type_num;++j)
            cin>>role[name].type[j];
        
        cin>>role[name].so_num;
        for(int j=1;j<=role[name].so_num;++j)
            cin>>role[name].so[j];
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
            cin>>user.group[j];
        }
        cin>>user.op;
        cin>>user.type;
        cin>>user.so;

        vector<string> temp=relation[user.name];
        bool found=false;
        for(auto it =temp.begin();it!=temp.end();++it){
            auto res_1 = find(role[*it].op + 1, role[*it].op + role[*it].op_num + 1, user.op);
            auto res_1_1 = find(role[*it].op + 1, role[*it].op + role[*it].op_num + 1, "*");
            auto res_2 = find(role[*it].type + 1, role[*it].type + role[*it].type_num + 1, user.type);
            auto res_2_2 = find(role[*it].type + 1, role[*it].type + role[*it].type_num + 1, "*");
            auto res_3 = find(role[*it].so + 1, role[*it].so + role[*it].so_num + 1, user.so);
            if (   (res_1 != (role[*it].op + role[*it].op_num + 1) || res_1_1 != (role[*it].op + role[*it].op_num + 1)  )
                && (res_2 != (role[*it].type + role[*it].type_num + 1) || res_2_2 != (role[*it].type + role[*it].type_num + 1))
                && (res_3 != (role[*it].so + role[*it].so_num + 1 )|| role[*it].so_num==0)  
                ){
            found=true;
            break;
          }
        }

        // 遍历用户的所有组
        for (int j = 1; j <= user.group_num && !found; ++j) {
        vector<string> temp = relation[user.group[j]];

        // 遍历temp中的角色并检查权限
        for(auto it =temp.begin();it!=temp.end();++it){
            auto res_1 = find(role[*it].op + 1, role[*it].op + role[*it].op_num + 1, user.op);
            auto res_1_1 = find(role[*it].op + 1, role[*it].op + role[*it].op_num + 1, "*");
            auto res_2 = find(role[*it].type + 1, role[*it].type + role[*it].type_num + 1, user.type);
            auto res_2_2 = find(role[*it].type + 1, role[*it].type + role[*it].type_num + 1, "*");
            auto res_3 = find(role[*it].so + 1, role[*it].so + role[*it].so_num + 1, user.so);
            if (   (res_1 != (role[*it].op + role[*it].op_num + 1) || res_1_1 != (role[*it].op + role[*it].op_num + 1)  )
                && (res_2 != (role[*it].type + role[*it].type_num + 1) || res_2_2 != (role[*it].type + role[*it].type_num + 1))
                && (res_3 != (role[*it].so + role[*it].so_num + 1 )|| role[*it].so_num==0)  
                ){
            found=true;
            break;
          }
        }
    }

     if(found) cout<<1<<endl;
        else cout<<0<<endl;
    }


    system("pause");
    return 0;
}