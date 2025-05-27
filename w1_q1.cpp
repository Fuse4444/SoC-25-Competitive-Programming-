#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int s = 0;  
    int t = 0;
    for (int i = 0; i < (n-1); i++) {
        cin >> t;
        s += t;
    }
    cout << n * (n + 1) / 2 - s << endl;
    return 0;
}
