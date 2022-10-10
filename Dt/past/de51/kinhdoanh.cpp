#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
// Time : O(N) :: Aux_Space : O(1)
int maxSubArray2(std::vector<int>& nums) {
    int sum = 0, max = INT32_MIN;
    for (int num : nums)
    {
        sum += num;
        if (sum > max) max = sum;
        if (sum < 0) sum = 0;
    }

    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./kinhdoang.INP", "r", stdin);
    freopen("./kinhdoang.OUT", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    
    std::cout << maxSubArray2(nums);
    return 0;
}