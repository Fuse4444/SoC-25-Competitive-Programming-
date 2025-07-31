#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

const int MAXM = 1e5 + 5;

int n, m;
vector<vector<int>> adj;
vector<int> index, lowlink, scc_id;
stack<int> st;
vector<bool> onStack;
int idx = 0, scc_count = 0;

int var(int x) {
    return 2 * (x - 1);
}
int neg(int x) {
    return x ^ 1;
}

void add_clause(int a, int b) {
    adj[neg(a)].push_back(b);
    adj[neg(b)].push_back(a);
}

void tarjan(int u) {
    index[u] = lowlink[u] = idx++;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (index[v] == -1) {
            tarjan(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (onStack[v]) {
            lowlink[u] = min(lowlink[u], index[v]);
        }
    }

    if (lowlink[u] == index[u]) {
        int v;
        do {
            v = st.top(); st.pop();
            onStack[v] = false;
            scc_id[v] = scc_count;
        } while (v != u);
        scc_count++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(2 * m);
    index.assign(2 * m, -1);
    lowlink.assign(2 * m, -1);
    scc_id.assign(2 * m, -1);
    onStack.assign(2 * m, false);

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;

        int a = var(x1), b = var(x2);
        if (s1 == "-") a = neg(a);
        if (s2 == "-") b = neg(b);

        add_clause(a, b);  // (a ∨ b)
    }

    // Tarjan's Algorithm
    for (int i = 0; i < 2 * m; ++i) {
        if (index[i] == -1)
            tarjan(i);
    }

    // Check satisfiability
    vector<char> answer(m, '-');
    for (int i = 0; i < m; ++i) {
        if (scc_id[2 * i] == scc_id[2 * i + 1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        // If true-literal has lower SCC id, assign true
        if (scc_id[2 * i] < scc_id[2 * i + 1])
            answer[i] = '+';
    }

    for (char c : answer)
        cout << c;
    cout << '\n';

    return 0;
}
