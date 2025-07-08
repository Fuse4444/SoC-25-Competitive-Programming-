#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int x;
        int nim_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            nim_sum ^= x;
        }
        cout << (nim_sum ? "first\n" : "second\n");
    }

    return 0;
}
