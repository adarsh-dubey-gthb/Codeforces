#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int x = 0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if (s[1]=='+')
        {
            x++;
        }
        if(s[1]=='-'){
            x--;
        }
        
    }
    cout<<x;

    
    
    

    return 0;
}