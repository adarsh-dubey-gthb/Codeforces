#include <bits/stdc++.h>
using namespace std;


int get_odd(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        
        if (get_odd(a[i]) != get_odd(i)) {
            possible = false;
        }
    }

    cout << (possible ? "YES\n" : "NO\n");
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