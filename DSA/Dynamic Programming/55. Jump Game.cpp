// https://leetcode.com/problems/jump-game/
#include <iostream>
#include <vector>

// native solution
// time: O(n^2)
bool nativeCanJumpSolution(std::vector<int>& nums, std::vector<bool> &dp, int pos = 0) {
    if (pos == nums.size() - 1) return true;
    if (nums[pos] == 0 || dp[pos] == false) return false;

    for (int i = nums[pos]; i > 0 && pos + i < nums.size(); i--)
        if (nativeCanJumpSolution(nums, dp, pos + i)) return true;
        else dp[pos+i] = false;

    return false;
}

// Greedy solution
// time: O(n)
bool canJump(std::vector<int> &nums) {
    int goal = nums.size();

    for (int i = nums.size() - 1; i >= 0; i--)
        if (i + nums[i] >= goal)
            goal = i;

    return (goal == 0) ? true : false;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) std::cin >> nums[i];
    std::vector<bool> dp = std::vector<bool>(n, true);

    std::cout << (canJump(nums));
}