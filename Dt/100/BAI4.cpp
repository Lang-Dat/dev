/**
 *	author: Lang Dat
 *	create: 18-11-2022 42:14:19
**/
#include <iostream>
using namespace std;

int solve(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2*solve(n/2) + 1;
    else return 3*solve(n/2) + 1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    std::cout << solve(n) << "";
    return 0;
}