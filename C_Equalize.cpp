#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int cost = 0;
    for (int i = 0; i < n;)
    {
        if (a[i] != b[i])
        {
            if (i + 1 < n && a[i+1] != b[i+1] && a[i] != a[i+1])
            {
                cost+=1;
                i+=2;
            } else{
                cost+=1;
                 i+=1;

            }
            
        }else{
            i+=1;
        }
        
    }
    
    cout<<cost;
    
    return 0;
}