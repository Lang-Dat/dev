#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;

    return *std::max_element(dp.begin(), dp.end());                
}

int main() {
    vector<int> nums = {0, 0, 0};
    log(lengthOfLIS(nums));
}