/**
 *	author: Lang Dat
 *	create: 18-11-2022 37:59:19
**/
#include <iostream>
using namespace std;

int flip(int n) {
    if (n == 1) return 3;
    else if (n == 3) return 1;
    else return 2;
}

int solve(int n) {
    if (n <= 3) return n;
    for (int i = 0;; i++) {
        if (3 * (1 << i) >= n) {
            return flip(solve(n - 3*(1 << i) / 2));
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./NUMBER.INP", "r", stdin);
    freopen("./NUMBER.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    std::cout << solve(n) << "";
    return 0;
}