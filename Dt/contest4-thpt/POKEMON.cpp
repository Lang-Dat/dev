/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 32:53:15
**/
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int freq[129];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./POKEMON.INP", "r", stdin);
    freopen("./POKEMON.OUT", "w", stdout);
    #endif

    int n;
    string str;
    std::cin >> n >> str;
    std::unordered_set<int> types(str.begin(), str.end());

    int best = INT32_MAX;
    for (int l = 0, r = 0, count = 0; r < n; r++) {
        freq[str[r]]++;
        if (freq[str[r]] == 1)
            count++;

        while (count == types.size()) {
            best = min(r - l + 1, best);
            freq[str[l]]--;
            if (freq[str[l++]] == 0) count--;
        }
    }

    std::cout << best << "";
    return 0;
}