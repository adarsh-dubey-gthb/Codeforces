#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>> n;
    int total_solved =0;
    for ( int i = 0; i < n; i++)
    {
        int p,v,t;
        cin >> p >> v >> t;
        if (p+v+t>=2)
        {
            total_solved++;
        }
        
    }
    cout<< total_solved <<endl;

    return 0;
}