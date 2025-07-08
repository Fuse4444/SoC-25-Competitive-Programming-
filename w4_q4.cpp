#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX = 2e6 + 5;  // To handle up to n + m
const ll MOD = 1e9 + 7;

vector<ll> fact(MAX), inv_fact(MAX);

// Fast exponentiation (a^b % MOD)
ll mod_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

// Compute nCr modulo MOD
ll binomial(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;
    precompute();
    cout << binomial(n + m - 1, m) << '\n';
    return 0;
}
