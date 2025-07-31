#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> graph(N + 1);

    // Reading edges
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Max-heap for BFS: pair<stamina, node>
    priority_queue<pair<int, int>> pq;

    // Distance array: -1 means unvisited
    vector<int> visited(N + 1, -1);

    // Reading guard positions
    for (int i = 0; i < K; ++i) {
        int p, h;
        cin >> p >> h;
        pq.push({h, p});
        visited[p] = h; // initialize visited with guard's stamina
    }

    // Multi-source BFS using max-heap
    while (!pq.empty()) {
        auto [stamina, node] = pq.top();
        pq.pop();

        if (stamina == 0) continue;

        for (int neighbor : graph[node]) {
            if (visited[neighbor] < stamina - 1) {
                visited[neighbor] = stamina - 1;
                pq.push({stamina - 1, neighbor});
            }
        }
    }

    // Collect all guarded vertices
    vector<int> result;
    for (int i = 1; i <= N; ++i) {
        if (visited[i] >= 0) result.push_back(i);
    }

    // Print result
    cout << result.size() << "\n";
    for (int v : result) cout << v << " ";
    cout << "\n";

    return 0;
}
