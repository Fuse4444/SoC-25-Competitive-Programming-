#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 7 == 0 || n % 7 == 1)
            cout << "second\n";
        else
            cout << "first\n";
    }
    return 0;
}
