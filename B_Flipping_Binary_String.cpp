#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n; 
  cin >> n;
  string s;
  cin >> s;
  
  int one = 0, zero = 0;
  for(char c : s){
    if(c == '1') {
        one++;
    }
    else zero++;
  }
  
  if(one % 2 == 0){
    cout << one << "\n";
    for (int i = 0; i < n; i++) {
        if(s[i] == '1'){
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
  }
  else if (zero % 2 != 0) {
    cout << zero << "\n";
    for (int i = 0; i < n; i++) {
        if(s[i] == '0'){
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
  }
  else {
    cout << -1 << "\n";
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}