#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i)
        cin >> r[i];

    double expected = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ra = r[i];
            int rb = r[j];
            double prob = 0.0;

            for (int x = 1; x <= ra; ++x) {
                prob += max(0, x - 1); // values in b less than x
            }

            prob /= (double)(ra * rb);
            expected += prob;
        }
    }

    cout << fixed << setprecision(6) << expected << endl;
    return 0;
}
