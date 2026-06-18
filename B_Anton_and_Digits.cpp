#include<bits/stdc++.h>
using namespace std;
int main(){
    int k2,k3,k5,k6;
    cin>>k2>>k3>>k5>>k6;
    int n;
    n = min({k2,k5,k6});
    int first = n*256;

    int m;
    int k = k2-n;

    m = min (k,k3);
    int second = m*32;
    int total = first + second;
    cout<<total<<endl;
    return 0;
}