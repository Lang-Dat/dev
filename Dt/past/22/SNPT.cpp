/**
 *	author: Lăng Trọng Đạt
 *	create: 13-12-2022 35:59:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

std::vector<int> nums;
int n = 3, target = 4;

void solve(int pos, int curr) {
    if (curr == target) {
        for (int i = 0; i < n; i++)
            std::cout << nums[i] << " ";
        std::cout << "\n";
        return;
    } else if (pos == n or curr > target) {
        return;
    }

    for (int i = 1; i + curr - 1 <= target; i++) {
        nums[pos] = i;
        solve(pos + 1, curr + i - 1);
    }
    nums[pos] = 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SNPT.INP", "r", stdin);
    freopen("./SNPT.OUT", "w", stdout);
    #endif

    std::cin >> n >> target;    
    nums.resize(n, 1);

    solve(0, n);

    return 0;
}