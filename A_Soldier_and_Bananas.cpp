#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,k,w;
    cin>>k>>n>>w;
    int price;
    price = k * w * (w + 1) / 2;
    int borrow;
    borrow = price - n;
    cout << max(0, price - n);



}