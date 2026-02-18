#include <bits/stdc++.h>
using namespace std;

bool islucky(long long x) {
    if (x == 0) return false;
    while (x > 0) {
        int d = x % 10;
        if (d != 4 && d != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    long long count = 0;
    for (char c : s) {
        if (c == '4' || c == '7') {
            count++;
        }
    }

    if (islucky(count)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
