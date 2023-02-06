#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("MULM.OUT", "w", stdout);
    freopen("MULM.INP", "r", stdin);

    int64_t l, r;
    std::cin >> l >> r;
    if (r - l >= 2022) {
        std::cout << 0;
    } else {
        int res = 1;
        for (int64_t i = l; i <= r; i++) {
            res = (res * (i % 2022)) % 2022;
        }
        std::cout << res;
    }
}
