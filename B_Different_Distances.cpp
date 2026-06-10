#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) cout << i << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        for (int i = n; i >= 1; i--) cout << i << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
    } 
    else {
        int m = (n + 1) / 2;
        
        for (int i = 1; i <= n; i++) cout << i << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        
        for (int i = n; i >= 1; i--) {
            if (i == m) {
                cout << m - 1 << " ";
            } else if (i == m - 1) {
                cout << m << " ";
            } else {
                cout << i << " ";
            }
        }
        
        for (int i = 1; i <= n; i++) cout << i << " ";
    }
    cout << "\n";
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