#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // 1-based index
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long sum = arr[i].first + arr[l].first + arr[r].first;
            if (sum == x) {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
                return 0;
            } else if (sum < x) {
                ++l;
            } else {
                --r;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
