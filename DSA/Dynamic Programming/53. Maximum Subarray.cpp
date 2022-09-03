// https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>

// native solution
// time: O(n^2)
int maxSubArray(std::vector<int>& nums) {
    int max = INT32_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int currMax = INT32_MIN, sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum > currMax) currMax = sum;
        }
        if (currMax > max) max = currMax;
    }

    return max;
}

// efficient solution
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
    // freopen("big input.txt", "r", stdin);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) std::cin >> nums[i];

    std::cout << (maxSubArray2(nums));
}