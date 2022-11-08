/**
 *	author: Lang Dat
 *	create: 08-11-2022 58:43:15
**/
#include <iostream>
using namespace std;

#define ull unsigned long long
int tongChuSo(ull n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DB.INP", "r", stdin);
    freopen("./DB.OUT", "w", stdout);
    #endif

    ull t, n;
    std::cin >> t;
    while (std::cin >> n) {
        if (n == 0 || n % tongChuSo(n)) {
            std::cout << 0 << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    }

    return 0;
}