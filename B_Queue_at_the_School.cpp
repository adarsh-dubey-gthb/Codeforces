#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(v) v.begin(), v.end()

void solve() {
    int n , t;
    cin >> n >> t;
    string s;
    cin >> s;
    while(t--){
        for ( int i = 0; i < n-1; i++)
        {
            if (s[i]=='B' && s[i+1] == 'G' )
            {
                swap(s[i],s[i+1]);
                i++;
            }
            
        }
        
    }
    cout<<s<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}