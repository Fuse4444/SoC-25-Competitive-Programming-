#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    stack<int> stk;
    vector<int> matched(n, 0);  // Marks matched brackets

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else if (!stk.empty()) {
            matched[i] = matched[stk.top()] = 1;
            stk.pop();
        }
    }

    int maxLen = 0, count = 0, curLen = 0;

    for (int i = 0; i < n; ++i) {
        if (matched[i]) {
            curLen++;
            if (curLen > maxLen) {
                maxLen = curLen;
                count = 1;
            } else if (curLen == maxLen) {
                count++;
            }
        } else {
            curLen = 0;
        }
    }

    if (maxLen == 0) cout << "0 1\n";
    else cout << maxLen << " " << count << "\n";

    return 0;
}
