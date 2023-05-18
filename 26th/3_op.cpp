// 引入必要的库，包括I/O流库、STL库等。
#include <bits/stdc++.h>
using namespace std;

// 定义了几个全局变量：n, m, q。
int n, m, q;

// 定义了用户关联角色的映射和用户组关联角色的映射。
unordered_map<string, vector<string> > UserMap;
unordered_map<string, vector<string> > GroupMap; 

// 定义了角色的结构，其中包括操作列表、资源种类列表和资源名称列表。
typedef struct Role {
    unordered_map<string, bool> opList;
    unordered_map<string, bool> kindList;
    unordered_map<string, bool> nameList;
}Role;

// 定义了角色的映射，键为角色名称，值为角色结构。
unordered_map<string, Role> roles;

int main()
{
    // 读入角色数n，关联数m，查询数q。
    scanf("%d%d%d", &n, &m, &q);

    // 读入n个角色的信息。
    for (int cnt = 0; cnt < n; cnt ++) {
        Role role;
        string name;
        int nv, no, nn;
        cin >> name; // 读入角色名称
        cin >> nv;  // 读入操作数
        // 读入操作列表
        for (int i = 0; i < nv; i++ ) {
            string op;
            cin >> op;
            role.opList[op] = true; // 将操作添加到操作列表中
        }
        cin >> no; // 读入资源种类数
        // 读入资源种类列表
        for (int i = 0; i < no; i++ ) {
            string kind;
            cin >> kind;
            role.kindList[kind] = true; // 将资源种类添加到资源种类列表中
        }
        cin >> nn; // 读入资源名称数
        // 读入资源名称列表
        if (nn == 0) role.nameList["*"] = true; // 若资源名称数为0，则所有资源名称都有效
        for (int i = 0; i < nn; i++ ) {
            string Sname;
            cin >> Sname;
            role.nameList[Sname] = true; // 将资源名称添加到资源名称列表中
        }
        // 将角色添加到角色映射中
        roles[name] = role;
    }

    // 读入m个关联信息
    for (int cnt = 0; cnt < m; cnt++ ) {
        string role_name;
        cin >> role_name; // 读入角色名
        int ns;     
        cin >> ns;        // 读入关联数
        // 读入关联列表
        for (int i = 0; i < ns; i++ ) {
            string type, name;
            cin >> type >> name;    // 读入关联类型和名称
            // 根据关联类型，将角色添加到对应的用户或用户组中
            if (type == "g") {
                GroupMap[name].push_back(role_name);
            }
            else {
                UserMap[name].push_back(role_name);
            }
        }
    }
    // 定义用户组列表
    vector<string> groups;
    // 读入q个查询
    for (int cnt = 0; cnt < q; cnt++ ) {
        bool flag = false;
        string name, groupName, op, kind, Sname;
        int ng;
        cin >> name >> ng; // 读入用户名和用户所在用户组数
        // 读入用户所在的用户组
        for (int i = 0; i < ng; i++ ) {
            cin >> groupName;
            groups.push_back(groupName); // 将用户组添加到用户组列表中
        }
        // 读入查询的权限信息
        cin >> op >> kind >> Sname;
        // 判断用户是否拥有查询的权限
        for (int i = 0; UserMap.count(name) && i < UserMap[name].size(); i++ ) {
            string role_name = UserMap[name][i];
            // 判断用户关联角色是否拥有查询的权限
            if (roles[role_name].opList.count("*") == 0 && roles[role_name].opList.count(op) == 0)
                continue;
            if (roles[role_name].kindList.count("*") == 0 && roles[role_name].kindList.count(kind) == 0) 
                continue;
            if (roles[role_name].nameList.count("*") == 0 && roles[role_name].nameList.count(Sname) == 0)
                continue;
            else {
                flag = true;
                break;
            }
        }

        // 判断用户所在的用户组是否拥有查询的权限
        for (int j = 0; !flag && j < groups.size(); j++ ) {
            string GroupName = groups[j];
            if (GroupMap.count(GroupName) == 0) continue;
            for (int i = 0; i < GroupMap[GroupName].size(); i++ ) {
                string role_name = GroupMap[GroupName][i];
                if (roles[role_name].opList.count("*") == 0 && roles[role_name].opList.count(op) == 0)
                    continue;
                if (roles[role_name].kindList.count("*") == 0 && roles[role_name].kindList.count(kind) == 0)
                    continue;
                if (roles[role_name].nameList.count("*") == 0 && roles[role_name].nameList.count(Sname) == 0) 
                    continue;
                else {
                    flag = true;
                    break;
                }
            }
        }
        // 输出查询结果，1表示拥有权限，0表示没有权限
        if (flag) cout << 1 << endl;
        else cout << 0 << endl;
        // 清空用户组列表，准备下一次查询
        groups.clear();
    }
    return 0; 
}
