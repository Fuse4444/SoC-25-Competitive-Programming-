#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        unordered_map<long long, int> dp;
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            unordered_map<long long, int> new_dp;

            for (auto& [val, cnt] : dp) {
                long long c1 = val + a[i];
                long long c2 = abs(c1);

                new_dp[c1] = (new_dp[c1] + cnt) % MOD;
                new_dp[c2] = (new_dp[c2] + cnt) % MOD;
            }

            dp = move(new_dp);
        }

        // Find max value and count
        long long max_val = 0;
        int ways = 0;

        for (auto& [val, cnt] : dp) {
            if (val > max_val) {
                max_val = val;
                ways = cnt;
            } else if (val == max_val) {
                ways = (ways + cnt) % MOD;
            }
        }

        cout << ways << '\n';
    }

    return 0;
}
