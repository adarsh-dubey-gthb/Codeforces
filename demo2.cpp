#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    map<int,int>m;
    for(int i = 0; i<n; i++){
        m[v[i]]++;
    }

    int sum = 0;
    for( auto j : m){
        if (j.second>1)
        {
            sum = sum+j.first;
        }
        
    }
    cout<<sum;
}