#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dependencies(m);
    for (int i = 0; i < m; i++) {
        cin >> dependencies[i];
    }

    vector<int> training_days(m);
    for (int i = 0; i < m; i++) {
        cin >> training_days[i];
    }

    // 计算最早开始时间
    vector<int> earliest_start(m);
    for (int i = 0; i < m; i++) {
        if (dependencies[i] == 0) {
            earliest_start[i] = 1;
        } else {
            earliest_start[i] = earliest_start[dependencies[i] - 1] + training_days[dependencies[i] - 1];
        }
    }

    // 输出最早开始时间
    for (int i = 0; i < m; i++) {
        cout << earliest_start[i] << (i == m - 1 ? '\n' : ' ');
    }

    // 计算最晚开始时间
    vector<int> latest_start(m, n + 1);
    for (int i = m - 1; i >= 0; i--) {
        if (dependencies[i] != 0) {
            latest_start[dependencies[i] - 1] = min(latest_start[dependencies[i] - 1], latest_start[i] - training_days[i]);
        }
    }

    // 判断是否能在 n 天内完成全部科目的训练
    bool can_finish = true;
    for (int i = 0; i < m; i++) {
        if (earliest_start[i] + training_days[i] - 1 > n) {
            can_finish = false;
            break;
        }
    }

    if (can_finish) {
        for (int i = 0; i < m; i++) {
            cout << latest_start[i] - training_days[i] + 1 << (i == m - 1 ? '\n' : ' ');
        }
    }

    
    system("pause");
    return 0;
}
