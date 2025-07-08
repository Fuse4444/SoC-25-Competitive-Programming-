#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

// Modular exponentiation
ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while (exp) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Modular inverse
ll mod_inv(ll x) {
    return mod_pow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> factors(n);
    ll num_divisors = 1;
    ll sum_divisors = 1;
    ll prod_divisors = 1;
    ll total_divisors = 1;

    // To handle exponentiation correctly in product
    vector<pair<ll, ll>> factor_exp(n);

    for (int i = 0; i < n; ++i) {
        ll p, k;
        cin >> p >> k;
        factors[i] = {p, k};

        // Number of divisors
        num_divisors = num_divisors * (k + 1) % MOD;

        // Sum of divisors: (p^{k+1} - 1) / (p - 1)
        ll numerator = (mod_pow(p, k + 1) - 1 + MOD) % MOD;
        ll denominator = mod_inv(p - 1);
        sum_divisors = sum_divisors * numerator % MOD * denominator % MOD;
    }

    // For product of divisors
    // We calculate exponent of N^{D(N)/2}
    // We break this into safe steps since D(N) can be huge
    ll exp = 1;
    for (auto [p, k] : factors) {
        // current power = k
        // total_divisors = product of (ki + 1)
        // So exponent of p = k * (total_divisors / (k + 1))
        ll temp = total_divisors;
        total_divisors = total_divisors * (k + 1) % (MOD - 1); // Euler's theorem mod
    }

    // Now compute the product of divisors using:
    // prod = product of p_i^{k_i * total_divisors/2}
    // We build the product gradually:
    ll D_half = total_divisors;
    if (D_half % 2 == 0) {
        D_half /= 2;
    } else {
        D_half = D_half * mod_inv(2) % (MOD - 1);
    }

    for (auto [p, k] : factors) {
        ll exp = k * D_half % (MOD - 1);
        prod_divisors = prod_divisors * mod_pow(p, exp) % MOD;
    }

    cout << num_divisors << " " << sum_divisors << " " << prod_divisors << "\n";
    return 0;
}
