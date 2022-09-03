// https://leetcode.com/problems/sum-of-all-subset-xor-totals/
#include <iostream>
#include <vector>

int res = 0;
std::vector<int> subset;

int calXORNums(std::vector<int>& nums)
{
    int ans = 0;
    for (int &num : nums) ans ^= num;
    return ans;
}

void dfs(std::vector<int>& nums, int pos)
{
    if (pos >= nums.size())
    {
        res += calXORNums(subset);
        return; 
    }

    dfs(nums, pos + 1);
    subset.push_back(nums[pos]);
    dfs(nums, pos + 1);
}

int util(std::vector<int>& nums, int level, int currXOR)
{
    if (level == nums.size()) return currXOR;
    int incl = util(nums, level + 1, currXOR ^ nums[level]);
    int excl = util(nums, level + 1, currXOR);
    return incl + excl;
}
int subsetXORSum(std::vector<int>& nums) {
    // Backtracking solution
    // dfs(nums, 0);
    // return res;

    // efficient way
    return util(nums, 0, 0);
}

int main()
{
    std::vector<int> nums = {1, 5, 6};
    // int n;
    // std::cin >> n;
    // for (int i = 0; i < n; i++) std::cin >> nums[i];
    int ans = subsetXORSum(nums);
    logl(ans);
}