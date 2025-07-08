#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

// Function to compute (a * b) % MOD
ll modmul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Function to compute sum of divisors using inverse formula
ll sigma_sum(ll n) {
    ll res = 0;
    for (ll i = 1; i <= n;) {
        ll q = n / i;
        ll next_i = n / q + 1;
        ll cnt = next_i - i;
        ll sum_i = (i + next_i - 1) % MOD;
        ll temp = modmul(cnt % MOD, sum_i);
        temp = modmul(temp, ((MOD + 1) / 2)); // divide by 2 under MOD
        res = (res + modmul(q % MOD, temp)) % MOD;
        i = next_i;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    cout << sigma_sum(n) << endl;
    return 0;
}
