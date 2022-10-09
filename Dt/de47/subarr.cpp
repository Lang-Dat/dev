#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./subarr.INP", "r", stdin);
    freopen("./subarr.OUT", "w", stdout);

    int n, count = 0;
    std::cin >> n;
    int nums[n+1];
    nums[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
    if (nums[n] % 3 != 0) {
        std::cout << 0;
        return 0;
    }
    const int sum_of_seq = nums[n] / 3;
    std::vector<int> startSplitPoints; // incresing order
    std::vector<int> endSplitPoints;   // decresing order
    for (int start = 1, end = n; start <= n && end >= 0; start++, end--) {
        if (nums[start] == sum_of_seq) startSplitPoints.push_back(start);
        if (nums[n] - nums[end-1] == sum_of_seq) endSplitPoints.push_back(end);
    }
    for (int start : startSplitPoints) {
        for (int end : endSplitPoints) {
            if (nums[end-1] - nums[start] == sum_of_seq && end - start > 1) {
                count++;
            }
            else if (end <= start) break;
        }
    }
    std::cout << count;
    return 0;
}