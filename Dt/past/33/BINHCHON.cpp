/**
 *	author: Lăng Trọng Đạt
 *	create: 22-12-2022 15:23:07
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::unordered_map<int, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BINHCHON.INP", "r", stdin);
    freopen("./BINHCHON.OUT", "w", stdout);
    #endif

    int n, m, tmp, best = 0;
    std::cin >> n >> m;
    while (std::cin >> tmp) {
        freq[tmp]++;
        best = max(best, freq[tmp]);
    }

    std::cout << best << "";
    return 0;
}