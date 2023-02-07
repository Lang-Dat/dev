/**
 *	author : Lăng Trọng Đạt
 *	creater: 01-02-2023 10:19:22
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GcdSeg.INP", "r", stdin);
    freopen("./GcdSeg.OUT", "w", stdout);
    #endif

    int64_t a, b, m, n, ucln;
    std::cin >> a >> b >> n >> m;

    ucln = __gcd(a, b);

    std::vector<int> uc;
    for (int i = 1; i * i <= ucln; i++) {
        if (ucln % i == 0) {
            uc.push_back(i);
            uc.push_back(ucln / i);
        }
    }

    sort(uc.begin(), uc.end(), greater<int>());

    for (int i : uc)
        if (n <= i and i <= m) {
            std::cout << i << "";
            return 0;
        }

    std::cout << -1 << "";
    return 0;
}