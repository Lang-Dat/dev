#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("DEMCAP.OUT", "w", stdout);
    freopen("DEMCAP.INP", "r", stdin);

    int n;
    std::cin >> n;
    std::cout << n / 2 - !(bool)(n & 1);
}
