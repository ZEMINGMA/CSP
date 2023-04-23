#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 计算字符串的所有非空子串的分值和
long long total_substring_scores(const string &s) {
    long long total_score = 0;
    int n = s.length();
    vector<int> last_occurrence(26, -1); // 上一次每个字符出现的位置
    vector<int> dp(26, 0);               // dp[i] 表示以字符 i+'a' 结尾的子串的分值和

    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';

        // 计算 dp[c]
        int contribution = i - last_occurrence[c];
        dp[c] += contribution;

        // 更新总分值和和字符的上一次出现位置
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
