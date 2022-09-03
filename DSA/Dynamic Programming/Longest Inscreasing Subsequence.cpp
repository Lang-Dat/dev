#include <iostream>

#define log(x) std::cout << x << " ";
#define logl(x) std::cout << x << std::endl;

int findMax(int ans[], int n, int nums[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < nums[n] && max < ans[i])
            max = ans[i];

    }
    return max;
}

int LIS(int nums[], int n)
{
    int ans[n];
    ans[0] = 1;

    for (int i = 0; i < n; i++)   
        ans[i] = 1 + findMax(ans, i, nums);

    int max = 1;
    for (int i : ans)
        if (i > max) max = i;
    
    return max;
}

int main()
{
    // int nums[10] = {0, 5, 3, 4, 9, 2, 6, 8, 7, 10}; // 6

    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) std::cin >> nums[i];

    logl(LIS(nums, n));
}