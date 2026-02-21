#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,string>>vp;
    vp.push_back({10,"abc"});
    vp.push_back({20,"def"});
    vp.push_back({20,"def"});
    vp.push_back({20,"def"});
    vp.push_back({20,"def"});
    vp.push_back({20,"def"});

    for (int i = 0; i < vp.size(); i++)
    {
        pair<int,string>p;
        p=vp[i];
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }
    
}