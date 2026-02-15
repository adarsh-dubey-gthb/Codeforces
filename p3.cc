#include <iostream>
#include <vector>

int main() {
    int n, k;
    if (!(std::cin >> n >> k)) return 0;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int kth_score = a[k-1];
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] >= kth_score && a[i] > 0) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
