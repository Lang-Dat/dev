/**
 *	author: Lăng Trọng Đạt
 *	create: 26-11-2022 21:31:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int freq[129];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./STRLONG.INP", "r", stdin);
    freopen("./STRLONG.OUT", "w", stdout);
    #endif

    int n, count = 0; string str;
    std::cin >> n >> str;

    for (int l = 0, r = 0; r < n; r++) {
        freq[str[r]]++;
        while (freq[str[r]] > 1) {
            freq[str[l++]]--;
            count += n - r;
        }
    }
    std::cout << count << "";
    return 0;
}