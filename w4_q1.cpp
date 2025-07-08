#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD - 1;  // Euler's theorem reduction for exponent

// Fast modular exponentiation
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        // Handle 0^0^0 = 1
        if (a == 0 && b == 0 && c == 0) {
            cout << 0 << '\n';
            continue;
        }

        // First compute b^c % (MOD - 1)
        ll exponent = mod_pow(b, c, MOD2);

        // Then compute a^exponent % MOD
        ll result = mod_pow(a, exponent, MOD);
        cout << result << '\n';
    }

    return 0;
}
