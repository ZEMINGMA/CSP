#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double i;
    cin >> n >> i;

    vector<int> cashflows(n + 1);
    for (int k = 0; k <= n; k++) {
        cin >> cashflows[k];
    }

    double total_present_value = 0;
    for (int k = 0; k <= n; k++) {
        total_present_value += cashflows[k] * pow(1 + i, -k);
    }

    cout <<fixed<<  setprecision(3) << total_present_value << endl;
    system("pause");
    return 0;
}
