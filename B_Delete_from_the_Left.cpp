#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int i = static_cast<int>(s.size()) - 1;
    int j = static_cast<int>(t.size()) - 1;

    while (i >= 0 && j >= 0 && s[i] == t[j]) {
        --i;
        --j;
    }

    cout << (i + 1) + (j + 1);
    return 0;
}