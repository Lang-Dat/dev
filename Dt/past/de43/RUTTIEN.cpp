#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./RUTTIEN.INP", "r", stdin);
    freopen("./RUTTIEN.OUT", "w", stdout);

    int n, k, tmp;
    std::cin >> n >> k;

    while(std::cin >> tmp) {
        if (k >= tmp) {
            k -= tmp;
            std::cout << "1";;
        } else {
            std::cout << "0";
        }
    }

    return 0;
}