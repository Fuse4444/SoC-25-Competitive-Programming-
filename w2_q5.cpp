#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  // for llabs (absolute value for long long)

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long median;
    if (n % 2 == 1) {
        // Odd number of elements: middle element
        median = arr[n / 2];
    } else {
        // Even number of elements: average of two middle elements (integer division)
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }

    long long sum_diff = 0;
    for (int i = 0; i < n; ++i) {
        sum_diff += llabs(arr[i] - median);
    }

    cout << sum_diff << endl;

    return 0;
}
