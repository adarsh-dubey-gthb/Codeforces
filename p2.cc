#include <iostream>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;
    
    int implemented_count = 0;
    for (int i = 0; i < n; ++i) {
        int p, v, t;
        std::cin >> p >> v >> t;
        if (p + v + t >= 2) {
            implemented_count++;
        }
    }
    
    std::cout << implemented_count << std::endl;
    
    return 0;
}
