#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    for (long long i = 0; i < n; ++i) {
        long long A, B;
        cin >> A >> B;

        // Condition:
        // Equation 2x + B*y = A has a non-negative integer solution
        // if and only if A is even OR B is odd
        if (A % 2 == 0 || B % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
