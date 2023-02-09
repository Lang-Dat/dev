#include <iostream>

bool solve(int target, int start) {
    std::cout << target << " " << start << "\n";
    if (target == 0) {
        std::cout << start;
        return true;
    }
    for (int i = start; i > 0 and i < target; i--) {
        if (solve(target - i, i - 1)) {
            std::cout << i;
            return true;
        }
    }
    return false;
}

int main() {
    int t, target;
    std::cin >> t;
//    while (std::cin >> target) {
//        std::cout << (solve(target, 10) ? "-1" : "") << "n";
//    }
      solve(t, 9);
}

