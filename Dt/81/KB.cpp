#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("KB.INP", "r", stdin);
    freopen("KB.OUT", "w", stdout);
    int64_t n, x, y, t;
    std::cin >> t;
    while (std::cin >> n >> x >> y) {
        std::cout << (y <= x ? 0 : (n - 1) * (y - x)) << "\n";
    }
}
