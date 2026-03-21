#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long floor_div2(long long a) {
    return a / 2 - ((a % 2 != 0) && (a < 0));
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n, 0);
    vector<pair<long long, int>> events;
    events.reserve(n);

    for (int i = 0; i < n; i++) {
        events.clear();
        
        
        int current_active = 0;

        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                long long k_start = floor_div2(a[i] + a[j]) + 1;
                events.push_back({k_start, 1});
            } else if (a[j] < a[i]) {
                current_active++;
                long long k_inactive = floor_div2(a[i] + a[j] - 1) + 1;
                events.push_back({k_inactive, -1});
            }
        }

        sort(events.begin(), events.end());

        int max_active = current_active;
        for (size_t idx = 0; idx < events.size(); ) {
            long long current_k = events[idx].first;
            
            while (idx < events.size() && events[idx].first == current_k) {
                current_active += events[idx].second;
                idx++;
            }
            max_active = max(max_active, current_active);
        }

        ans[i] = max_active;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}