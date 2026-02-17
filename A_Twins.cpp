#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end(), greater<int>()); 

    int half = sum / 2;
    int count = 0;
    int coins = 0;

    for (int j = 0; j < n; j++) {
        count += a[j];
        coins++;
        if (count > half) {
            cout << coins << endl;
            break;
        }
    }

    return 0;
}
