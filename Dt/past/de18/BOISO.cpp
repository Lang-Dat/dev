#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

bool check(ull n) {
    int tmp;
    while (n > 0) {
        tmp = n % 10;
        if (tmp != 1 && tmp != 0) return false;
        n /= 10;
    }
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BOISO.INP", "r", stdin);
    freopen("./BOISO.OUT", "w", stdout);

    ull n;
    std::cin >> n;

    for (ull i = n;; i += n)
        if (check(i)) {
            std::cout << i;
            return 0;
        }
    return 0;
}