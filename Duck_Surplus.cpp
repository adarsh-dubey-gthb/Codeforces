#include <iostream>
#include <vector>

using namespace std;

void process() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<long long> stack;
    
    for (int i = 0; i < n; ++i) {
        long long current_duck = a[i];
        
        while (!stack.empty() && stack.back() > current_duck) {
            long long prev_duck = stack.back();
            stack.pop_back();
            current_duck = prev_duck + current_duck;
        }
        
        stack.push_back(current_duck);
    }
    
    cout << stack.back() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            process();
        }
    }
    return 0;
}