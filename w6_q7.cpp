#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> tree[MAXN];

vector<int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int find_farthest_node(const vector<int>& dist) {
    int max_dist = -1, node = -1;
    for (int i = 1; i < dist.size(); ++i) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            node = i;
        }
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // First BFS to find one end of the diameter
    vector<int> d1 = bfs(1, n);
    int u = find_farthest_node(d1);

    // Second BFS from one end of the diameter
    vector<int> dist1 = bfs(u, n);
    int v = find_farthest_node(dist1);

    // Third BFS from the other end of the diameter
    vector<int> dist2 = bfs(v, n);

    // Final result
    for (int i = 1; i <= n; ++i) {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << "\n";

    return 0;
}
