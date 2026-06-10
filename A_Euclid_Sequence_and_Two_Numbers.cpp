#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> b, long long x, long long y) {
    multiset<long long> s(b.begin(), b.end());
    vector<long long> seq;
    seq.push_back(x);
    seq.push_back(y);
    s.erase(s.find(x));
    s.erase(s.find(y));
    while (!s.empty()) {
        long long nxt = seq[seq.size()-2] % seq.back();
        if (s.find(nxt) == s.end()) return false;
        seq.push_back(nxt);
        s.erase(s.find(nxt));
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(b.begin(), b.end());
        long long x = b[n-1], y = b[n-2];
        if (check(b, x, y)) {
            cout << x << " " << y << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
