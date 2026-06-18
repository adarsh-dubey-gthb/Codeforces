#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int current_streak = 1;
    int max_streak = 1;
    for(int i=1 ; i<n; i++){
        if(a[i]>=a[i-1]){
            current_streak++;
        }
        else{
            current_streak =1;
        }
        max_streak = max(max_streak, current_streak);
    }
    cout<<max_streak<<endl;
    return 0;
}