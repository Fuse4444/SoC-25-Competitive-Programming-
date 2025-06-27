#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    long long x;
    int n;
    cin >> x >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; ++i) {
        long long d;
        cin >> d;
        pq.push(d);
    }

    long long totalCost = 0;

    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();

        long long mergeCost = a + b;
        totalCost += mergeCost;

        pq.push(mergeCost);
    }

    cout << totalCost << endl;
    return 0;
}
