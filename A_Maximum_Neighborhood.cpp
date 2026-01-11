#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<1<<"\n";
        return;
    }
    long long max_cost = 0;
    for ( int r = 1; r <= n; r++)
    {
        for ( int c = 1; c <= n; c++)
        {
            long long current = (long long)(r-1)*n+c;
            long long current_total = current;

            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if (nr>=1 && nr<=n && nc>=1 && nc<=n)
                {
                    long long neb_value = (long long)(nr-1)*n+nc;
                    current_total += neb_value;
                }
                
            }
            max_cost = max(max_cost , current_total);
            
        }
    }
    cout<<max_cost<<"\n";
    
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