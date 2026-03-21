#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
        vector<pair<int, int>> dragons(n);
    
    for (int i = 0; i < n; i++) {
        cin >> dragons[i].first >> dragons[i].second;
    }
    
    sort(dragons.begin(), dragons.end());
    
    bool can_defeat_all = true;
    
    for (int i = 0; i < n; i++) {
        if (s > dragons[i].first) {
            s += dragons[i].second; 
        } else {
            can_defeat_all = false; 
            break; 
        }
    }
    
    if (can_defeat_all) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}