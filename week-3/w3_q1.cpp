#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long n;
    cin >> n;

    vector<pair<long, long>> task(n);
    vector<long> r1(n);
    vector<long> r2(n);

    for (long i = 0; i < n; i++) {
        cin >> task[i].first >> task[i].second;
        r1[i] = task[i].first;
        r2[i] = task[i].second;
    }

    sort(r1.begin(), r1.end()); 
    sort(r2.begin(), r2.end());

    long s1 = 0, s2 = 0;
    for (long i = 0; i < n; i++) {
        s1 += (n - i) * r1[i];
        s2 += r2[i];
    }
    cout << s2 - s1;

    return 0;
}
