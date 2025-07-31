#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
vector<int> parent(MAXN, -1);
vector<bool> visited(MAXN, false);
int start = -1, endNode = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (neighbor == par) continue;
        if (visited[neighbor]) {
            start = neighbor;
            endNode = node;
            return true;
        } else {
            parent[neighbor] = node;
            if (dfs(neighbor, node)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read graph
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Try DFS from every unvisited node
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endNode; v != start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(start);  // Complete the cycle

        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << '\n';
        for (int v : cycle)
            cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
