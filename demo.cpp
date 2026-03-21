#include <bits/stdc++.h>
using namespace std;
#include<map>
int main(){
    map< string, int>directory;
    directory["Amit"]=10;
    directory["Aman"]=66;
    directory["Naman"]=77;

    for(auto i:directory){
        cout<<"Name"<<i.first;
        cout<<"phn-no"<<i.second;
        
    }
}