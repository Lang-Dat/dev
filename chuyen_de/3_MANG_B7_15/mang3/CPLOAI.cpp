/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 01:54:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1005;
static bool freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CPLOAI.INP", "r", stdin);
    freopen("./CPLOAI.OUT", "w", stdout);
    #endif

    int n, tmp, count = 0;

    std::cin >> n;
    while (std::cin >> tmp) {
        count += freq[tmp] == false;
        freq[tmp] = true;
    }

    std::cout << count << "\n";

    for (int i = 1; i < LIM; i++)
        if (freq[i])
            std::cout << i << " ";

    return 0;
}