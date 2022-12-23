/**
 *	author: Lăng Trọng Đạt
 *	create: 23-11-2022 52:05:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

static const int LIM = 5*1e5 + 5;
ull sums[LIM];

int use_binary_search(int n, int s) {
    // Time complex: O(nLogn)
    int ans = INT32_MAX;
    for (int i = 0; i <= n; i++) {
        int ind = lower_bound(sums + i + 1, sums + n + 1, sums[i] + s) - sums;
        if (ind != n + 1)
            ans = min(ind - i, ans);
    }
    return ans;
}
int use_two_poiter(int n, int s) {
    // Time complex: O(n)
    int ans = INT32_MAX;
    for (int l = 0, r = 0, curr = 0; r < n; r++) {
        while (sums[r] - sums[l+1] >= s && l < r) {
            l++;
        }
        if (sums[r] - sums[l] >= s)
        ans = min(r - l, ans);
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SUB.INP", "r", stdin);
    freopen("./SUB.OUT", "w", stdout);
    #endif

    int n, s, ans = INT32_MAX;
    std::cin >> n >> s;
    sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> sums[i];
        sums[i] += sums[i-1];
    }
    ans = use_two_poiter(n, s);
    std::cout << ans << "";
    return 0;
}