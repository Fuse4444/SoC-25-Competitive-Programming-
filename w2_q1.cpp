#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> songs(n);
    for (int i = 0; i < n; i++) cin >> songs[i];

    // compressing the big aah numbers 
    vector<long long> unique_songs = songs;
    sort(unique_songs.begin(), unique_songs.end());
    unique_songs.erase(unique(unique_songs.begin(), unique_songs.end()), unique_songs.end());

    // new identity to each number
    for (int i = 0; i < n; i++) {
        songs[i] = (int)(lower_bound(unique_songs.begin(), unique_songs.end(), songs[i]) - unique_songs.begin());
    }

    // counting 
    vector<int> freq(unique_songs.size(), 0);

    int max_len = 0, start = 0;
    for (int end = 0; end < n; end++) {
        freq[songs[end]]++;

        while (freq[songs[end]] > 1) {
            freq[songs[start]]--;
            start++;
        }

        max_len = max(max_len, end - start + 1);
    }

    cout << max_len << '\n';

    return 0;
}
