#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll luckiness(ll num) {
    ll min_d = 9, max_d = 0;
    while (num > 0) {
        ll d = num % 10;
        min_d = min(min_d, d);
        max_d = max(max_d, d);
        num /= 10;
    }
    return max_d - min_d;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
// the max luckiness will always appear within the interval of 100 from the min in the range 
    ll t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll best = l;
        ll best_luck = luckiness(l);
        for (ll i = l + 1; i <= r && i <= l + 100; ++i) {
            ll current_luck = luckiness(i);
            if (current_luck > best_luck) {
                best_luck = current_luck;
                best = i;
                if (best_luck == 9) break;
            }
        }

        cout << best << '\n';
    }
    return 0;
}
