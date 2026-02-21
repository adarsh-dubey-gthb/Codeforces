#include<bits/stdc++.h>
using namespace std;
int main{
    queue<pair<int,int>Q;
    Q.push((1,2));
    Q.push((1,2));
    Q.push((1,2));
    Q.push((1,2));
    Q.push((1,2));
    while (!Q.empty())
    {
        pair<int,int>p;
        p=Q.front();
        cout<<p.first<<", "<<p.second<<endl;
        Q.pop();
    }
    
}