#include <iostream>
#include <algorithm>

int main() {
        freopen("ABK1.INP", "r", stdin);
        freopen("ABK1.OUT", "w", stdout);
    int64_t a, b, k;
    std::cin >> a >> b >> k;
    int64_t l = std::max(a, b - k), r = std::min(b, a + k);
    std::cout << (r >= l ? r - l + 1 : 0);
}
