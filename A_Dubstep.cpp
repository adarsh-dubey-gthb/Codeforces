#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    if(cin >> s){
    bool isSpace = true;
    for (int i = 0; i < s.length();)
    {
        if (i <= s.length()-3 && s[i]=='W' && s[i+1] == 'U' && s[i+2] == 'B')
        {
            i+=3;
            if (!isSpace)
            {
                cout<<" ";
                isSpace = 'true';
            }
        } else {
            cout << s[i];
            isSpace = false;
            i++;

        }
        
    }
    cout<< "\n";
    
}
return 0;

}




