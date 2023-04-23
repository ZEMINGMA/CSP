#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> book_prices(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> book_prices[i];
    }

    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(n * x + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n * x; ++j) {
            if (j >= book_prices[i]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - book_prices[i]] + book_prices[i]);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }

    int min_cost = INF;
    for (int j = x; j <= n * x; ++j) {
        min_cost = min(min_cost, dp[n][j]);
    }

    cout << min_cost << endl;
    system("pause");
    return 0;
}
