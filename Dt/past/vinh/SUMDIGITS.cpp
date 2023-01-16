/**
 *	author: Lang Dat
 *	create: 13-11-2022 14:29:18
**/
#include <iostream>
using namespace std;

int tongChuSo(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int count(int n) {
    int ans = 0;
    for (int i = 1e3; i < 1e4; i++) {
        ans += tongChuSo(i) == n;
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SUMDIGITS.INP", "r", stdin);
    freopen("./SUMDIGITS.OUT", "w", stdout);
    #endif

    int n, t;
    std::cin >> t;
    while (std::cin >> n) {
        std::cout << count(n) << "\n";
    }

    return 0;
}