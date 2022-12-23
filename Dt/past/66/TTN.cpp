/**
 *	author: Lang Dat
 *	create: 21-10-2022 47:04:20
**/
#include <iostream>
#include <unordered_map>
using namespace std;

std::unordered_map<int, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TTN.INP", "r", stdin);
    freopen("./TTN.OUT", "w", stdout);

    int n, ans = 0, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
    }
    for (auto &p : freq) {
        ans += p.second / p.first;
    }
    std::cout << ans;
    return 0;
}