/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    // static const int LIM = 20 * 100 + 10;
    // int dp[205][LIM];
    // int sum;

    // bool build(std::vector<int> &nums, int pos, int curr_sum) {
    //     if (curr_sum > sum || pos == nums.size()) return false;
    //     if (curr_sum == sum || dp[pos][curr_sum] == 1) return true;
    //     if (dp[pos][curr_sum] == 2) return false;
    //     bool res = build(nums, pos + 1, curr_sum + nums[pos]) || 
    //                build(nums, pos + 1, curr_sum);
    //     return dp[pos][curr_sum] = res ? 1 : 2;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum /= 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        dp[0][0] = true;
        // build(nums, 0, 0);
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < sum + 1; j++)
                dp[i][j] = dp[i-1][j] || 
                           ((j >= nums[i]) ? dp[i-1][j - nums[i]] : 0);
        return dp[nums.size() - 1][sum];
        // for(int i = 1; i < nums.size(); i++)
        //     for(int j = 0; j < sum / 2 + 1; j++)
        //         dp[i][j] = dp[i - 1][j] || ((j >= nums[i]) ? dp[i - 1][j - nums[i]] : 0);
        // return dp[nums.size() - 1][sum / 2];
    }
};
// @lc code=end

int main() {
    std::vector<int> nums = {1, 5, 11, 5};
    Solution ob;
    std::cout << ob.canPartition(nums) << "";
}