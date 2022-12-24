/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 03:59:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int OFF_SET = 1e5 + 5;
static const int LIM = 2e5 + 5;
static bool freq_a[LIM], freq_b[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BSET.INP", "r", stdin);
    freopen("./BSET.OUT", "w", stdout);
    #endif

    int n, m, tmp;
    std::cin >> n >> m;
    while (n-- and std::cin >> tmp)
        freq_a[tmp + OFF_SET] = true;
    while (m-- and std::cin >> tmp)
        freq_b[tmp + OFF_SET] = true;

    int hop = 0, giao = 0;
    for (int i = 0; i < LIM; i++) {
        hop += freq_a[i] | freq_b[i];
        giao += freq_a[i] & freq_b[i];
    }
    std::cout << hop << " " << giao;
    return 0;
}