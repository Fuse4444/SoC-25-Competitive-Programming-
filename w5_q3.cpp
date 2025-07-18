#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<string> large_numbers;

void generate_large_numbers(string current, int length) {
    if ((int)current.size() == length) {
        large_numbers.push_back(current);
        return;
    }
    for (char d : {'5', '6', '7', '8', '9'}) {
        generate_large_numbers(current + d, length);
    }
}

bool is_valid_sum(const string& x_str) {
    int len = x_str.size();
    for (int d = 1; d <= len; ++d) {
        large_numbers.clear();
        generate_large_numbers("", d);
        for (int i = 0; i < (int)large_numbers.size(); ++i) {
            for (int j = 0; j < (int)large_numbers.size(); ++j) {
                string a = large_numbers[i];
                string b = large_numbers[j];

                // Convert to integer safely
                string sum_str;
                int carry = 0;
                for (int k = d - 1; k >= 0; --k) {
                    int da = a[k] - '0';
                    int db = b[k] - '0';
                    int total = da + db + carry;
                    sum_str += (total % 10 + '0');
                    carry = total / 10;
                }
                if (carry > 0)
                    sum_str += (carry + '0');
                reverse(sum_str.begin(), sum_str.end());

                // Remove leading zeros if any
                sum_str.erase(0, min(sum_str.find_first_not_of('0'), sum_str.size()-1));

                if (sum_str == x_str)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        cout << (is_valid_sum(x) ? "YES" : "NO") << '\n';
    }

    return 0;
}
