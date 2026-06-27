#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    string s, t;
    cin >> s >> t;

    vector<int> left_pos(m);
    vector<int> right_pos(m);

    int j = 0; 
    for (int i = 0; i < n && j < m; i++) {
        if (s[i] == t[j]) {
            left_pos[j] = i; 
            j++;             
        }
    }

    j = m - 1;
    for (int i = n - 1; i >= 0 && j >= 0; i--) {
        if (s[i] == t[j]) {
            right_pos[j] = i; 
            j--;              
        }
    }

    int max_gap = 0;
    for (int i = 1; i < m; i++) {
        int current_gap = right_pos[i] - left_pos[i - 1];
        max_gap = max(max_gap, current_gap);
    }

    cout << max_gap << "\n";

    return 0;
}