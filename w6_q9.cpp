#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> tree[MAXN];
int in_time[MAXN], subtree_size[MAXN];
vector<int> flat_tree;
int timer = 0;

void dfs(int u) {
    in_time[u] = timer++;
    flat_tree.push_back(u);
    subtree_size[u] = 1;
    sort(tree[u].begin(), tree[u].end()); // visit children in increasing index order
    for (int v : tree[u]) {
        dfs(v);
        subtree_size[u] += subtree_size[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Reading parent relationships and building the tree
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    // Preprocess DFS
    dfs(1);

    // Answer queries
    while (q--) {
        int u, k;
        cin >> u >> k;
        if (subtree_size[u] < k) {
            cout << -1 << '\n';
        } else {
            cout << flat_tree[in_time[u] + k - 1] << '\n';
        }
    }

    return 0;
}
