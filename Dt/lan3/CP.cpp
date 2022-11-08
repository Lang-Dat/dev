/**
 *	author: Lang Dat
 *	create: 08-11-2022 54:41:15
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CP.INP", "r", stdin);
    freopen("./CP.OUT", "w", stdout);
    #endif

    long long a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << -1 << "";
    } else if (a % b == 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}