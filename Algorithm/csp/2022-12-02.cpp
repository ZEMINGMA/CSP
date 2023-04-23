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

    // �������翪ʼʱ��
    vector<int> earliest_start(m);
    for (int i = 0; i < m; i++) {
        if (dependencies[i] == 0) {
            earliest_start[i] = 1;
        } else {
            earliest_start[i] = earliest_start[dependencies[i] - 1] + training_days[dependencies[i] - 1];
        }
    }

    // ������翪ʼʱ��
    for (int i = 0; i < m; i++) {
        cout << earliest_start[i] << (i == m - 1 ? '\n' : ' ');
    }

    // ��������ʼʱ��
    vector<int> latest_start(m, n + 1);
    for (int i = m - 1; i >= 0; i--) {
        if (dependencies[i] != 0) {
            latest_start[dependencies[i] - 1] = min(latest_start[dependencies[i] - 1], latest_start[i] - training_days[i]);
        }
    }

    // �ж��Ƿ����� n �������ȫ����Ŀ��ѵ��
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
