#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    vector<bool> vis(n + 1, false);
    vector<vector<int>> cycles;
    vector<int> cycle_idx(n + 1), pos_in_cycle(n + 1);

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            vector<int> cyc;
            int curr = i;
            while(!vis[curr]) {
                vis[curr] = true;
                cycle_idx[curr] = cycles.size();
                pos_in_cycle[curr] = cyc.size();
                cyc.push_back(curr);
                curr = a[curr];
            }
            cycles.push_back(cyc);
        }
    }

    int m = cycles.size();
    vector<int> target(m, -1), shift(m, -1);
    bool possible = true;

    for(int i = 1; i <= n; ++i) {
        if(b[i] != -1) {
            int u = i, v = b[i];
            int cu = cycle_idx[u], cv = cycle_idx[v];
            if(cycles[cu].size() != cycles[cv].size()) {
                possible = false;
                break;
            }
            int pu = pos_in_cycle[u], pv = pos_in_cycle[v];
            int len = cycles[cu].size();
            int cur_shift = (pv - pu + len) % len;

            if(target[cu] != -1) {
                if(target[cu] != cv || shift[cu] != cur_shift) {
                    possible = false;
                    break;
                }
            } else {
                target[cu] = cv;
                shift[cu] = cur_shift;
            }
        }
    }

    if(!possible) {
        cout << "NO\n";
        return;
    }

    vector<int> in_degree(m, 0);
    vector<bool> used(m, false);
    for(int i = 0; i < m; ++i) {
        if(target[i] != -1) {
            in_degree[target[i]]++;
            if(in_degree[target[i]] > 1) {
                possible = false;
                break;
            }
            used[target[i]] = true;
        }
    }

    if(!possible) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < m; ++i) {
        if(target[i] != -1) {
            int len = cycles[i].size();
            for(int j = 0; j < len; ++j) {
                int u = cycles[i][j];
                int v = cycles[target[i]][(j + shift[i]) % len];
                b[u] = v;
            }
        }
    }

    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> avail(n + 1);
    for(int i = 0; i < m; ++i) {
        if(!used[i]) {
            int min_val = cycles[i][0];
            for(int x : cycles[i]) min_val = min(min_val, x);
            avail[cycles[i].size()].push({min_val, i});
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(b[i] == -1) {
            int cu = cycle_idx[i];
            int len = cycles[cu].size();
            if(avail[len].empty()) {
                possible = false;
                break;
            }
            auto best = avail[len].top();
            avail[len].pop();

            int cv = best.second;
            int min_v = best.first;

            int pu = pos_in_cycle[i];
            int pv = pos_in_cycle[min_v];
            int cur_shift = (pv - pu + len) % len;

            target[cu] = cv;
            shift[cu] = cur_shift;

            for(int j = 0; j < len; ++j) {
                int u = cycles[cu][j];
                int v = cycles[cv][(j + cur_shift) % len];
                b[u] = v;
            }
        }
    }

    if(!possible) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = 1; i <= n; ++i) {
        cout << b[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}