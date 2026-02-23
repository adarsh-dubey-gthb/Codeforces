#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        long long diff = x - 2 * y;

        if (diff >= 0 && diff % 3 == 0 && (x + 4 * y >= 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
