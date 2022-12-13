/**
 *	author: Lăng Trọng Đạt
 *	create: 13-12-2022 05:11:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

int nums[21];
int n, target;

bool solve(int pos = 0, int curr = 0) {
    if (curr == target) return true;
    else if (pos == n or curr > target)
        return false;
    for (int i = 0; nums[pos] * i + curr <= target; i++) {
        if (solve(pos + 1, curr + nums[pos] * i)) 
            return true;
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./ExpSum.INP", "r", stdin);
    freopen("./ExpSum.OUT", "w", stdout);
    #endif

    int T;
    std::cin >> T;
    while (std::cin >> n >> target) {
        for (int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }
        cout << solve() << "\n";
    }

    return 0;
}