#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;

        long long time_noAI = (n + x + y - 1) / (x + y);

        long long lines_during_setup = z * x;
        long long time_AI;
        if (lines_during_setup >= n) {
            time_AI = z;
        } else {
            long long remaining = n - lines_during_setup;
            time_AI = z + (remaining + x + 10*y - 1) / (x + 10*y);
        }

        cout << min(time_noAI, time_AI) << "\n";
    }
    return 0;
}
