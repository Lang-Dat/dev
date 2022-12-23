/**
 *	author: Lang Dat
 *	create: 26-10-2022 49:17:09
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UOCSO.INP", "r", stdin);
    freopen("./UOCSO.OUT", "w", stdout);

    ull n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << n / 2 << "";
    } else if (n % 3 == 0) {
        std::cout << n / 3 << "";
    } else {
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0) {
                std::cout << n / i << "";
                return 0;
            } else if (n % (i + 2) == 0) {
                std::cout << n / (i + 2) << "";
                return 0;
            }
        }
        std::cout << -1 << "";
    }

    return 0;
}