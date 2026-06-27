#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>h(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum+h[i];
    }
    int min_sum = sum;
    int min_index = 1;
    //slide the window
    for (int i = 1; i <= n-k ; ++i)
    {
        sum = sum - h[i-1] + h[i+k-1];
        if (sum<min_sum)
        {
            /* code */
            min_sum = sum;
            min_index = i+1;
            
        }
    }
    
    cout<<min_index<<endl;

    return 0;
    
    
    
    
}