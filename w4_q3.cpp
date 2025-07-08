#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 5;
const ll MOD = 1e9 + 7;

vector<ll> fact(MAX), inv_fact(MAX);

// Fast exponentiation modulo MOD
ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// Compute nCr modulo MOD
ll binomial(int a, int b) {
    if (b < 0 || b > a) return 0;
    return (((fact[a] * inv_fact[b]) % MOD) * inv_fact[a - b]) % MOD;
}

int main() {
    int n;
    cin >> n;
    precompute();
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << binomial(a, b) << '\n';
    }
    return 0;
}
