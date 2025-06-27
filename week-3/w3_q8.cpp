#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const long long INF = 1e18;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }

    // Sort b for value compression
    sort(b.begin(), b.end());

    vector<long long> prev(n), curr(n);

    // Initialize dp[0][j]
    for (int j = 0; j < n; ++j) {
        prev[j] = abs(a[0] - b[j]);
        if (j > 0)
            prev[j] = min(prev[j], prev[j - 1]);
    }

    // Fill dp[i][j]
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            curr[j] = abs(a[i] - b[j]) + prev[j];
            if (j > 0)
                curr[j] = min(curr[j], curr[j - 1]);
        }
        swap(prev, curr);
    }

    cout << prev[n - 1] << endl;
    return 0;
}
