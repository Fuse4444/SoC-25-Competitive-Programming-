#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

bool canMake(const vector<ll>& machines, ll time, ll t) {
    ll total = 0;
    for (ll k : machines) {
        total += time / k;
        if (total >= t) return true; // early exit
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;
    vector<ll> machines(n);
    for (ll i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    ll low = 1, high = 1e18, ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canMake(machines, mid, t)) {
            ans = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
