#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int x,y;
        cin>>x>>y;
        if (x==0 && y==0)
        {
           cout<<0<<"\n";
        }
        else{
            int distsq= x*x + y*y;
            int sqr = round(sqrt(distsq));
            if (sqr*sqr == distsq)
            {
                cout<<1<<"\n";
            }
            else{
                cout<<2<<"\n";
            }
            
        }

        
    }
 return 0;   
}