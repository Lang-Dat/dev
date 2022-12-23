/**
 *	author: Lang Dat
 *	create: 18-10-2022 35:22:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UOCCHUNG.INP", "r", stdin);
    freopen("./UOCCHUNG.OUT", "w", stdout);

    int n, ucln, tmp;
    std::cin >> n >> ucln;
    while (std::cin >> tmp) {
        ucln = __gcd(ucln, tmp);
    }
    std::cout << ucln;
    return 0;
}