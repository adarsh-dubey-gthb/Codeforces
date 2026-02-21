#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    long long n, h, k;
    cin >> n >> h >> k;
    
    vector<long long> a(n);
    long long S = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S += a[i];
    }
    long long rem = h % S;
    if (rem == 0) {
        rem = S; 
    }
    
    long long C = (h - rem) / S;
    vector<long long> suf_max(n);
    suf_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf_max[i] = max(suf_max[i + 1], a[i]);
    }
    long long pref_sum = 0;
    long long pref_min = 2e18; 
    long long best_idx = n;    

    for (int i = 0; i < n; i++) {
        pref_sum += a[i];
        pref_min = min(pref_min, a[i]);

        long long max_possible_sum = pref_sum;
                if (i < n - 1) {
            long long gain_from_swap = suf_max[i + 1] - pref_min;
            if (gain_from_swap > 0) {
                max_possible_sum += gain_from_swap;
            }
        }
        if (max_possible_sum >= rem) {
            best_idx = i + 1; 
            break;
        }
    }

    long long ans = C * (n + k) + best_idx;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}