#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ;
    cin>>t;
    while(t--){
        long long n,x,y,z;
        long long t_ai;
        cin>>n>>x>>y>>z;
        long long t_na = (n+x+y-1)/(x+y);
        if (z*x>=n)
        {
            t_ai = (n+x-1)/x;
        }
        else{
            t_ai = z+(n-(z*x)+x+10*y-1)/(x+10*y);
        }

        long long time = min(t_na , t_ai);
        cout<<time<<"\n";
         
    }
}