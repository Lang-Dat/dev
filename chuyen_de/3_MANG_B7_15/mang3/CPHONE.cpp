/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 48:55:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1005;
static int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CPHONE.INP", "r", stdin);
    freopen("./CPHONE.OUT", "w", stdout);
    #endif

    int best = 0, n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
        best = max(best, freq[tmp]);
    }

    for (int i = 0; i < LIM; i++)
        if (freq[i] == best)
            std::cout << i << "\n";
    return 0;
}