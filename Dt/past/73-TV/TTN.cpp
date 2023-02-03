/**
 *	author : Lăng Trọng Đạt
 *	creater: 02-02-2023 08:57:49
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int freq[LIM];
int n, tmp;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TTN.INP", "r", stdin);
    freopen("./TTN.OUT", "w", stdout);
    #endif

    std::cin >> n;
    while (std::cin >> tmp)
        freq[tmp]++;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += freq[i] / i;
    }

    std::cout << ans << "";

    return 0;
}