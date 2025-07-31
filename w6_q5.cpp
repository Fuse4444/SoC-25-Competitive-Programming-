#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> graph[MAXN];
int indegree[MAXN] = {0};
int dp[MAXN] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read edges
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }

    // Kahn's Algorithm for Topo Sort
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (dp[v] < dp[u] + 1)
                dp[v] = dp[u] + 1;
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    int longest = 0;
    for (int i = 1; i <= n; ++i)
        longest = max(longest, dp[i]);

    cout << longest << "\n";
    return 0;
}
