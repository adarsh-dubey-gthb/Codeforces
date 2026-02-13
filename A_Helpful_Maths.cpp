#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    
    cin>>s;
    vector<int>nums;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '+')
        {
            nums.push_back(s[i]-'0');
        }
        
    }
    sort(nums.begin(), nums.end());
    for (int j = 0; j <nums.size() ; j++)
    {
        cout<<nums[j];
        if (j != nums.size()-1)
        {
            cout<<'+';
        }
        
    }
    return 0;
    
    
}