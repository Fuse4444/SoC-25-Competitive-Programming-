#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;
const int MAX_V = 100 * 1000 + 5; // max total value = 100 items * max value 1000

int main() {
    int N;
    long long W;
    cin >> N >> W;

    vector<int> weight(N), value(N);
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }

    // dp[v] = min weight to achieve value v
    vector<long long> dp(MAX_V, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int v = MAX_V - 1; v >= value[i]; --v) {
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }

    int answer = 0;
    for (int v = 0; v < MAX_V; ++v) {
        if (dp[v] <= W) {
            answer = v;
        }
    }

    cout << answer << endl;
    return 0;
}
