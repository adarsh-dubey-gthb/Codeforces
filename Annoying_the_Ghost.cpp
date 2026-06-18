#include <bits/stdc++.h>
using namespace std;

long long get_swaps(vector<int>& target_positions) {
    long long total_swaps = 0;
    int size = target_positions.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (target_positions[i] > target_positions[j]) {
                total_swaps++;
            }
        }
    }
    return total_swaps;
}

void process() {
    int n;
    cin >> n;
    vector<long long> start_piles(n), end_piles(n);
    for (int i = 0; i < n; i++) cin >> start_piles[i];
    for (int i = 0; i < n; i++) cin >> end_piles[i];

    vector<long long> check_start = start_piles;
    vector<long long> check_end = end_piles;
    sort(check_start.begin(), check_start.end());
    
    for (int i = 0; i < n; i++) {
        if (check_start[i] > check_end[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> min_needed_index(n);
    for (int i = 0; i < n; i++) {
        int index = lower_bound(end_piles.begin(), end_piles.end(), start_piles[i]) - end_piles.begin();
        min_needed_index[i] = index;
    }

    vector<bool> is_taken(n, false);
    vector<int> final_destinations(n);

    for (int i = 0; i < n; i++) {
        int chosen_slot = -1;
        for (int j = min_needed_index[i]; j < n; j++) {
            if (!is_taken[j]) {
                chosen_slot = j;
                is_taken[j] = true;
                break;
            }
        }
        if (chosen_slot == -1) {
            cout << -1 << "\n";
            return;
        }
        final_destinations[i] = chosen_slot;
    }

    long long result = get_swaps(final_destinations);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            process();
        }
    }
    return 0;
}
