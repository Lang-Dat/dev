/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 14:37:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2*1e3 + 1;
static int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CPAIR.INP", "r", stdin);
    freopen("./CPAIR.OUT", "w", stdout);
    #endif

    int n, target, tmp;
    int count = 0;
    std::cin >> n >> target;

    while (std::cin >> tmp) {
        count += freq[target - tmp];
        freq[tmp]++;
    }

    std::cout << count << "";

    return 0;
}