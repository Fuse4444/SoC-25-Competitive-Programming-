#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll get_min_h(ll a, ll b, ll n) {
    if (n == 1) return 1;
    return (n - 2) * (a - b) + a + 1;
}

ll get_max_h(ll a, ll b, ll n) {
    if (n == 1) return a;
    return (n - 1) * (a - b) + a;
}

ll days_to_climb(ll h, ll a, ll b) {
    if (h <= a) return 1;
    ll d = (h - a + (a - b - 1)) / (a - b); // ceil((h - a) / (a - b))
    return d + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;
        ll low = 1, high = 1e18;
        vector<int> result;

        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                ll a, b, n;
                cin >> a >> b >> n;

                ll new_low = get_min_h(a, b, n);
                ll new_high = get_max_h(a, b, n);

                if (new_high < low || new_low > high) {
                    result.push_back(0);
                } else {
                    low = max(low, new_low);
                    high = min(high, new_high);
                    result.push_back(1);
                }

            } else if (type == 2) {
                ll a, b;
                cin >> a >> b;

                if (low != high) {
                    result.push_back(-1);
                } else {
                    result.push_back(days_to_climb(low, a, b));
                }
            }
        }

        for (int x : result) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
