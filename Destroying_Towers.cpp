#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    const long long INF = 1e18;
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 1, INF));
    
    for(int j=0; j<=n; j++){
        dp[n+1][j] = 0;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= i; j++) {
            long long bound = (j == 0) ? -1 : a[j];
            
            if (a[i] <= bound) {
                dp[i][j] = min(dp[i][j], a[i] + dp[i + 1][j]);
            } else {
                if (j != 0) {
                    dp[i][j] = min(dp[i][j], bound + dp[i + 1][j]);
                } else {
                    dp[i][j] = min(dp[i][j], a[i] + dp[i + 1][0]);
                }
            }
            
            long long current_height = (j != 0 && a[i] > bound) ? bound : a[i];
            dp[i][j] = min(dp[i][j], current_height + dp[i + 1][i]);
        }
    }
    cout << dp[1][0] << "\n";
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
