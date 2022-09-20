#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int lengthOfLIS(vector<int>& nums, int k) {
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i] && nums[j] + k >= nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;

    return *std::max_element(dp.begin(), dp.end());                
}

int main() {
    vector<int> nums = {4,2,1,4,3,4,5,8,15};
    log(lengthOfLIS(nums, 3));
}