#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(v) v.begin(), v.end()

void solve() {
    string s;
    cin>>s;
    if (s.length()>10)
    {
        cout << s[0]<<s.length()-2<<s[s.length()-1]<<endl;

    }else{
        cout<<s<<endl;
    }
    
    
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