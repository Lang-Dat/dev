/**
 *	author: Lang Dat
 *	create: 23-10-2022 54:11:07
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./POW.INP", "r", stdin);
    freopen("./POW.OUT", "w", stdout);

    ull l, r, base, x = 1;
    bool isPrint = false;
    std::cin >> l >> r >> base;
    
    while (x <= r) {
        if (x >= l) {
            std::cout << x << " ";
            isPrint = true;
        }
        x *= base;
    }
    if (!isPrint) {
        std::cout << "-1";
    }
    return 0;
}