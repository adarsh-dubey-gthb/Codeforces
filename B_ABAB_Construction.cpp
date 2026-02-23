#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;

    int min_L[2] = {0, INF};
    int max_L[2] = {0, -INF};

    for (int i = 0; i < n; i++) {
        int n_min[2] = {INF, INF};
        int n_max[2] = {-INF, -INF};

        for (int p = 0; p < 2; p++) {
            if (min_L[p] <= max_L[p]) {
                char left_char = (p == 0) ? 'a' : 'b';
                
                if (x[i] == '?' || x[i] == left_char) {
                    n_min[1 - p] = min(n_min[1 - p], min_L[p] + 1);
                    n_max[1 - p] = max(n_max[1 - p], max_L[p] + 1);
                }

                int right_idx_parity = (n - i + p) % 2;
                char right_char = (right_idx_parity == 1) ? 'a' : 'b';
                
                if (x[i] == '?' || x[i] == right_char) {
                    n_min[p] = min(n_min[p], min_L[p]);
                    n_max[p] = max(n_max[p], max_L[p]);
                }
            }
        }
        
        min_L[0] = n_min[0]; 
        min_L[1] = n_min[1];
        max_L[0] = n_max[0]; 
        max_L[1] = n_max[1];
    }

    if (min_L[0] <= max_L[0] || min_L[1] <= max_L[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}