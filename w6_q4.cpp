#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
vector<bool> visited(MAXN);

void dfs(int node, const vector<int>& a) {
    visited[node] = true;
    int next = a[node];
    if (!visited[next])
        dfs(next, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1); // 1-indexed
        visited.assign(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int minDance = 0, maxDance = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int cnt = 0;
                int x = i;
                // traverse the cycle
                while (!visited[x]) {
                    visited[x] = true;
                    x = a[x];
                    cnt++;
                }
                minDance++; // 1 connected component
                if (cnt == 2) maxDance += 1;
                else maxDance += 1;
            }
        }

        cout << minDance << " " << maxDance << "\n";
    }

    return 0;
}
