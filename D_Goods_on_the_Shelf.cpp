#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    // Count how many separated blocks each element has
    map<int, int> block_count;
    int total_blocks = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // A new block starts at index 0, or whenever the element changes
        if (i == 0 || a[i] != a[i - 1]) {
            block_count[a[i]]++;
            total_blocks++;
        }
    }

    int unique_count = block_count.size();

    // Case 1: Already perfect. Every unique item has exactly 1 block.
    if (total_blocks == unique_count) {
        cout << "YES\n";
        return;
    }

    // Case 2: Too broken. A single swap can fix a maximum of 4 extra blocks.
    if (total_blocks > unique_count + 4) {
        cout << "NO\n";
        return;
    }

    // Gather candidate indices
    vector<int> cands;
    for (int i = 0; i < n; i++) {
        // If an element type is "split" across multiple blocks
        if (block_count[a[i]] > 1) {
            // Is this specific index the boundary of a block?
            bool is_left_bound = (i == 0 || a[i] != a[i - 1]);
            bool is_right_bound = (i == n - 1 || a[i] != a[i + 1]);
            
            if (is_left_bound || is_right_bound) {
                // Add the boundary and its immediate neighbors
                if (i > 0) cands.push_back(i - 1);
                cands.push_back(i);
                if (i + 1 < n) cands.push_back(i + 1);
            }
        }
    }

    // Remove duplicate candidates to avoid checking the same swap twice
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());

    // Super-fast O(1) swap checker
    auto check_swap = [&](int x, int y) {
        if (x == y || a[x] == a[y]) return false;
        
        // A swap only changes boundaries immediately next to x and y
        vector<int> cuts = {x - 1, x, y - 1, y};
        sort(cuts.begin(), cuts.end());
        cuts.erase(unique(cuts.begin(), cuts.end()), cuts.end());
        
        // Count blocks in these spots BEFORE the swap
        int current_cut_count = 0;
        for (int i : cuts) {
            if (i >= 0 && i < n - 1 && a[i] != a[i + 1]) current_cut_count++;
        }
        
        // Perform swap
        swap(a[x], a[y]);
        
        // Count blocks in these spots AFTER the swap
        int new_cut_count = 0;
        for (int i : cuts) {
            if (i >= 0 && i < n - 1 && a[i] != a[i + 1]) new_cut_count++;
        }
        
        // Backtrack
        swap(a[x], a[y]);
        
        // Calculate the net change in total blocks
        int delta = new_cut_count - current_cut_count;
        return (total_blocks + delta) == unique_count;
    };

    // Test all combinations from our highly-targeted list
    for (int i = 0; i < cands.size(); i++) {
        for (int j = i + 1; j < cands.size(); j++) {
            if (check_swap(cands[i], cands[j])) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}