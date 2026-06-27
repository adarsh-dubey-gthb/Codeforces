#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }
    
  
    if ((double)sum / n >= 4.5) {
        cout << "0\n";
    } else {
        sort(a.begin(), a.end());
        
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == 5) {
                continue;
            } else {
                sum = sum - a[j] + 5; 
                a[j] = 5;
                count++;
            }
            
            if ((double)sum / n >= 4.5) {
                break;
            }
        }
        cout << count << "\n";
    }
    
    return 0;
}