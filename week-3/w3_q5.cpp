#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int main() {
    int t;
    cin >> t;

    vector<int> queries(t);
    int max_n = 0;

    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    vector<long long> dp(max_n + 1);
    dp[0] = 0; // unused
    if (max_n >= 1) dp[1] = 2;
    if (max_n >= 2) dp[2] = 8;

    for (int i = 3; i <= max_n; ++i) {
        dp[i] = (4 * dp[i - 1] % MOD - dp[i - 2] + MOD) % MOD;
    }

    for (int i = 0; i < t; ++i) {
        cout << dp[queries[i]] << '\n';
    }

    return 0;
}
