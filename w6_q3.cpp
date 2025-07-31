#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<int> graph[MAXN];
int indegree[MAXN];
int dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read edges
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    // Topological Sort using Kahn's Algorithm
    queue<int> q;
    q.push(1);
    dp[1] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            dp[neighbor] = (dp[neighbor] + dp[node]) % MOD;
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
