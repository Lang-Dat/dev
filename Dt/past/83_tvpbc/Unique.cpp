#include <iostream>

bool solve(int target, int start) {
//    std::cout << target << " " << start << "\n";
    if (target == 0) {
//        std::cout << start;
        return true;
    }
    for (int i = start; i > 0; i--) {
        if (i <= target and solve(target - i, i - 1)) {
            std::cout << i;
            return true;
        }
    }
    return false;
}

int main() {
    freopen("UNIQUE.INP", "r", stdin);
    freopen("UNIQUE.OUT", "w", stdout);
    int t, target;
    std::cin >> t;
    while (std::cin >> target) {
        if (!solve(target, 9)) {
            std::cout << -1;
        }
        std::cout << "\n";
    }
//      solve(t, 9);
}

