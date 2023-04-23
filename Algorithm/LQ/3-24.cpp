#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �����ַ��������зǿ��Ӵ��ķ�ֵ��
long long total_substring_scores(const string &s) {
    long long total_score = 0;
    int n = s.length();
    vector<int> last_occurrence(26, -1); // ��һ��ÿ���ַ����ֵ�λ��
    vector<int> dp(26, 0);               // dp[i] ��ʾ���ַ� i+'a' ��β���Ӵ��ķ�ֵ��

    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';

        // ���� dp[c]
        int contribution = i - last_occurrence[c];
        dp[c] += contribution;

        // �����ܷ�ֵ�ͺ��ַ�����һ�γ���λ��
        total_score += contribution;
        last_occurrence[c] = i;
    }

    return total_score;
}

int main() {
    string s;
    cin >> s;
    long long total_score = total_substring_scores(s);
    cout << total_score << endl;
    system("pause");
    return 0;
}
