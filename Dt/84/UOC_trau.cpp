/**
 *	author: Lang Dat
 *	create: 02-11-2022 54:50:14
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

ull soUoc(ull n) {
    ull count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i * i != n) count++;
        }
    }
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UOC.INP", "r", stdin);
    freopen("./UOC_trau.OUT", "w", stdout);

    ull n, tmp, count = 0;
    std::cin >> n;
    while (std::cin >> tmp)
        count += soUoc(tmp) == 3;

    std::cout << count << "";
    return 0;
}