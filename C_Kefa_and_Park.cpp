#include<bits/stdc++.h>
using namespace std;
    int n,m;
    const int maxn = 100005;
    vector<int>cats(maxn);
    vector<int>adj[maxn];
    int leaves= 0;
    void dfs(int u, int parent , int cons_cats){
        if (cats[u]==1)
        {
            cons_cats++;
        }
        else{
            cons_cats =0;
        }
        if (cons_cats>m)
        {
            return;
        }
        bool isleaf = true;
        for (int v : adj[u])
        {
            if (v != parent)
            {
                isleaf = false;
                dfs( v , u, cons_cats);
            }
            
        }
        if (isleaf)
        {
            leaves++;
        }

    }
    
int main(){
     cin>>n>>m;
     for (int i = 1; i <= n; i++)
     {
        cin>>cats[i];
     }
     for (int i = 0; i < n-1; i++)
     {
        int u,v;
        cin >> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     dfs(1,0,0);
     cout<<leaves;
     return 0;
     
}