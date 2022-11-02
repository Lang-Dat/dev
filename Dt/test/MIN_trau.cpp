/**
 *	author: Lang Dat
 *	create: 02-11-2022 43:09:10
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int count(ull n) {
    int c = 0;
    while (n > 0) {
        c += n % 10 == 5;
        n /= 10;
    }
    return c;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MIN.INP", "r", stdin);
    freopen("./MIN_trau.OUT", "w", stdout);

    ull n, k;
    std::cin >> n >> k;

    for (int i = n + 1;; i++)
        if (count(i) == k) {
            std::cout << i << "";
            return 0;
        }
    return 0;
}