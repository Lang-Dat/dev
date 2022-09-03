// https://leetcode.com/problems/jump-game-ii/
#include <iostream>
#include <vector>

int canJump(std::vector<int>& nums) {
    int l = 0, r = 0, res = 0, farthest = 0;

    while (r < nums.size() - 1)
    {   
        farthest = 0;

        for (int i = l; i <= r; i++)
            if (nums[i] + i > farthest) farthest = nums[i] + i;

        l = r + 1;
        r = farthest;
        res++;
    }

    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) std::cin >> nums[i];

    std::cout << (canJump(nums));
}