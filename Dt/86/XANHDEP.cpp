#include <iostream>
#include <algorithm>

int solve(std::string &str) {
    // tim do dai day con dai nhat co cac phan tu bang nhau
    int best = 1;
    for (int i = 1, count = 1; i < str.size(); i++) {
        (str[i] == str[i - 1]) ? count++ : count = 1;
        best = std::max(best, count);
    }

    return best;
}

int main() {
    freopen("XANHDEP.INP", "r", stdin);
    freopen("XANHDEP.OUT", "w", stdout);

    int n, best = 0;
    std::string str;
    std::cin >> n;
    while (std::cin >> str) {
        best = std::max(best, solve(str));
    }

    std::cout << best;
}
