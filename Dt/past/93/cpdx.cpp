/**
 *	author: Lang Dat
 *	create: 07-11-2022 31:20:15
**/
#include <iostream>
#include <vector>
using namespace std;

bool isPermutation(int sq) {
    int tmp = sq, x = 0;
    while (sq > 0) {
        x = x * 10 + sq % 10;
        sq /= 10;
    }
    return x == tmp;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./cpdx.INP", "r", stdin);
    freopen("./cpdx.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    std::vector<int> ans = {0, 1, 4, 9, 121, 484, 676, 10201, 12321, 14641, 40804, 44944, 69696, 94249, 698896, 1002001};
    for (int i = ans.size() - 1; i >= 0; i--)
        if (ans[i] < n) {
            std::cout << ans[i] << "";
            return 0;
        }
    return 0;
}