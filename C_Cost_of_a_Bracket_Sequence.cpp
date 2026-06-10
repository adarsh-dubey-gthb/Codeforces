#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> open_pos, close_pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') open_pos.push_back(i);
        else close_pos.push_back(i);
    }

    int c_open = open_pos.size();
    int c_close = close_pos.size();

    int min_cost = n + 1; 
    string best_mask(n, '0');
    vector<bool> deleted(n, false);

   
    int start_i = max(0, k - c_close);
    int end_i = min(k, c_open);

    for (int i = start_i; i <= end_i; ++i) {
        int j = k - i; 
        fill(deleted.begin(), deleted.end(), false);
        
        for (int x = 0; x < i; ++x) deleted[open_pos[x]] = true;
        for (int x = 0; x < j; ++x) deleted[close_pos[c_close - 1 - x]] = true;

        int pairs = 0;
        int open_count = 0;
        for (int x = 0; x < n; ++x) {
            if (deleted[x]) continue;
            
            if (s[x] == '(') {
                open_count++;
            } else {
                if (open_count > 0) {
                    open_count--;
                    pairs++;
                }
            }
        }

        int cost = 2 * pairs;
        
        if (cost < min_cost) {
            min_cost = cost;
            for (int x = 0; x < n; ++x) {
                best_mask[x] = deleted[x] ? '1' : '0';
            }
        }
    }

    cout << best_mask << "\n";
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