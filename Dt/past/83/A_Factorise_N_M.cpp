#include <iostream>

int main() {
    int t, tmp;
    std::cin >> t;
    while (std::cin >> tmp) {
        if (tmp == 2) {
            std::cout << 2 << "\n";
        } else {
            std::cout << 3 << "\n";
        }
    }
    
}