/**
 *	author: Lăng Trọng Đạt
 *	create: 05-12-2022 13:55:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 5*1e5 + 5;
int nums[LIM];
int n, k;

bool check(int length) {
    // TC: O(n)
    int count = 0;
    for (int i = 0; nums[i] >= k && count < k; i++)
        count += nums[i] / length;
    return count >= k;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CATTHEP.INP", "r", stdin);
    freopen("./CATTHEP.OUT", "w", stdout);
    #endif

    std::cin >> n >> k;
    int maxLength = 0;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        maxLength = max(maxLength, nums[i]);
    }
    sort(nums, nums + n, greater<int>());
    int l = 1, r = maxLength;
    while (l <= r) { // O(log2(maxLength))
        int mid = (l + r) / 2;
        if (check(mid)) {
            maxLength = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    std::cout << maxLength << "";
    return 0;
}