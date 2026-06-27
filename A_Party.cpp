#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<int>emp(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>emp[i];
    }

    int maxg = 0;
    for (int i = 1; i <= n; i++)
    {
        int dept= 0;
        int curemp = i;
        while (curemp != -1)
        {
            dept++;
            curemp = emp[curemp];
        }
        maxg = max(maxg, dept);
        
    }
    cout<<maxg;
    
    return 0;
}