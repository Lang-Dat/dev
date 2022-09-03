// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400


#include <iostream>
#include <vector>

int max(int a, int b)
    {return a > b ? a : b;}

int rob(std::vector<int>& nums) {
    int rob1 = 0, rob2 = 0, temp;
    // [rob1, rob2, n, n+1, ...]
    for (auto i : nums)
    {
        temp = max(rob1 + i, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;

}

int main()
{
    std::vector<int> nums = {2,7,9,3,1}; // ans: 12
    nums.erase(nums.begin(), nums.begin() + 1);
    std::cout << nums[0];
    // int n;
    // std::cin >> n;
    // std::vector<int> nums(n);
    // for (int i = 0; i < n; i++) std::cin >> nums[i];
    // std::cout << rob(nums);

}