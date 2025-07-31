#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
int N;
ll K;

// Matrix multiplication: C = A * B
vector<vector<int>> mat_mult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            if (A[i][k])
                for (int j = 0; j < N; ++j)
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j] % MOD) % MOD;
    return C;
}

// Matrix exponentiation: res = A^power
vector<vector<int>> mat_pow(vector<vector<int>> A, ll power) {
    vector<vector<int>> res(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        res[i][i] = 1;  // Identity matrix

    while (power > 0) {
        if (power % 2 == 1)
            res = mat_mult(res, A);
        A = mat_mult(A, A);
        power /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];

    vector<vector<int>> result = mat_pow(A, K);

    int total_paths = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            total_paths = (total_paths + result[i][j]) % MOD;

    cout << total_paths << '\n';
    return 0;
}
