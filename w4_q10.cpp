#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e7 + 1;

vector<int> spf(MAX);  // Smallest prime factor

// Sieve of Eratosthenes to compute smallest prime factor for every number
void computeSPF() {
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

// Get all distinct prime factors of x
vector<int> getPrimeFactors(int x) {
    vector<int> primes;
    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);
        while (x % p == 0) x /= p;
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    computeSPF();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> d1(n, -1), d2(n, -1);

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        vector<int> primes = getPrimeFactors(x);

        if (primes.size() < 2) continue;

        // Use first prime to build d1, rest is d2
        int p1 = primes[0];
        int d = 1;
        int temp = x;
        while (temp % p1 == 0) {
            d *= p1;
            temp /= p1;
        }

        int d_1 = d;
        int d_2 = x / d_1;

        if (__gcd(d_1 + d_2, x) == 1) {
            d1[i] = d_1;
            d2[i] = d_2;
        }
    }

    for (int x : d1) cout << x << " ";
    cout << "\n";
    for (int x : d2) cout << x << " ";
    cout << "\n";

    return 0;
}
