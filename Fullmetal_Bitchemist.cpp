#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    long long counts[3] = {0};
    counts[0] = 1;
    long long current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        int val = (s[i] == '0') ? 1 : 2;
        current_sum = (current_sum + val) % 3;
        counts[current_sum]++;
    }
    
    long long total_substrings = 1LL * n * (n + 1) / 2;
    
    long long bad_sum_substrings = 0;
    bad_sum_substrings += counts[0] * (counts[0] - 1) / 2;
    bad_sum_substrings += counts[1] * (counts[1] - 1) / 2;
    bad_sum_substrings += counts[2] * (counts[2] - 1) / 2;
    
    long long valid_sum_substrings = total_substrings - bad_sum_substrings;
    
    long long odd_alternating_stuck = 0;
    long long alt_len = 1;
    
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            alt_len++;
        } else {
            alt_len = 1;
        }
        odd_alternating_stuck += (alt_len - 1) / 2;
    }
    
    long long ans = valid_sum_substrings - odd_alternating_stuck;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            solve();
        }
    }
    return 0;
}